/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __UNISTD_H__
#define __UNISTD_H__	1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/io.h>
#include <internal/types.h>

struct timespec {
    long tv_sec;
    long tv_nsec;
};

int nanosleep(const struct timespec *req, struct timespec *rem);


#ifdef __cplusplus
}
#endif

#endif
