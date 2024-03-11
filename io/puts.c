#include <stdio.h>
#include <internal/syscall.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int puts(const char *s) {
    int ret = write(1, s, strlen(s));
    write(1, "\n", 1);


    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}
