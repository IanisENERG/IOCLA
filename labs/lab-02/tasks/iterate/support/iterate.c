// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>

#include "iterate.h"
#include "array.h"

void print_chars(void)
{
	unsigned char *it = (unsigned char*) v;
	for (int i = 0; i < sizeof(v) ; i++) {
		printf("%p -> 0x%x\n", (it + i), *(it + i));
	}
	printf("-------------------------------\n");
}

void print_shorts(void)
{
	unsigned short *it = (unsigned short*) v;
	for (int i = 0; i < sizeof(v) / (sizeof(short)); i++) {
		printf("%p -> 0x%x\n", (it + i), *(it + i));
	}

	printf("-------------------------------\n");
}

void print_ints(void)
{
	unsigned int *it = (unsigned int*) v;
	for (int i = 0; i < sizeof(v) / (sizeof(int)); i++) {
		printf("%p -> 0x%x\n", (it + i), *(it + i));
	}

	printf("-------------------------------\n");
}

void print_long_longs(void)
{
	unsigned long long *it = (unsigned long long*) v;
	for (int i = 0; i < sizeof(v) / (sizeof(long long)); i++) {
		printf("%p -> 0x%llx\n", (it + i), *(it + i));
	}

	printf("-------------------------------\n");
}
