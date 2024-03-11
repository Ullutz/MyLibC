// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>
#include <stdlib.h>

char *strcpy(char *destination, const char *source)
{
	int i = 0;
	while (*(source + i)) {
		*(destination + i) = *(source + i);
		i++;
	}
	*(destination + i) = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	size_t i = 0;
	while (*(source + i) && i <= len) {
		*(destination + i) = *(source + i);
		i++;
	}

	*(destination + i) = '\0';

	return destination;
}

char *strcat(char *destination, const char *source)
{
	int i = 0;
	int j = strlen(destination);
	while (*(source + i)) {
		*(destination + j + i) = *(source + i);
		i++;
	}

	*(destination + j + i) = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	size_t i = 0;
	int j = strlen(destination);
	while (*(source + i)&& i < len) {
		*(destination + j + i) = *(source + i);
		i++;
	}

	*(destination + j + i) = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	int i = 0;
	while (*(str1 + i) == *(str2 + i) && *(str1 + i) && *(str2 + i))
		i++;

	if (*(str1 + i) - *(str2 + i) < 0)
		return -1;
	if (*(str1 + i) - *(str2 + i) > 0)
		return 1;

	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	size_t i = 0;
	while (*(str1 + i) == *(str2 + i) && *(str1 + i) && *(str2 + i) && i < len)
		i++;

	if (i == len)
		i--;

	if (*(str1 + i) - *(str2 + i) < 0)
		return -1;
	if (*(str1 + i) - *(str2 + i) > 0)
		return 1;

	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	int i = 0;
	while (*(str + i) != c && *(str + i))
		i++;

	if (!*(str + i))
		return NULL;

	return (char *)(str + i);
}

char *strrchr(const char *str, int c)
{
	int i = strlen(str);
	while (i != 0) {
		if ( *(str + i) == c)
			return (char *)(str + i);

		i--;
	}

	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	int i = 0;
	while (*(haystack + i + strlen(needle))) {
		const char *substring = haystack + i;
		if (strncmp(substring, needle, strlen(needle)) == 0)
			return (char *)substring;

		i++;
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	int i = strlen(haystack) - strlen(needle);
	while (i != 0) {
		const char *substring = haystack + i;
		if (strncmp(substring, needle, strlen(needle)) == 0)
			return (char *)substring;

		i--;
	}

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *dst = (char *) destination;
	char *src = (char *) source;

	for (size_t i = 0; i < num; i++) {
		dst[i] = src[i];
	}

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *dst = (char *) destination;
	char *temporary = malloc(num * sizeof(char *));
	char *src = (char *) source;

	for (size_t i = 0; i < num; i++) {
		temporary[i] = src[i];
	}

	for (size_t i = 0; i < num; i++) {
		dst[i] = temporary[i];
	}

	free(temporary);

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	char *str1 = (char *) ptr1;
	char *str2 = (char *) ptr2;

	int n = strncmp(str1, str2, num);
	return n;
}

void *memset(void *source, int value, size_t num)
{
	char *str = (char *) source;
	for (size_t i = 0; i < num; i++) {
		str[i] = value;
	}
	return source;
}
