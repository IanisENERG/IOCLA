// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "pixel.h"
#include "pixels.h"

#define GET_PIXEL(a, i, j) ((*(*(a) + (i)) + (j)))

void reverse_pic(struct picture *pic)
{
	if (pic == NULL || pic->pix_array == NULL) {
		return;
	}
	for (int i = 0; i < pic->height / 2; i++) {
		struct pixel *tmp_row = pic->pix_array[i];
		pic->pix_array[i] = pic->pix_array[pic->height - i - 1];
		pic->pix_array[pic->height - i - 1] = tmp_row;
 	}
}

	void color_to_gray(struct picture *pic)
{
    if (!pic || !pic->pix_array) return;

    for (int i = 0; i < pic->height; i++) {
        for (int j = 0; j < pic->width; j++) {
            struct pixel *p = &pic->pix_array[i][j];
            p->R = 0.3 * p->R;
            p->G = 0.59 * p->G;
            p->B = 0.11 * p->B;
        }
    }
}

