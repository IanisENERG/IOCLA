// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <stdlib.h>

#include "odd_even.h"

void print_binary(int number, int nr_bits)
{
	printf("0b");
	for (int i = nr_bits - 1; i >= 0; i--) {
		int bit = (number >> i) & 1;
		printf("%d", bit);
	}
}

void check_parity(int *numbers, int n)
{
	int nr_bits;
	for (int i = 0; i < n; i++) {
		int value = *(numbers + i);
		if (!(value & 1)) {

			if (value == 0) {
				printf ("0b0");
				continue;
			}

			nr_bits = 0;
			int tmp = *(numbers + i);
			while (tmp > 0) {
				tmp = tmp >> 1;
				nr_bits++;
			}
			print_binary(value, nr_bits);
		}
		else {
			printf("0x%08X", value);
		}
		printf("\n");
	}
}
