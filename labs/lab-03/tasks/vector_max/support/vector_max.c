// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>

#include "vector_max.h"

int vector_max(int *v, int len)
{
	int max;
	unsigned int i = 0;

	greater_than: max = *(v + i);
	v_is_equal: i++;

	if (*(v + i) > max && i < len) {
		goto greater_than;
	}
	if (*(v + i) <= max && i < len){
		goto v_is_equal;
	}

	return max;
}
