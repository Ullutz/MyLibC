// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	mode_t mod = 0;

	va_list arguments;

	va_start(arguments, flags);
	if (flags)
		mod = va_arg(arguments, mode_t);

	va_end(arguments);


	int ret = syscall(__NR_open, filename, flags, mod);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}
