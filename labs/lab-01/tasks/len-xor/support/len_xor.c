// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "len_xor.h"

int my_strlen(const char *str)
{
	int res = 0;

	for (res = 0; *str; str++) {
		res++;
	}
	return res;
}

void equality_check(const char *str)
{
	int n, i;
	char check, curr;

	n = my_strlen(str);

	for (i = 0; i < n; i++) {
		curr = *(str + i);
		check = *(str + ((i + (1 << i)) % n));
		if ((curr ^ check) == 0) {
			printf("Address of %c: %p\n", curr, str + i);
		}
	}
}

