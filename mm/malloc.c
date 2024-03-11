// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	void *arr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (arr == MAP_FAILED)
		return NULL;

	mem_list_add(arr, size);

	return arr;
}

void *calloc(size_t nmemb, size_t size)
{
	void *arr = malloc(nmemb * size);

	for (size_t i = 0; i < nmemb; i++) {
		*(size_t *)(arr + i) = 0;
	}

	return arr;
}

void free(void *ptr)
{
	struct mem_list *item;
	item = mem_list_find(ptr);

	if (!item)
		return;

	munmap(ptr, item->len);
	mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	struct mem_list *item;
	item = mem_list_find(ptr);
	size_t prev_size = item->len;
	void *arr = malloc(size);

	if (prev_size < size)
		memcpy(arr, ptr, prev_size);
	else
		memcpy(arr, ptr, size);

	mem_list_del(ptr);
	mem_list_add(arr, size);
	return arr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	void *arr = realloc(ptr, nmemb * size);

	return arr;
}
