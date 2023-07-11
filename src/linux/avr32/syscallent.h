/*
 * Copyright (c) 2004-2009 Atmel Corporation
 * Copyright (c) 2009-2021 The strace developers.
 * All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

[  0] = { 0,	0,		SEN(restart_syscall),		"restart_syscall"	},
[  1] = { 1,	TP|SE,		SEN(exit),			"exit"			},
[  2] = { 0,	TP,		SEN(fork),			"fork"			},
[  3] = { 3,	TD,		SEN(read),			"read"			},
[  4] = { 3,	TD,		SEN(write),			"write"			},
[  5] = { 3,	TD|TF,		SEN(open),			"open"			},
[  6] = { 1,	TD,		SEN(close),			"close"			},
[  7] = { 1,	NF,		SEN(umask),			"umask"			},
[  8] = { 2,	TD|TF,		SEN(creat),			"creat"			},
[  9] = { 2,	TF,		SEN(link),			"link"			},
[ 10] = { 1,	TF,		SEN(unlink),			"unlink"		},
[ 11] = { 3,	CC|TF|TP|TSD|SE|SI,	SEN(execve),			"execve"		},
[ 12] = { 1,	TF,		SEN(chdir),			"chdir"			},
[ 13] = { 1,	TCL,		SEN(time),			"time"			},
[ 14] = { 3,	TF,		SEN(mknod),			"mknod"			},
[ 15] = { 2,	TF,		SEN(chmod),			"chmod"			},
[ 16] = { 3,	TF,		SEN(chown),			"chown"			},
[ 17] = { 3,	TF,		SEN(chown),			"lchown"		},
[ 18] = { 3,	TD,		SEN(lseek),			"lseek"			},
[ 19] = { 5,	TD,		SEN(llseek),			"_llseek"		},
[ 20] = { 0,	PU|NF,		SEN(getpid),			"getpid"		},
[ 21] = { 5,	TF,		SEN(mount),			"mount"			},
[ 22] = { 1,	TF,		SEN(umount2),			"umount2"		},
[ 23] = { 1,	TC,		SEN(setuid),			"setuid"		},
[ 24] = { 0,	TC|PU|NF,	SEN(getuid),			"getuid"		},
[ 25] = { 1,	0,		SEN(stime),			"stime"			},
[ 26] = { 4,	0,		SEN(ptrace),			"ptrace"		},
[ 27] = { 1,	0,		SEN(alarm),			"alarm"			},
[ 28] = { 0,	TS,		SEN(pause),			"pause"			},
[ 29] = { 2,	TF,		SEN(utime),			"utime"			},
[ 30] = { 2,	TF|TST|TSTA,	SEN(stat),			"stat"			},
[ 31] = { 2,	TD|TFST|TSTA,	SEN(fstat),			"fstat"			},
[ 32] = { 2,	TF|TLST|TSTA,	SEN(lstat),			"lstat"			},
[ 33] = { 2,	TF,		SEN(access),			"access"		},
[ 34] = { 1,	TF,		SEN(chroot),			"chroot"		},
[ 35] = { 0,	0,		SEN(sync),			"sync"			},
[ 36] = { 1,	TD,		SEN(fsync),			"fsync"			},
[ 37] = { 2,	TS|TP,		SEN(kill),			"kill"			},
[ 38] = { 2,	TF,		SEN(rename),			"rename"		},
[ 39] = { 2,	TF,		SEN(mkdir),			"mkdir"			},
[ 40] = { 1,	TF,		SEN(rmdir),			"rmdir"			},
[ 41] = { 1,	TD,		SEN(dup),			"dup"			},
[ 42] = { 1,	TD,		SEN(pipe),			"pipe"			},
[ 43] = { 1,	0,		SEN(times),			"times"			},
[ 44] = { 5,	TP,		SEN(clone),			"clone"			},
[ 45] = { 1,	TM|SI,		SEN(brk),			"brk"			},
[ 46] = { 1,	TC,		SEN(setgid),			"setgid"		},
[ 47] = { 0,	TC|PU|NF,	SEN(getgid),			"getgid"		},
[ 48] = { 2,	TF,		SEN(getcwd),			"getcwd"		},
[ 49] = { 0,	TC|PU|NF,	SEN(geteuid),			"geteuid"		},
[ 50] = { 0,	TC|PU|NF,	SEN(getegid),			"getegid"		},
[ 51] = { 1,	TF,		SEN(acct),			"acct"			},
[ 52] = { 1,	TC|NF,		SEN(setfsuid),			"setfsuid"		},
[ 53] = { 1,	TC|NF,		SEN(setfsgid),			"setfsgid"		},
[ 54] = { 3,	TD,		SEN(ioctl),			"ioctl"			},
[ 55] = { 3,	TD,		SEN(fcntl),			"fcntl"			},
[ 56] = { 2,	0,		SEN(setpgid),			"setpgid"		},
[ 57] = { 5,	TM|SI,		SEN(mremap),			"mremap"		},
[ 58] = { 3,	TC,		SEN(setresuid),			"setresuid"		},
[ 59] = { 3,	TC,		SEN(getresuid),			"getresuid"		},
[ 60] = { 2,	TC,		SEN(setreuid),			"setreuid"		},
[ 61] = { 2,	TC,		SEN(setregid),			"setregid"		},
[ 62] = { 2,	TSFA,		SEN(ustat),			"ustat"			},
[ 63] = { 2,	TD,		SEN(dup2),			"dup2"			},
[ 64] = { 0,	PU|NF,		SEN(getppid),			"getppid"		},
[ 65] = { 0,	PU|NF,		SEN(getpgrp),			"getpgrp"		},
[ 66] = { 0,	0,		SEN(setsid),			"setsid"		},
[ 67] = { 4,	TS,		SEN(rt_sigaction),		"rt_sigaction"		},
[ 68] = { 0,	TS,		SEN(rt_sigreturn),		"rt_sigreturn"		},
[ 69] = { 4,	TS,		SEN(rt_sigprocmask),		"rt_sigprocmask"	},
[ 70] = { 2,	TS,		SEN(rt_sigpending),		"rt_sigpending"		},
[ 71] = { 4,	TS,		SEN(rt_sigtimedwait_time32),	"rt_sigtimedwait"	},
[ 72] = { 3,	TS|TP,		SEN(rt_sigqueueinfo),		"rt_sigqueueinfo"	},
[ 73] = { 2,	TS,		SEN(rt_sigsuspend),		"rt_sigsuspend"		},
[ 74] = { 2,	0,		SEN(sethostname),		"sethostname"		},
[ 75] = { 2,	0,		SEN(setrlimit),			"setrlimit"		},
[ 76] = { 2,	0,		SEN(getrlimit),			"getrlimit"		},
[ 77] = { 2,	0,		SEN(getrusage),			"getrusage"		},
[ 78] = { 2,	TCL,		SEN(gettimeofday),		"gettimeofday"		},
[ 79] = { 2,	TCL,		SEN(settimeofday),		"settimeofday"		},
[ 80] = { 2,	TC,		SEN(getgroups),			"getgroups"		},
[ 81] = { 2,	TC,		SEN(setgroups),			"setgroups"		},
[ 82] = { 5,	TD,		SEN(select),			"select"		},
[ 83] = { 2,	TF,		SEN(symlink),			"symlink"		},
[ 84] = { 1,	TD,		SEN(fchdir),			"fchdir"		},
[ 85] = { 3,	TF,		SEN(readlink),			"readlink"		},
[ 86] = { 5,	TD,		SEN(pread),			"pread"			},
[ 87] = { 5,	TD,		SEN(pwrite),			"pwrite"		},
[ 88] = { 2,	TF,		SEN(swapon),			"swapon"		},
[ 89] = { 4,	0,		SEN(reboot),			"reboot"		},
[ 90] = { 6,	TD|TM|SI,	SEN(mmap_pgoff),		"mmap2"			},
[ 91] = { 2,	TM|SI,		SEN(munmap),			"munmap"		},
[ 92] = { 2,	TF,		SEN(truncate),			"truncate"		},
[ 93] = { 2,	TD,		SEN(ftruncate),			"ftruncate"		},
[ 94] = { 2,	TD,		SEN(fchmod),			"fchmod"		},
[ 95] = { 3,	TD,		SEN(fchown),			"fchown"		},
[ 96] = { 2,	0,		SEN(getpriority),		"getpriority"		},
[ 97] = { 3,	0,		SEN(setpriority),		"setpriority"		},
[ 98] = { 4,	TP,		SEN(wait4),			"wait4"			},
[ 99] = { 2,	TF|TSF|TSFA,	SEN(statfs),			"statfs"		},
[100] = { 2,	TD|TFSF|TSFA,	SEN(fstatfs),			"fstatfs"		},
[101] = { 0,	0,		SEN(vhangup),			"vhangup"		},
[102] = { 2,	TS,		SEN(sigaltstack),		"sigaltstack"		},
[103] = { 3,	0,		SEN(syslog),			"syslog"		},
[104] = { 3,	0,		SEN(setitimer),			"setitimer"		},
[105] = { 2,	0,		SEN(getitimer),			"getitimer"		},
[106] = { 1,	TF,		SEN(swapoff),			"swapoff"		},
[107] = { 1,	0,		SEN(sysinfo),			"sysinfo"		},
[108] = { 6,	TI|TSD,		SEN(ipc),			"ipc"			},
[109] = { 4,	TD|TN,		SEN(sendfile),			"sendfile"		},
[110] = { 2,	0,		SEN(setdomainname),		"setdomainname"		},
[111] = { 1,	0,		SEN(uname),			"uname"			},
[112] = { 1,	TCL,		SEN(adjtimex32),		"adjtimex"		},
[113] = { 3,	TM|SI,		SEN(mprotect),			"mprotect"		},
[114] = { 0,	TP,		SEN(vfork),			"vfork"			},
[115] = { 3,	0,		SEN(init_module),		"init_module"		},
[116] = { 2,	0,		SEN(delete_module),		"delete_module"		},
[117] = { 4,	TF,		SEN(quotactl),			"quotactl"		},
[118] = { 1,	0,		SEN(getpgid),			"getpgid"		},
[119] = { 2,	0,		SEN(bdflush),			"bdflush"		},
[120] = { 3,	0,		SEN(sysfs),			"sysfs"			},
[121] = { 1,	NF,		SEN(personality),		"personality"		},
[122] = { 5,	0,		SEN(afs_syscall),		"afs_syscall"		},
[123] = { 3,	TD,		SEN(getdents),			"getdents"		},
[124] = { 2,	TD,		SEN(flock),			"flock"			},
[125] = { 3,	TM,		SEN(msync),			"msync"			},
[126] = { 3,	TD,		SEN(readv),			"readv"			},
[127] = { 3,	TD,		SEN(writev),			"writev"		},
[128] = { 1,	0,		SEN(getsid),			"getsid"		},
[129] = { 1,	TD,		SEN(fdatasync),			"fdatasync"		},
[130] = { 1,	0,		SEN(sysctl),			"_sysctl"		},
[131] = { 2,	TM,		SEN(mlock),			"mlock"			},
[132] = { 2,	TM,		SEN(munlock),			"munlock"		},
[133] = { 1,	TM,		SEN(mlockall),			"mlockall"		},
[134] = { 0,	TM,		SEN(munlockall),		"munlockall"		},
[135] = { 2,	0,		SEN(sched_setparam),		"sched_setparam"	},
[136] = { 2,	0,		SEN(sched_getparam),		"sched_getparam"	},
[137] = { 3,	0,		SEN(sched_setscheduler),	"sched_setscheduler"	},
[138] = { 1,	0,		SEN(sched_getscheduler),	"sched_getscheduler"	},
[139] = { 0,	0,		SEN(sched_yield),		"sched_yield"		},
[140] = { 1,	0,		SEN(sched_get_priority_max),	"sched_get_priority_max"},
[141] = { 1,	0,		SEN(sched_get_priority_min),	"sched_get_priority_min"},
[142] = { 2,	0,		SEN(sched_rr_get_interval_time32),"sched_rr_get_interval"},
[143] = { 2,	0,		SEN(nanosleep_time32),		"nanosleep"		},
[144] = { 3,	TD,		SEN(poll_time32),		"poll"			},
[145] = { 3,	0,		SEN(nfsservctl),		"nfsservctl"		},
[146] = { 3,	TC,		SEN(setresgid),			"setresgid"		},
[147] = { 3,	TC,		SEN(getresgid),			"getresgid"		},
[148] = { 5,	CC|TC,		SEN(prctl),			"prctl"			},
[149] = { 3,	TN,		SEN(socket),			"socket"		},
[150] = { 3,	TN,		SEN(bind),			"bind"			},
[151] = { 3,	TN,		SEN(connect),			"connect"		},
[152] = { 2,	TN,		SEN(listen),			"listen"		},
[153] = { 3,	TN,		SEN(accept),			"accept"		},
[154] = { 3,	TN,		SEN(getsockname),		"getsockname"		},
[155] = { 3,	TN,		SEN(getpeername),		"getpeername"		},
[156] = { 4,	TN,		SEN(socketpair),		"socketpair"		},
[157] = { 4,	TN,		SEN(send),			"send"			},
[158] = { 4,	TN,		SEN(recv),			"recv"			},
[159] = { 6,	TN,		SEN(sendto),			"sendto"		},
[160] = { 6,	TN,		SEN(recvfrom),			"recvfrom"		},
[161] = { 2,	TN,		SEN(shutdown),			"shutdown"		},
[162] = { 5,	TN,		SEN(setsockopt),		"setsockopt"		},
[163] = { 5,	TN,		SEN(getsockopt),		"getsockopt"		},
[164] = { 3,	TN,		SEN(sendmsg),			"sendmsg"		},
[165] = { 3,	TN,		SEN(recvmsg),			"recvmsg"		},
[166] = { 3,	TF,		SEN(truncate64),		"truncate64"		},
[167] = { 3,	TD,		SEN(ftruncate64),		"ftruncate64"		},
[168] = { 2,	TF|TST|TSTA,	SEN(stat64),			"stat64"		},
[169] = { 2,	TF|TLST|TSTA,	SEN(lstat64),			"lstat64"		},
[170] = { 2,	TD|TFST|TSTA,	SEN(fstat64),			"fstat64"		},
[171] = { 2,	TF,		SEN(pivotroot),			"pivot_root"		},
[172] = { 3,	TM,		SEN(mincore),			"mincore"		},
[173] = { 3,	TM,		SEN(madvise),			"madvise"		},
[174] = { 3,	TD,		SEN(getdents64),		"getdents64"		},
[175] = { 3,	TD,		SEN(fcntl64),			"fcntl64"		},
[176] = { 0,	PU|NF,		SEN(gettid),			"gettid"		},
[177] = { 4,	TD,		SEN(readahead),			"readahead"		},
[178] = { 5,	TF,		SEN(setxattr),			"setxattr"		},
[179] = { 5,	TF,		SEN(setxattr),			"lsetxattr"		},
[180] = { 5,	TD,		SEN(fsetxattr),			"fsetxattr"		},
[181] = { 4,	TF,		SEN(getxattr),			"getxattr"		},
[182] = { 4,	TF,		SEN(getxattr),			"lgetxattr"		},
[183] = { 4,	TD,		SEN(fgetxattr),			"fgetxattr"		},
[184] = { 3,	TF,		SEN(listxattr),			"listxattr"		},
[185] = { 3,	TF,		SEN(listxattr),			"llistxattr"		},
[186] = { 3,	TD,		SEN(flistxattr),		"flistxattr"		},
[187] = { 2,	TF,		SEN(removexattr),		"removexattr"		},
[188] = { 2,	TF,		SEN(removexattr),		"lremovexattr"		},
[189] = { 2,	TD,		SEN(fremovexattr),		"fremovexattr"		},
[190] = { 2,	TS|TP,		SEN(tkill),			"tkill"			},
[191] = { 4,	TD|TN,		SEN(sendfile64),		"sendfile64"		},
[192] = { 6,	0,		SEN(futex_time32),		"futex"			},
[193] = { 3,	0,		SEN(sched_setaffinity),		"sched_setaffinity"	},
[194] = { 3,	0,		SEN(sched_getaffinity),		"sched_getaffinity"	},
[195] = { 2,	TC,		SEN(capget),			"capget"		},
[196] = { 2,	TC,		SEN(capset),			"capset"		},
[197] = { 2,	TM,		SEN(io_setup),			"io_setup"		},
[198] = { 1,	TM,		SEN(io_destroy),		"io_destroy"		},
[199] = { 5,	0,		SEN(io_getevents_time32),	"io_getevents"		},
[200] = { 3,	0,		SEN(io_submit),			"io_submit"		},
[201] = { 3,	0,		SEN(io_cancel),			"io_cancel"		},
[202] = { 5,	TD,		SEN(fadvise64),			"fadvise64"		},
[203] = { 1,	TP|SE,		SEN(exit),			"exit_group"		},
[204] = { 4,	0,		SEN(lookup_dcookie),		"lookup_dcookie"	},
[205] = { 1,	TD,		SEN(epoll_create),		"epoll_create"		},
[206] = { 4,	TD,		SEN(epoll_ctl),			"epoll_ctl"		},
[207] = { 4,	TD,		SEN(epoll_wait),		"epoll_wait"		},
[208] = { 5,	TM|SI,		SEN(remap_file_pages),		"remap_file_pages"	},
[209] = { 1,	0,		SEN(set_tid_address),		"set_tid_address"	},
[210] = { 3,	0,		SEN(timer_create),		"timer_create"		},
[211] = { 4,	0,		SEN(timer_settime32),		"timer_settime"		},
[212] = { 2,	0,		SEN(timer_gettime32),		"timer_gettime"		},
[213] = { 1,	0,		SEN(timer_getoverrun),		"timer_getoverrun"	},
[214] = { 1,	0,		SEN(timer_delete),		"timer_delete"		},
[215] = { 2,	TCL,		SEN(clock_settime32),		"clock_settime"		},
[216] = { 2,	TCL,		SEN(clock_gettime32),		"clock_gettime"		},
[217] = { 2,	TCL,		SEN(clock_getres_time32),	"clock_getres"		},
[218] = { 4,	0,		SEN(clock_nanosleep_time32),	"clock_nanosleep"	},
[219] = { 3,	TF|TSF|TSFA,	SEN(statfs64),			"statfs64"		},
[220] = { 3,	TD|TFSF|TSFA,	SEN(fstatfs64),			"fstatfs64"		},
[221] = { 3,	TS|TP,		SEN(tgkill),			"tgkill"		},
[222] = { },
[223] = { 2,	TF,		SEN(utimes),			"utimes"		},
[224] = { 6,	TD,		SEN(fadvise64_64),		"fadvise64_64"		},
[225] = { 3,	0,		SEN(printargs),			"cacheflush"		},
[226] = { 5,	0,		SEN(vserver),			"vserver"		},
[227] = { 4,	TD,		SEN(mq_open),			"mq_open"		},
[228] = { 1,	0,		SEN(mq_unlink),			"mq_unlink"		},
[229] = { 5,	TD,		SEN(mq_timedsend_time32),	"mq_timedsend"		},
[230] = { 5,	TD,		SEN(mq_timedreceive_time32),	"mq_timedreceive"	},
[231] = { 2,	TD,		SEN(mq_notify),			"mq_notify"		},
[232] = { 3,	TD,		SEN(mq_getsetattr),		"mq_getsetattr"		},
[233] = { 4,	0,		SEN(kexec_load),		"kexec_load"		},
[234] = { 5,	TP,		SEN(waitid),			"waitid"		},
[235] = { 5,	0,		SEN(add_key),			"add_key"		},
[236] = { 4,	0,		SEN(request_key),		"request_key"		},
[237] = { 5,	0,		SEN(keyctl),			"keyctl"		},
[238] = { 3,	0,		SEN(ioprio_set),		"ioprio_set"		},
[239] = { 2,	0,		SEN(ioprio_get),		"ioprio_get"		},
[240] = { 0,	TD,		SEN(inotify_init),		"inotify_init"		},
[241] = { 3,	TD|TF,		SEN(inotify_add_watch),		"inotify_add_watch"	},
[242] = { 2,	TD,		SEN(inotify_rm_watch),		"inotify_rm_watch"	},
[243] = { 4,	TD|TF,		SEN(openat),			"openat"		},
[244] = { 3,	TD|TF,		SEN(mkdirat),			"mkdirat"		},
[245] = { 4,	TD|TF,		SEN(mknodat),			"mknodat"		},
[246] = { 5,	TD|TF,		SEN(fchownat),			"fchownat"		},
[247] = { 3,	TD|TF,		SEN(futimesat),			"futimesat"		},
[248] = { 4,	TD|TF|TFST|TSTA,SEN(fstatat64),			"fstatat64"		},
[249] = { 3,	TD|TF,		SEN(unlinkat),			"unlinkat"		},
[250] = { 4,	TD|TF,		SEN(renameat),			"renameat"		},
[251] = { 5,	TD|TF,		SEN(linkat),			"linkat"		},
[252] = { 3,	TD|TF,		SEN(symlinkat),			"symlinkat"		},
[253] = { 4,	TD|TF,		SEN(readlinkat),		"readlinkat"		},
[254] = { 3,	TD|TF,		SEN(fchmodat),			"fchmodat"		},
[255] = { 3,	TD|TF,		SEN(faccessat),			"faccessat"		},
[256] = { 6,	TD,		SEN(pselect6_time32),		"pselect6"		},
[257] = { 5,	TD,		SEN(ppoll_time32),		"ppoll"			},
[258] = { 1,	0,		SEN(unshare),			"unshare"		},
[259] = { 2,	0,		SEN(set_robust_list),		"set_robust_list"	},
[260] = { 3,	0,		SEN(get_robust_list),		"get_robust_list"	},
[261] = { 6,	TD,		SEN(splice),			"splice"		},
[262] = { 6,	TD,		SEN(sync_file_range),		"sync_file_range"	},
[263] = { 4,	TD,		SEN(tee),			"tee"			},
[264] = { 4,	TD,		SEN(vmsplice),			"vmsplice"		},
[265] = { 6,	TD,		SEN(epoll_pwait),		"epoll_pwait"		},
[266] = { 2,	TI,		SEN(msgget),			"msgget"		},
[267] = { 4,	TI,		SEN(msgsnd),			"msgsnd"		},
[268] = { 5,	TI,		SEN(msgrcv),			"msgrcv"		},
[269] = { 3,	TI,		SEN(msgctl),			"msgctl"		},
[270] = { 3,	TI,		SEN(semget),			"semget"		},
[271] = { 3,	TI,		SEN(semop),			"semop"			},
[272] = { 4,	TI,		SEN(semctl),			"semctl"		},
[273] = { 4,	TI,		SEN(semtimedop_time32),		"semtimedop"		},
[274] = { 3,	TI|TM|SI,	SEN(shmat),			"shmat"			},
[275] = { 3,	TI,		SEN(shmget),			"shmget"		},
[276] = { 1,	TI|TM|SI,	SEN(shmdt),			"shmdt"			},
[277] = { 3,	TI,		SEN(shmctl),			"shmctl"		},
[278] = { 4,	TD|TF,		SEN(utimensat_time32),		"utimensat"		},
[279] = { 3,	TD|TS,		SEN(signalfd),			"signalfd"		},
[280] = { 4,	TD,		SEN(timerfd),			"timerfd"		},
[281] = { 1,	TD,		SEN(eventfd),			"eventfd"		},
[282] = { },
[283] = { 2,	TD,		SEN(setns),			"setns"			},
[284] = { 5,	TD,		SEN(pread),			"pread64"		},
[285] = { 5,	TD,		SEN(pwrite),			"pwrite64"		},
[286] = { 2,	TD,		SEN(timerfd_create),		"timerfd_create"	},
[287] = { 6,	TD,		SEN(fallocate),			"fallocate"		},
[288] = { 4,	TD,		SEN(timerfd_settime32),		"timerfd_settime"	},
[289] = { 2,	TD,		SEN(timerfd_gettime32),		"timerfd_gettime"	},
[290] = { 4,	TD|TS,		SEN(signalfd4),			"signalfd4"		},
[291] = { 2,	TD,		SEN(eventfd2),			"eventfd2"		},
[292] = { 1,	TD,		SEN(epoll_create1),		"epoll_create1"		},
[293] = { 3,	TD,		SEN(dup3),			"dup3"			},
[294] = { 2,	TD,		SEN(pipe2),			"pipe2"			},
[295] = { 1,	TD,		SEN(inotify_init1),		"inotify_init1"		},
[296] = { 5,	TD,		SEN(preadv),			"preadv"		},
[297] = { 5,	TD,		SEN(pwritev),			"pwritev"		},
[298] = { 4,	TP|TS,		SEN(rt_tgsigqueueinfo),		"rt_tgsigqueueinfo"	},
[299] = { 5,	TD,		SEN(perf_event_open),		"perf_event_open"	},
[300] = { 5,	TN,		SEN(recvmmsg_time32),		"recvmmsg"		},
[301] = { 2,	TD,		SEN(fanotify_init),		"fanotify_init"		},
[302] = { 6,	TD|TF,		SEN(fanotify_mark),		"fanotify_mark"		},
[303] = { 4,	0,		SEN(prlimit64),			"prlimit64"		},
[304] = { 5,	TD|TF,		SEN(name_to_handle_at),		"name_to_handle_at"	},
[305] = { 3,	TD,		SEN(open_by_handle_at),		"open_by_handle_at"	},
[306] = { 2,	TCL,		SEN(clock_adjtime32),		"clock_adjtime"		},
[307] = { 1,	TD,		SEN(syncfs),			"syncfs"		},
[308] = { 4,	TN,		SEN(sendmmsg),			"sendmmsg"		},
[309] = { 6,	0,		SEN(process_vm_readv),		"process_vm_readv"	},
[310] = { 6,	0,		SEN(process_vm_writev),		"process_vm_writev"	},
[311] = { 5,	0,		SEN(kcmp),			"kcmp"			},
[312] = { 3,	TD,		SEN(finit_module),		"finit_module"		},
[313] = { 3,	0,		SEN(sched_setattr),		"sched_setattr"		},
[314] = { 4,	0,		SEN(sched_getattr),		"sched_getattr"		},
[315] = { 5,	TD|TF,		SEN(renameat2),			"renameat2"		},
[316] = { 3,	0,		SEN(seccomp),			"seccomp"		},
[317] = { 3,	0,		SEN(getrandom),			"getrandom"		},
[318] = { 2,	TD,		SEN(memfd_create),		"memfd_create"		},
[319] = { 3,	TD,		SEN(bpf),			"bpf"			},
[320] = { 5,	CC|TD|TF|TP|TSD|SE|SI,	SEN(execveat),			"execveat"		},
[321] = { 4,	TN,		SEN(accept4),			"accept4"		},
[322] = { 1,	TD,		SEN(userfaultfd),		"userfaultfd"		},
[323] = { 3,	0,		SEN(membarrier),		"membarrier"		},
[324] = { 3,	TM,		SEN(mlock2),			"mlock2"		},
[325] = { 6,	TD,		SEN(copy_file_range),		"copy_file_range"	},
[326] = { 6,	TD,		SEN(preadv2),			"preadv2"		},
[327] = { 6,	TD,		SEN(pwritev2),			"pwritev2"		},
[328] = { 4,	TM|SI,		SEN(pkey_mprotect),		"pkey_mprotect"		},
[329] = { 2,	0,		SEN(pkey_alloc),		"pkey_alloc"		},
[330] = { 1,	0,		SEN(pkey_free),			"pkey_free"		},
