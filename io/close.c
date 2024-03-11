// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	int flag = syscall(__NR_close, fd);

	if (flag < 0) {
		errno = -flag;
		return -1;
	}

	return flag;
}
