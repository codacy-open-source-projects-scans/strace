/*
 * Check decoding of pipe syscall.
 *
 * Copyright (c) 2015-2016 Dmitry V. Levin <ldv@strace.io>
 * Copyright (c) 2015-2024 The strace developers.
 * All rights reserved.
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "tests.h"
#include "scno.h"

#ifdef __NR_pipe

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

int
main(void)
{
	(void) close(0);
	(void) close(1);
	TAIL_ALLOC_OBJECT_CONST_ARR(int, fds, 2);
	if (pipe(fds))
		perror_msg_and_fail("pipe");

	return 0;
}

#else

SKIP_MAIN_UNDEFINED("__NR_pipe")

#endif
