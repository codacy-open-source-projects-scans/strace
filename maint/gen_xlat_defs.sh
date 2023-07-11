#! /bin/bash -eu

# Generate xlat .in file based on the existing file and Linux UAPI headers.
#
# Copyright (c) 2018-2023 The strace developers.
# All rights reserved.
#
# SPDX-License-Identifier: LGPL-2.1-or-later

warn()
{
	printf >&2 '%s: %s\n' "$0" "$*"
}

fatal()
{
	warn "$@"
	exit 1
}

usage()
{
	s="${0//?/ }"
	cat >&2 <<-EOF
		$0 -f VAL_PRINT_FMT \\
		$s -p REGEXP_PATTERN \\
		$s -d LINUX_SRC_DIR \\
		$s -c COMMON_DEFS_GLOB_PATTERN \\
		$s -a ARCH_DEFS_FILE \\
		$s < xlat/xlat_file_name.in

		Examples:
		$0 -f 'd' -p 'MADV_' -d '/path/to/linux' -c 'asm-generic/mman-common.h' -a 'asm/mman.h' < xlat/madvise_cmds.in
		$0 -f '#x' -p '_?MAP_' -d '/path/to/linux' -c 'asm-generic/mman*.h' -a 'asm/mman.h' < xlat/mmap_flags.in
		$0 -f '#o' -p '[_OF]' -d '/path/to/linux' -c 'asm-generic/fcntl.h' -a 'asm/fcntl.h' < xlat/open_mode_flags.in
		$0 -f 'u' -p 'SO_' -d '/path/to/linux' -c 'asm-generic/socket.h' -a 'asm/socket.h' < xlat/sock_options.in
	EOF
	exit 1
}

VAL_PRINT_FMT=
REGEXP_PATTERN=
COMMON_DEFS_GLOB_PATTERN=
ARCH_DEFS_FILE=
LINUX_SRC=

comment_re='[^/]*\/\*.*\*\/.*'
comment_glob='*/\**\*/*'

while [ 0 -lt "$#" ]; do
	case "$1" in
	-p)
		shift
		REGEXP_PATTERN="$1"
		;;
	-d)
		shift
		LINUX_SRC="$1"
		;;
	-c)
		shift
		COMMON_DEFS_GLOB_PATTERN="$1"
		;;
	-a)
		shift
		ARCH_DEFS_FILE="$1"
		;;
	-f)
		shift
		VAL_PRINT_FMT="$1"
		;;
	-[h?])
		usage
		;;
	-*)
		fatal "$1: unknown option"
		;;
	*)
		fatal "$1: unexpected argument"
		;;
	esac

	shift
done

for v in \
	 VAL_PRINT_FMT \
	 REGEXP_PATTERN \
	 COMMON_DEFS_GLOB_PATTERN \
	 ARCH_DEFS_FILE \
	 LINUX_SRC \
	 ; do
	eval [ -n \"\$$v\" ] || fatal "$v has not been specified"
done

printf "/* Generated by %s -f '%s' -p '%s' -c '%s' -a '%s' */\\n" \
	"$0" "$VAL_PRINT_FMT" "$REGEXP_PATTERN" \
	"$COMMON_DEFS_GLOB_PATTERN" "$ARCH_DEFS_FILE"

sed -En '/^\/\* Generated by .*\*\//d;s/^((# .*|'"$comment_re"'|'"$REGEXP_PATTERN"'[^[:space:]]*).*)?$/\2/p' |
uniq |
while read name_ rest; do
	# Empty lines, comments, and "# " directives are passed verbatim.
	case "$name_ $rest" in
		\ )
			echo
			continue ;;
		\#\ *|${comment_glob})
			printf '%s\n' "$name_ $rest"
			continue ;;
	esac
	sed -En 's/#[[:space:]]*define[[:space:]]+('"$name_"')[[:space:]]+([x[:xdigit:]]+).*$/\2\t\1/p' \
		$LINUX_SRC/include/uapi/$COMMON_DEFS_GLOB_PATTERN |
	sort -n | {
		def=
		name=
		read def name ||:

		if [ -n "$def" ]; then
			warn "$name_ is defined to $def"
		else
			warn "No def for $name_"
			name="$name_"
		fi

		grep -oEH '#[[:space:]]*define[[:space:]]+'"$name"'[[:space:]]+(0x[[:xdigit:]]+|[[:digit:]]+)' \
		    $LINUX_SRC/arch/*/include/uapi/$ARCH_DEFS_FILE |
		sed -En 's|^[^#]*/arch/([^/]+)/include/uapi/[^:]*:#[[:space:]]*define[[:space:]]+'"$name"'[[:space:]]+([^[:space:]]+)([[:space:]].*)?$|\1\t\2|p' |
		sed s/parisc/hppa/ |
		sort |
		awk -vname="$name" -vdef="$def" -vfmt="$VAL_PRINT_FMT" '
			# Like strtonum, but also supports octal and hexadecimal
			# representation.
			# Taken from https://www.gnu.org/software/gawk/manual/html_node/Strtonum-Function.html
			function mystrtonum(str,        ret, n, i, k, c)
			{
				if (str ~ /^0[0-7]*$/) {
					# octal
					n = length(str)
					ret = 0
					for (i = 1; i <= n; i++) {
						c = substr(str, i, 1)
						# index() returns 0 if c not in string,
						# includes c == "0"
						k = index("1234567", c)

						ret = ret * 8 + k
					}
				} else if (str ~ /^0[xX][[:xdigit:]]+$/) {
					# hexadecimal
					str = substr(str, 3) # lop off leading 0x
					n = length(str)
					ret = 0

					for (i = 1; i <= n; i++) {
						c = substr(str, i, 1)
						c = tolower(c)
						# index() returns 0 if c not in string,
						# includes c == "0"
						k = index("123456789abcdef", c)

						ret = ret * 16 + k
					}
				} else if (str ~ \
				    /^[-+]?([0-9]+([.][0-9]*([Ee][0-9]+)?)?|([.][0-9]+([Ee][-+]?[0-9]+)?))$/) {
					# decimal number, possibly floating point
					ret = str + 0
				} else {
					ret = "NOT-A-NUMBER"
				}

				return ret
			}

			BEGIN {
				d = mystrtonum(def)
			}

			{
				i = mystrtonum($2)
				if (i == d) next
				if (a[i])
					a[i] = a[i] " || defined __" $1 "__"
				else
					a[i] = "defined __" $1 "__"
			}

			END {
				iftext = "#if"
				for (i in a) {
					printf("%s %s\n%s\t%" fmt "\n", iftext, a[i],
					       name, i)
					iftext = "#elif"
				}

				if (iftext != "#if")
					print "#else"

				if (def == "")
					printf("%s\n", name)
				else
					printf("%s\t%" fmt "\n", name, d)

				if (iftext != "#if")
					print "#endif"
			}' |
		sed -e 's/defined __arm64__/& || defined __aarch64__/g' \
		    -e 's/defined __x86__/defined __x86_64__ || defined __i386__/g'
	}
done
