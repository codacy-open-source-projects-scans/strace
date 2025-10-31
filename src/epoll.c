/*
 * Copyright (c) 2004-2007 Ulrich Drepper <drepper@redhat.com>
 * Copyright (c) 2004 Roland McGrath <roland@redhat.com>
 * Copyright (c) 2005-2015 Dmitry V. Levin <ldv@strace.io>
 * Copyright (c) 2015-2025 The strace developers.
 * All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include "defs.h"
#include "kernel_fcntl.h"
#include <linux/eventpoll.h>

SYS_FUNC(epoll_create)
{
	/* size */
	tprints_arg_name("size");
	int size = tcp->u_arg[0];
	PRINT_VAL_D(size);

	return RVAL_DECODED | RVAL_FD;
}

#include "xlat/epollflags.h"

SYS_FUNC(epoll_create1)
{
	/* flags */
	tprints_arg_name("flags");
	printflags(epollflags, tcp->u_arg[0], "EPOLL_???");

	return RVAL_DECODED | RVAL_FD;
}

#include "xlat/epollevents.h"

static bool
print_epoll_event(struct tcb *tcp, void *elem_buf, size_t elem_size, void *data)
{
	const struct epoll_event *ev = elem_buf;

	tprint_struct_begin();
	PRINT_FIELD_FLAGS(*ev, events, epollevents, "EPOLL???");
	tprint_struct_next();
	PRINT_FIELD_X(*ev, data);
	tprint_struct_end();

	return true;
}

#include "xlat/epollctls.h"

SYS_FUNC(epoll_ctl)
{
	/* epfd */
	tprints_arg_name("epfd");
	printfd(tcp, tcp->u_arg[0]);

	/* op */
	tprints_arg_next_name("op");
	const unsigned int op = tcp->u_arg[1];
	printxval(epollctls, op, "EPOLL_CTL_???");

	/* fd */
	tprints_arg_next_name("fd");
	printfd(tcp, tcp->u_arg[2]);

	/* event */
	tprints_arg_next_name("event");
	struct epoll_event ev;
	if (EPOLL_CTL_DEL == op)
		printaddr(tcp->u_arg[3]);
	else if (!umove_or_printaddr(tcp, tcp->u_arg[3], &ev))
		print_epoll_event(tcp, &ev, sizeof(ev), 0);

	return RVAL_DECODED;
}

static void
epoll_wait_common(struct tcb *tcp, const print_obj_by_addr_fn print_timeout)
{
	if (entering(tcp)) {
		/* epfd */
		tprints_arg_name("epfd");
		printfd(tcp, tcp->u_arg[0]);
	} else {
		/* events */
		tprints_arg_next_name("events");
		struct epoll_event ev;
		print_array(tcp, tcp->u_arg[1], tcp->u_rval, &ev, sizeof(ev),
			    tfetch_mem, print_epoll_event, 0);

		/* maxevents */
		tprints_arg_next_name("maxevents");
		int maxevents = tcp->u_arg[2];
		PRINT_VAL_D(maxevents);

		/* timeout */
		tprints_arg_next_name("timeout");
		print_timeout(tcp, tcp->u_arg[3]);
	}
}

static int
print_timeout_int(struct tcb *tcp, kernel_ulong_t arg)
{
	int timeout = arg;
	PRINT_VAL_D(timeout);
	return 0;
}

SYS_FUNC(epoll_wait)
{
	epoll_wait_common(tcp, print_timeout_int);
	return 0;
}

static int
epoll_pwait_common(struct tcb *tcp, const print_obj_by_addr_fn print_timeout)
{
	epoll_wait_common(tcp, print_timeout);
	if (exiting(tcp)) {
		/* sigmask */
		/* NB: kernel requires arg[5] == NSIG_BYTES */
		tprints_arg_next_name("sigmask");
		print_sigset_addr_len(tcp, tcp->u_arg[4], tcp->u_arg[5]);

		/* sigsetsize */
		tprints_arg_next_name("sigsetsize");
		PRINT_VAL_U(tcp->u_arg[5]);
	}
	return 0;
}

SYS_FUNC(epoll_pwait)
{
	return epoll_pwait_common(tcp, print_timeout_int);
}

SYS_FUNC(epoll_pwait2)
{
	return epoll_pwait_common(tcp, print_timespec64);
}
