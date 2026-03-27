// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>

#include "binary_search.h"

int binary_search(int *v, int len, int dest)
{
	int start = 0;
	int end = len - 1;
	int middle;

	loop: 
		if (start > end)
			return -1;

		middle = (end + start)/ 2;

		if (v[middle] == dest) {
			goto end;
		}

		if (v[middle] < dest) {
			goto bigger;
		}

		end = middle - 1;
		goto loop;

	bigger:
		start = middle + 1;
		goto loop;

	end: return middle;
}
