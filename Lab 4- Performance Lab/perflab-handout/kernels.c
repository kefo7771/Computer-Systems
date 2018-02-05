/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/*
 * Please fill in the following student struct
 */
student_t student = {
    "Kenneth Ford",     /* First member full name */
    "kenneth.ford@colorado.edu"  /* First member email address */
};

/***************
 * ROTATE KERNEL
 ***************/

/******************************************************
 * Your different versions of the rotate kernel go here
 ******************************************************/

/*
 * new_rotate1 - The naive baseline version of rotate
 */
char new_rotate1_descr[] = "new_rotate1: First changed implementation w/ loop order reversed";
void new_rotate1(int dim, pixel *src, pixel *dst)
{
    int i, j;
    for (j = 0; j < dim; j++){
        for (i = 0; i < dim; i++){
            dst[RIDX(dim-1-j, i, dim)].red   = src[RIDX(i, j, dim)].red;
            dst[RIDX(dim-1-j, i, dim)].green = src[RIDX(i, j, dim)].green;
            dst[RIDX(dim-1-j, i, dim)].blue  = src[RIDX(i, j, dim)].blue;
        }
    }
}

/*
 * new_rotate12 - The naive baseline version of rotate
 */
char new_rotate2_descr[] = "new_rotate2: Changed new_rotate1 with 2 operations per iteration";
void new_rotate2(int dim, pixel *src, pixel *dst)
{
    int i, j;
    for (i = 0; i < dim; i++){
        for (j = 0; j < dim; j+=2){
            dst[RIDX(dim-1-j, i, dim)].red   = src[RIDX(i, j, dim)].red;
            dst[RIDX(dim-1-j, i, dim)].green = src[RIDX(i, j, dim)].green;
            dst[RIDX(dim-1-j, i, dim)].blue  = src[RIDX(i, j, dim)].blue;

            dst[RIDX(dim-1-(j+1), i, dim)].red   = src[RIDX(i, (j+1), dim)].red;
            dst[RIDX(dim-1-(j+1), i, dim)].green = src[RIDX(i, (j+1), dim)].green;
            dst[RIDX(dim-1-(j+1), i, dim)].blue  = src[RIDX(i, (j+1), dim)].blue;
        }
    }
}

/*
 * new_rotate12 - The naive baseline version of rotate
 */
char new_rotate3_descr[] = "new_rotate3: Changed new_rotate2 with 4 operations per iteration";
void new_rotate3(int dim, pixel *src, pixel *dst)
{
    int i, j;
    for (i = 0; i < dim; i+=2){
        for (j = 0; j < dim; j+=2){
            dst[RIDX(dim-1-j, i, dim)].red   = src[RIDX(i, j, dim)].red;
            dst[RIDX(dim-1-j, i, dim)].green = src[RIDX(i, j, dim)].green;
            dst[RIDX(dim-1-j, i, dim)].blue  = src[RIDX(i, j, dim)].blue;

            dst[RIDX(dim-1-(j+1), i, dim)].red   = src[RIDX(i, (j+1), dim)].red;
            dst[RIDX(dim-1-(j+1), i, dim)].green = src[RIDX(i, (j+1), dim)].green;
            dst[RIDX(dim-1-(j+1), i, dim)].blue  = src[RIDX(i, (j+1), dim)].blue;

            dst[RIDX(dim-1-j, (i+1), dim)].red   = src[RIDX((i+1), j, dim)].red;
            dst[RIDX(dim-1-j, (i+1), dim)].green = src[RIDX((i+1), j, dim)].green;
            dst[RIDX(dim-1-j, (i+1), dim)].blue  = src[RIDX((i+1), j, dim)].blue;

            dst[RIDX(dim-1-(j+1), (i+1), dim)].red   = src[RIDX((i+1), (j+1), dim)].red;
            dst[RIDX(dim-1-(j+1), (i+1), dim)].green = src[RIDX((i+1), (j+1), dim)].green;
            dst[RIDX(dim-1-(j+1), (i+1), dim)].blue  = src[RIDX((i+1), (j+1), dim)].blue;
        }
    }
}

char new_rotate4_descr[] = "new_rotate4: Changed i j order 2 operations per iteration";
void new_rotate4(int dim, pixel *src, pixel *dst)
{
    int i, j;
    for (j = 0; j < dim; j++){
        for (i = 0; i < dim; i+=2){
            dst[RIDX(dim-1-j, i, dim)].red   = src[RIDX(i, j, dim)].red;
            dst[RIDX(dim-1-j, i, dim)].green = src[RIDX(i, j, dim)].green;
            dst[RIDX(dim-1-j, i, dim)].blue  = src[RIDX(i, j, dim)].blue;

            dst[RIDX(dim-1-(j), (i+1), dim)].red   = src[RIDX((i+1), (j), dim)].red;
            dst[RIDX(dim-1-(j), (i+1), dim)].green = src[RIDX((i+1), (j), dim)].green;
            dst[RIDX(dim-1-(j), (i+1), dim)].blue  = src[RIDX((i+1), (j), dim)].blue;
        }
    }
}

char new_rotate5_descr[] = "new_rotate5: Changed i j order 5 operations per iteration";
void new_rotate5(int dim, pixel *src, pixel *dst)
{
    int i, j;
    for (j = 0; j < dim; j+=2){
        for (i = 0; i < dim; i+=2){
            dst[RIDX(dim-1-j, i, dim)].red   = src[RIDX(i, j, dim)].red;
            dst[RIDX(dim-1-j, i, dim)].green = src[RIDX(i, j, dim)].green;
            dst[RIDX(dim-1-j, i, dim)].blue  = src[RIDX(i, j, dim)].blue;

            dst[RIDX(dim-1-(j), (i+1), dim)].red   = src[RIDX((i+1), (j), dim)].red;
            dst[RIDX(dim-1-(j), (i+1), dim)].green = src[RIDX((i+1), (j), dim)].green;
            dst[RIDX(dim-1-(j), (i+1), dim)].blue  = src[RIDX((i+1), (j), dim)].blue;

            dst[RIDX(dim-1-(j+1), (i), dim)].red   = src[RIDX((i), (j+1), dim)].red;
            dst[RIDX(dim-1-(j+1), (i), dim)].green = src[RIDX((i), (j+1), dim)].green;
            dst[RIDX(dim-1-(j+1), (i), dim)].blue  = src[RIDX((i), (j+1), dim)].blue;

            dst[RIDX(dim-1-(j+1), (i+1), dim)].red   = src[RIDX((i+1), (j+1), dim)].red;
            dst[RIDX(dim-1-(j+1), (i+1), dim)].green = src[RIDX((i+1), (j+1), dim)].green;
            dst[RIDX(dim-1-(j+1), (i+1), dim)].blue  = src[RIDX((i+1), (j+1), dim)].blue;
        }
    }
}

char new_rotate6_descr[] = "new_rotate6: 4 operations per iteration w/ code motion step 1";
void new_rotate6(int dim, pixel *src, pixel *dst)
{
    int i, j, a, b, c, d;
    for (i = 0; i < dim; i+=2){
        for (j = 0; j < dim; j+=2){
            a = -1 - j;
            b = (j+1);
            c = -1 - b;
            d = (i + 1);
            dst[RIDX(dim + a, i, dim)].red   = src[RIDX(i, j, dim)].red;
            dst[RIDX(dim + a, i, dim)].green = src[RIDX(i, j, dim)].green;
            dst[RIDX(dim + a, i, dim)].blue  = src[RIDX(i, j, dim)].blue;

            dst[RIDX(dim + c, i, dim)].red   = src[RIDX(i, b, dim)].red;
            dst[RIDX(dim + c, i, dim)].green = src[RIDX(i, b, dim)].green;
            dst[RIDX(dim + c, i, dim)].blue  = src[RIDX(i, b, dim)].blue;

            dst[RIDX(dim + a, d, dim)].red   = src[RIDX(d, j, dim)].red;
            dst[RIDX(dim + a, d, dim)].green = src[RIDX(d, j, dim)].green;
            dst[RIDX(dim + a, d, dim)].blue  = src[RIDX(d, j, dim)].blue;

            dst[RIDX(dim + c, d, dim)].red   = src[RIDX(d, b, dim)].red;
            dst[RIDX(dim + c, d, dim)].green = src[RIDX(d, b, dim)].green;
            dst[RIDX(dim + c, d, dim)].blue  = src[RIDX(d, b, dim)].blue;
        }
    }
}

char new_rotate7_descr[] = "new_rotate7:";
void new_rotate7(int dim, pixel *src, pixel *dst)
{
    int i, j;
    for (i = 0; i < dim; i++){
        for (j = 0; j < dim; j+=4){
            dst[RIDX(dim-1-j, i, dim)].red   = src[RIDX(i, j, dim)].red;
            dst[RIDX(dim-1-j, i, dim)].green = src[RIDX(i, j, dim)].green;
            dst[RIDX(dim-1-j, i, dim)].blue  = src[RIDX(i, j, dim)].blue;

            dst[RIDX(dim-1-(j+1), (i), dim)].red   = src[RIDX((i), (j+1), dim)].red;
            dst[RIDX(dim-1-(j+1), (i), dim)].green = src[RIDX((i), (j+1), dim)].green;
            dst[RIDX(dim-1-(j+1), (i), dim)].blue  = src[RIDX((i), (j+1), dim)].blue;

            dst[RIDX(dim-1-(j+2), (i), dim)].red   = src[RIDX((i), (j+2), dim)].red;
            dst[RIDX(dim-1-(j+2), (i), dim)].green = src[RIDX((i), (j+2), dim)].green;
            dst[RIDX(dim-1-(j+2), (i), dim)].blue  = src[RIDX((i), (j+2), dim)].blue;

            dst[RIDX(dim-1-(j+3), (i), dim)].red   = src[RIDX((i), (j+3), dim)].red;
            dst[RIDX(dim-1-(j+3), (i), dim)].green = src[RIDX((i), (j+3), dim)].green;
            dst[RIDX(dim-1-(j+3), (i), dim)].blue  = src[RIDX((i), (j+3), dim)].blue;
        }
    }
}

/**********************/
/*
 * new_rotate_8 - Eighth new version of rotate with 4 actions in loop
 */
char new_rotate8_descr[] = "new_rotate_8: Eighth new version of rotate with 4 actions in loop";
void new_rotate8(int dim, pixel *src, pixel *dst)
{
    int i, j;
    for (j = 0; j < dim; j++){
        for (i = 0; i < dim; i+=4){
            //first i
            dst[RIDX(dim-1-j, i, dim)].red   = src[RIDX(i, j, dim)].red;
            dst[RIDX(dim-1-j, i, dim)].green = src[RIDX(i, j, dim)].green;
            dst[RIDX(dim-1-j, i, dim)].blue  = src[RIDX(i, j, dim)].blue;
            //second i
            dst[RIDX(dim-1-j, i+1, dim)].red   = src[RIDX(i+1, j, dim)].red;
            dst[RIDX(dim-1-j, i+1, dim)].green = src[RIDX(i+1, j, dim)].green;
            dst[RIDX(dim-1-j, i+1, dim)].blue  = src[RIDX(i+1, j, dim)].blue;
            //third i
            dst[RIDX(dim-1-j, i+2, dim)].red   = src[RIDX(i+2, j, dim)].red;
            dst[RIDX(dim-1-j, i+2, dim)].green = src[RIDX(i+2, j, dim)].green;
            dst[RIDX(dim-1-j, i+2, dim)].blue  = src[RIDX(i+2, j, dim)].blue;
            //fourth i
            dst[RIDX(dim-1-j, i+3, dim)].red   = src[RIDX(i+3, j, dim)].red;
            dst[RIDX(dim-1-j, i+3, dim)].green = src[RIDX(i+3, j, dim)].green;
            dst[RIDX(dim-1-j, i+3, dim)].blue  = src[RIDX(i+3, j, dim)].blue;
        }// for i
    }// for j
}// new_rotate_8
/**********************/

/**********************/
/*
 * new_rotate_9 - Ninth new version of rotate with 4 actions in loop
 */
char new_rotate9_descr[] = "new_rotate_9: Ninth new version of rotate with 8 actions in loop";
void new_rotate9(int dim, pixel *src, pixel *dst)
{
    int i, j;
    for (j = 0; j < dim; j+=2){
        for (i = 0; i < dim; i+=4){
            //first i, first j
            dst[RIDX(dim-1-j, i, dim)].red   = src[RIDX(i, j, dim)].red;
            dst[RIDX(dim-1-j, i, dim)].green = src[RIDX(i, j, dim)].green;
            dst[RIDX(dim-1-j, i, dim)].blue  = src[RIDX(i, j, dim)].blue;
            //second i, first j
            dst[RIDX(dim-1-j, i+1, dim)].red   = src[RIDX(i+1, j, dim)].red;
            dst[RIDX(dim-1-j, i+1, dim)].green = src[RIDX(i+1, j, dim)].green;
            dst[RIDX(dim-1-j, i+1, dim)].blue  = src[RIDX(i+1, j, dim)].blue;
            //third i, first j
            dst[RIDX(dim-1-j, i+2, dim)].red   = src[RIDX(i+2, j, dim)].red;
            dst[RIDX(dim-1-j, i+2, dim)].green = src[RIDX(i+2, j, dim)].green;
            dst[RIDX(dim-1-j, i+2, dim)].blue  = src[RIDX(i+2, j, dim)].blue;
            //fourth i, first j
            dst[RIDX(dim-1-j, i+3, dim)].red   = src[RIDX(i+3, j, dim)].red;
            dst[RIDX(dim-1-j, i+3, dim)].green = src[RIDX(i+3, j, dim)].green;
            dst[RIDX(dim-1-j, i+3, dim)].blue  = src[RIDX(i+3, j, dim)].blue;

            //first i, second j
            dst[RIDX(dim-1-(j+1), i, dim)].red   = src[RIDX(i, (j+1), dim)].red;
            dst[RIDX(dim-1-(j+1), i, dim)].green = src[RIDX(i, (j+1), dim)].green;
            dst[RIDX(dim-1-(j+1), i, dim)].blue  = src[RIDX(i, (j+1), dim)].blue;
            //second i, second j
            dst[RIDX(dim-1-(j+1), i+1, dim)].red   = src[RIDX(i+1, (j+1), dim)].red;
            dst[RIDX(dim-1-(j+1), i+1, dim)].green = src[RIDX(i+1, (j+1), dim)].green;
            dst[RIDX(dim-1-(j+1), i+1, dim)].blue  = src[RIDX(i+1, (j+1), dim)].blue;
            //third i, second j
            dst[RIDX(dim-1-(j+1), i+2, dim)].red   = src[RIDX(i+2, (j+1), dim)].red;
            dst[RIDX(dim-1-(j+1), i+2, dim)].green = src[RIDX(i+2, (j+1), dim)].green;
            dst[RIDX(dim-1-(j+1), i+2, dim)].blue  = src[RIDX(i+2, (j+1), dim)].blue;
            //fourth i, second j
            dst[RIDX(dim-1-(j+1), i+3, dim)].red   = src[RIDX(i+3, (j+1), dim)].red;
            dst[RIDX(dim-1-(j+1), i+3, dim)].green = src[RIDX(i+3, (j+1), dim)].green;
            dst[RIDX(dim-1-(j+1), i+3, dim)].blue  = src[RIDX(i+3, (j+1), dim)].blue;
        }// for i
    }// for j
}// new_rotate_9
/**********************/

/*
 * new_rotate10 - Ninth new version of rotate with 4 actions in loop
 */
char new_rotate10_descr[] = "new_rotate_10: Tenth new version of rotate with 8 actions in loop";
void new_rotate10(int dim, pixel *src, pixel *dst)
{
    int i, j;
    for (i = 0; i < dim; i+=4){
        for (j = 0; j < dim; j+=4){
            //first i, first j
            dst[RIDX(dim-1-j, i, dim)].red   = src[RIDX(i, j, dim)].red;
            dst[RIDX(dim-1-j, i, dim)].green = src[RIDX(i, j, dim)].green;
            dst[RIDX(dim-1-j, i, dim)].blue  = src[RIDX(i, j, dim)].blue;
            //second i, first j
            dst[RIDX(dim-1-j, i+1, dim)].red   = src[RIDX(i+1, j, dim)].red;
            dst[RIDX(dim-1-j, i+1, dim)].green = src[RIDX(i+1, j, dim)].green;
            dst[RIDX(dim-1-j, i+1, dim)].blue  = src[RIDX(i+1, j, dim)].blue;
            //third i, first j
            dst[RIDX(dim-1-j, i+2, dim)].red   = src[RIDX(i+2, j, dim)].red;
            dst[RIDX(dim-1-j, i+2, dim)].green = src[RIDX(i+2, j, dim)].green;
            dst[RIDX(dim-1-j, i+2, dim)].blue  = src[RIDX(i+2, j, dim)].blue;
            //fourth i, first j
            dst[RIDX(dim-1-j, i+3, dim)].red   = src[RIDX(i+3, j, dim)].red;
            dst[RIDX(dim-1-j, i+3, dim)].green = src[RIDX(i+3, j, dim)].green;
            dst[RIDX(dim-1-j, i+3, dim)].blue  = src[RIDX(i+3, j, dim)].blue;

            //first i, second j
            dst[RIDX(dim-1-(j+1), i, dim)].red   = src[RIDX(i, (j+1), dim)].red;
            dst[RIDX(dim-1-(j+1), i, dim)].green = src[RIDX(i, (j+1), dim)].green;
            dst[RIDX(dim-1-(j+1), i, dim)].blue  = src[RIDX(i, (j+1), dim)].blue;
            //second i, second j
            dst[RIDX(dim-1-(j+1), i+1, dim)].red   = src[RIDX(i+1, (j+1), dim)].red;
            dst[RIDX(dim-1-(j+1), i+1, dim)].green = src[RIDX(i+1, (j+1), dim)].green;
            dst[RIDX(dim-1-(j+1), i+1, dim)].blue  = src[RIDX(i+1, (j+1), dim)].blue;
            //third i, second j
            dst[RIDX(dim-1-(j+1), i+2, dim)].red   = src[RIDX(i+2, (j+1), dim)].red;
            dst[RIDX(dim-1-(j+1), i+2, dim)].green = src[RIDX(i+2, (j+1), dim)].green;
            dst[RIDX(dim-1-(j+1), i+2, dim)].blue  = src[RIDX(i+2, (j+1), dim)].blue;
            //fourth i, second j
            dst[RIDX(dim-1-(j+1), i+3, dim)].red   = src[RIDX(i+3, (j+1), dim)].red;
            dst[RIDX(dim-1-(j+1), i+3, dim)].green = src[RIDX(i+3, (j+1), dim)].green;
            dst[RIDX(dim-1-(j+1), i+3, dim)].blue  = src[RIDX(i+3, (j+1), dim)].blue;

            //first i, third j
            dst[RIDX(dim-1-(j+2), i, dim)].red   = src[RIDX(i, (j+2), dim)].red;
            dst[RIDX(dim-1-(j+2), i, dim)].green = src[RIDX(i, (j+2), dim)].green;
            dst[RIDX(dim-1-(j+2), i, dim)].blue  = src[RIDX(i, (j+2), dim)].blue;
            //second i, third j
            dst[RIDX(dim-1-(j+2), i+1, dim)].red   = src[RIDX(i+1, (j+2), dim)].red;
            dst[RIDX(dim-1-(j+2), i+1, dim)].green = src[RIDX(i+1, (j+2), dim)].green;
            dst[RIDX(dim-1-(j+2), i+1, dim)].blue  = src[RIDX(i+1, (j+2), dim)].blue;
            //third i, third j
            dst[RIDX(dim-1-(j+2), i+2, dim)].red   = src[RIDX(i+2, (j+2), dim)].red;
            dst[RIDX(dim-1-(j+2), i+2, dim)].green = src[RIDX(i+2, (j+2), dim)].green;
            dst[RIDX(dim-1-(j+2), i+2, dim)].blue  = src[RIDX(i+2, (j+2), dim)].blue;
            //fourth i, third j
            dst[RIDX(dim-1-(j+2), i+3, dim)].red   = src[RIDX(i+3, (j+2), dim)].red;
            dst[RIDX(dim-1-(j+2), i+3, dim)].green = src[RIDX(i+3, (j+2), dim)].green;
            dst[RIDX(dim-1-(j+2), i+3, dim)].blue  = src[RIDX(i+3, (j+2), dim)].blue;

            //first i, fourth j
            dst[RIDX(dim-1-(j+3), i, dim)].red   = src[RIDX(i, (j+3), dim)].red;
            dst[RIDX(dim-1-(j+3), i, dim)].green = src[RIDX(i, (j+3), dim)].green;
            dst[RIDX(dim-1-(j+3), i, dim)].blue  = src[RIDX(i, (j+3), dim)].blue;
            //second i, fourth j
            dst[RIDX(dim-1-(j+3), i+1, dim)].red   = src[RIDX(i+1, (j+3), dim)].red;
            dst[RIDX(dim-1-(j+3), i+1, dim)].green = src[RIDX(i+1, (j+3), dim)].green;
            dst[RIDX(dim-1-(j+3), i+1, dim)].blue  = src[RIDX(i+1, (j+3), dim)].blue;
            //third i, fourth j
            dst[RIDX(dim-1-(j+3), i+2, dim)].red   = src[RIDX(i+2, (j+3), dim)].red;
            dst[RIDX(dim-1-(j+3), i+2, dim)].green = src[RIDX(i+2, (j+3), dim)].green;
            dst[RIDX(dim-1-(j+3), i+2, dim)].blue  = src[RIDX(i+2, (j+3), dim)].blue;
            //fourth i, fourth j
            dst[RIDX(dim-1-(j+3), i+3, dim)].red   = src[RIDX(i+3, (j+3), dim)].red;
            dst[RIDX(dim-1-(j+3), i+3, dim)].green = src[RIDX(i+3, (j+3), dim)].green;
            dst[RIDX(dim-1-(j+3), i+3, dim)].blue  = src[RIDX(i+3, (j+3), dim)].blue;
        }// for i
    }// for j
}// new_rotate_10
/**********************/

/*
 * new_rotate11 - Ninth new version of rotate with 4 actions in loop
 */
char new_rotate11_descr[] = "new_rotate_11: 8 actions in loop with code motion";
void new_rotate11(int dim, pixel *src, pixel *dst)
{
    int i, j, a, b, c, d, e, f;
    for (i = 0; i < dim; i+=4){
        a = (i+1);
        b = (i+2);
        c = (i+3);
        for (j = 0; j < dim; j+=4){
            d = (j+1);
            e = (j+2);
            f = (j+3);
            //first i, first j
            dst[RIDX(dim-1-j, i, dim)].red   = src[RIDX(i, j, dim)].red;
            dst[RIDX(dim-1-j, i, dim)].green = src[RIDX(i, j, dim)].green;
            dst[RIDX(dim-1-j, i, dim)].blue  = src[RIDX(i, j, dim)].blue;
            //second i, first j
            dst[RIDX(dim-1-j, a, dim)].red   = src[RIDX(a, j, dim)].red;
            dst[RIDX(dim-1-j, a, dim)].green = src[RIDX(a, j, dim)].green;
            dst[RIDX(dim-1-j, a, dim)].blue  = src[RIDX(a, j, dim)].blue;
            //third i, first j
            dst[RIDX(dim-1-j, b, dim)].red   = src[RIDX(b, j, dim)].red;
            dst[RIDX(dim-1-j, b, dim)].green = src[RIDX(b, j, dim)].green;
            dst[RIDX(dim-1-j, b, dim)].blue  = src[RIDX(b, j, dim)].blue;
            //fourth i, first j
            dst[RIDX(dim-1-j, c, dim)].red   = src[RIDX(c, j, dim)].red;
            dst[RIDX(dim-1-j, c, dim)].green = src[RIDX(c, j, dim)].green;
            dst[RIDX(dim-1-j, c, dim)].blue  = src[RIDX(c, j, dim)].blue;

            //first i, second j
            dst[RIDX(dim-1-(d), i, dim)].red   = src[RIDX(i, (d), dim)].red;
            dst[RIDX(dim-1-(d), i, dim)].green = src[RIDX(i, (d), dim)].green;
            dst[RIDX(dim-1-(d), i, dim)].blue  = src[RIDX(i, (d), dim)].blue;
            //second i, second j
            dst[RIDX(dim-1-(d), a, dim)].red   = src[RIDX(a, (d), dim)].red;
            dst[RIDX(dim-1-(d), a, dim)].green = src[RIDX(a, (d), dim)].green;
            dst[RIDX(dim-1-(d), a, dim)].blue  = src[RIDX(a, (d), dim)].blue;
            //third i, second j
            dst[RIDX(dim-1-(d), b, dim)].red   = src[RIDX(b, (d), dim)].red;
            dst[RIDX(dim-1-(d), b, dim)].green = src[RIDX(b, (d), dim)].green;
            dst[RIDX(dim-1-(d), b, dim)].blue  = src[RIDX(b, (d), dim)].blue;
            //fourth i, second j
            dst[RIDX(dim-1-(d), c, dim)].red   = src[RIDX(c, (d), dim)].red;
            dst[RIDX(dim-1-(d), c, dim)].green = src[RIDX(c, (d), dim)].green;
            dst[RIDX(dim-1-(d), c, dim)].blue  = src[RIDX(c, (d), dim)].blue;

            //first i, third j
            dst[RIDX(dim-1-(e), i, dim)].red   = src[RIDX(i, (e), dim)].red;
            dst[RIDX(dim-1-(e), i, dim)].green = src[RIDX(i, (e), dim)].green;
            dst[RIDX(dim-1-(e), i, dim)].blue  = src[RIDX(i, (e), dim)].blue;
            //second i, third j
            dst[RIDX(dim-1-(e), a, dim)].red   = src[RIDX(a, (e), dim)].red;
            dst[RIDX(dim-1-(e), a, dim)].green = src[RIDX(a, (e), dim)].green;
            dst[RIDX(dim-1-(e), a, dim)].blue  = src[RIDX(a, (e), dim)].blue;
            //third i, third j
            dst[RIDX(dim-1-(e), b, dim)].red   = src[RIDX(b, (e), dim)].red;
            dst[RIDX(dim-1-(e), b, dim)].green = src[RIDX(b, (e), dim)].green;
            dst[RIDX(dim-1-(e), b, dim)].blue  = src[RIDX(b, (e), dim)].blue;
            //fourth i, third j
            dst[RIDX(dim-1-(e), c, dim)].red   = src[RIDX(c, (e), dim)].red;
            dst[RIDX(dim-1-(e), c, dim)].green = src[RIDX(c, (e), dim)].green;
            dst[RIDX(dim-1-(e), c, dim)].blue  = src[RIDX(c, (e), dim)].blue;

            //first i, fourth j
            dst[RIDX(dim-1-(f), i, dim)].red   = src[RIDX(i, (f), dim)].red;
            dst[RIDX(dim-1-(f), i, dim)].green = src[RIDX(i, (f), dim)].green;
            dst[RIDX(dim-1-(f), i, dim)].blue  = src[RIDX(i, (f), dim)].blue;
            //second i, fourth j
            dst[RIDX(dim-1-(f), a, dim)].red   = src[RIDX(a, (f), dim)].red;
            dst[RIDX(dim-1-(f), a, dim)].green = src[RIDX(a, (f), dim)].green;
            dst[RIDX(dim-1-(f), a, dim)].blue  = src[RIDX(a, (f), dim)].blue;
            //third i, fourth j
            dst[RIDX(dim-1-(f), b, dim)].red   = src[RIDX(b, (f), dim)].red;
            dst[RIDX(dim-1-(f), b, dim)].green = src[RIDX(b, (f), dim)].green;
            dst[RIDX(dim-1-(f), b, dim)].blue  = src[RIDX(b, (f), dim)].blue;
            //fourth i, fourth j
            dst[RIDX(dim-1-(f), c, dim)].red   = src[RIDX(c, (f), dim)].red;
            dst[RIDX(dim-1-(f), c, dim)].green = src[RIDX(c, (f), dim)].green;
            dst[RIDX(dim-1-(f), c, dim)].blue  = src[RIDX(c, (f), dim)].blue;
        }// for i
    }// for j
}// new_rotate_11
/**********************/

/**********************/
/*
 * new_rotate_12 - Twelth new version of rotate with 16 actions in loop
 */
char new_rotate12_descr[] = "new_rotate12: 12th new version of rotate with 16 actions in loop and external indices";
void new_rotate12(int dim, pixel *src, pixel *dst)
{
    int i, j;
    for (i = 0; i < dim; i+=4){
        int iOne=i+1;
        int iTwo=i+2;
        int iThree=i+3;
        for (j = 0; j < dim; j+=4){
            int jOne=j+1;
            int jTwo=j+2;
            int jThree=j+3;
            int first=dim-1-j;
            int second=dim-1-(jOne);
            int third=dim-1-(jTwo);
            int fourth=dim-1-(jThree);
            //first i, first j
            dst[RIDX(first, i, dim)].red   = src[RIDX(i, j, dim)].red;
            dst[RIDX(first, i, dim)].green = src[RIDX(i, j, dim)].green;
            dst[RIDX(first, i, dim)].blue  = src[RIDX(i, j, dim)].blue;
            //second i, first j
            dst[RIDX(first, iOne, dim)].red   = src[RIDX(iOne, j, dim)].red;
            dst[RIDX(first, iOne, dim)].green = src[RIDX(iOne, j, dim)].green;
            dst[RIDX(first, iOne, dim)].blue  = src[RIDX(iOne, j, dim)].blue;
            //third i, first j
            dst[RIDX(first, iTwo, dim)].red   = src[RIDX(iTwo, j, dim)].red;
            dst[RIDX(first, iTwo, dim)].green = src[RIDX(iTwo, j, dim)].green;
            dst[RIDX(first, iTwo, dim)].blue  = src[RIDX(iTwo, j, dim)].blue;
            //fourth i, first j
            dst[RIDX(first, iThree, dim)].red   = src[RIDX(iThree, j, dim)].red;
            dst[RIDX(first, iThree, dim)].green = src[RIDX(iThree, j, dim)].green;
            dst[RIDX(first, iThree, dim)].blue  = src[RIDX(iThree, j, dim)].blue;

            //first i, second j
            dst[RIDX(second, i, dim)].red   = src[RIDX(i, (jOne), dim)].red;
            dst[RIDX(second, i, dim)].green = src[RIDX(i, (jOne), dim)].green;
            dst[RIDX(second, i, dim)].blue  = src[RIDX(i, (jOne), dim)].blue;
            //second i, second j
            dst[RIDX(second, iOne, dim)].red   = src[RIDX(iOne, (jOne), dim)].red;
            dst[RIDX(second, iOne, dim)].green = src[RIDX(iOne, (jOne), dim)].green;
            dst[RIDX(second, iOne, dim)].blue  = src[RIDX(iOne, (jOne), dim)].blue;
            //third i, second j
            dst[RIDX(second, iTwo, dim)].red   = src[RIDX(iTwo, (jOne), dim)].red;
            dst[RIDX(second, iTwo, dim)].green = src[RIDX(iTwo, (jOne), dim)].green;
            dst[RIDX(second, iTwo, dim)].blue  = src[RIDX(iTwo, (jOne), dim)].blue;
            //fourth i, second j
            dst[RIDX(second, iThree, dim)].red   = src[RIDX(iThree, (jOne), dim)].red;
            dst[RIDX(second, iThree, dim)].green = src[RIDX(iThree, (jOne), dim)].green;
            dst[RIDX(second, iThree, dim)].blue  = src[RIDX(iThree, (jOne), dim)].blue;

             //first i, third j
            dst[RIDX(third, i, dim)].red   = src[RIDX(i, (jTwo), dim)].red;
            dst[RIDX(third, i, dim)].blue  = src[RIDX(i, (jTwo), dim)].blue;
            dst[RIDX(third, i, dim)].green = src[RIDX(i, (jTwo), dim)].green;
            //second i, third j
            dst[RIDX(third, iOne, dim)].red   = src[RIDX(iOne, (jTwo), dim)].red;
            dst[RIDX(third, iOne, dim)].green = src[RIDX(iOne, (jTwo), dim)].green;
            dst[RIDX(third, iOne, dim)].blue  = src[RIDX(iOne, (jTwo), dim)].blue;
            //third i, third j
            dst[RIDX(third, iTwo, dim)].red   = src[RIDX(iTwo, (jTwo), dim)].red;
            dst[RIDX(third, iTwo, dim)].green = src[RIDX(iTwo, (jTwo), dim)].green;
            dst[RIDX(third, iTwo, dim)].blue  = src[RIDX(iTwo, (jTwo), dim)].blue;
            //fourth i, third j
            dst[RIDX(third, iThree, dim)].red   = src[RIDX(iThree, (jTwo), dim)].red;
            dst[RIDX(third, iThree, dim)].green = src[RIDX(iThree, (jTwo), dim)].green;
            dst[RIDX(third, iThree, dim)].blue  = src[RIDX(iThree, (jTwo), dim)].blue;

            //first i, fourth j
            dst[RIDX(fourth, i, dim)].red   = src[RIDX(i, (jThree), dim)].red;
            dst[RIDX(fourth, i, dim)].green = src[RIDX(i, (jThree), dim)].green;
            dst[RIDX(fourth, i, dim)].blue  = src[RIDX(i, (jThree), dim)].blue;
            //second i, fourth j
            dst[RIDX(fourth, iOne, dim)].red   = src[RIDX(iOne, (jThree), dim)].red;
            dst[RIDX(fourth, iOne, dim)].green = src[RIDX(iOne, (jThree), dim)].green;
            dst[RIDX(fourth, iOne, dim)].blue  = src[RIDX(iOne, (jThree), dim)].blue;
            //third i, fourth j
            dst[RIDX(fourth, iTwo, dim)].red   = src[RIDX(iTwo, (jThree), dim)].red;
            dst[RIDX(fourth, iTwo, dim)].green = src[RIDX(iTwo, (jThree), dim)].green;
            dst[RIDX(fourth, iTwo, dim)].blue  = src[RIDX(iTwo, (jThree), dim)].blue;
            //fourth i,fourth j
            dst[RIDX(fourth, iThree, dim)].red   = src[RIDX(iThree, (jThree), dim)].red;
            dst[RIDX(fourth, iThree, dim)].green = src[RIDX(iThree, (jThree), dim)].green;
            dst[RIDX(fourth, iThree, dim)].blue  = src[RIDX(iThree, (jThree), dim)].blue;
        }// for j
    }// for i
}// new_rotate_12
/**********************/

/**********************/
/*
 * new_rotate_13 - 13th new version of rotate with 16 actions in loop
 */
char new_rotate13_descr[] = "new_rotate13: 13th new version of rotate with 16 actions in loop and external indices";
void new_rotate13(int dim, pixel *src, pixel *dst)
{
    int i, j;
    for (i = 0; i < dim; i+=8){
        int iOne=i+1;
        int iTwo=i+2;
        int iThree=i+3;
        int iFour=i+4;
        int iFive=i+5;
        int iSix=i+6;
        int iSeven=i+7;
        for (j = 0; j < dim; j+=4){
            int jOne=j+1;
            int jTwo=j+2;
            int jThree=j+3;
            int first=dim-1-j;
            int second=dim-1-(jOne);
            int third=dim-1-(jTwo);
            int fourth=dim-1-(jThree);
            //first i, first j
            dst[RIDX(first, i, dim)].red   = src[RIDX(i, j, dim)].red;
            dst[RIDX(first, i, dim)].green = src[RIDX(i, j, dim)].green;
            dst[RIDX(first, i, dim)].blue  = src[RIDX(i, j, dim)].blue;
            //second i, first j
            dst[RIDX(first, iOne, dim)].red   = src[RIDX(iOne, j, dim)].red;
            dst[RIDX(first, iOne, dim)].green = src[RIDX(iOne, j, dim)].green;
            dst[RIDX(first, iOne, dim)].blue  = src[RIDX(iOne, j, dim)].blue;
            //third i, first j
            dst[RIDX(first, iTwo, dim)].red   = src[RIDX(iTwo, j, dim)].red;
            dst[RIDX(first, iTwo, dim)].green = src[RIDX(iTwo, j, dim)].green;
            dst[RIDX(first, iTwo, dim)].blue  = src[RIDX(iTwo, j, dim)].blue;
            //fourth i, first j
            dst[RIDX(first, iThree, dim)].red   = src[RIDX(iThree, j, dim)].red;
            dst[RIDX(first, iThree, dim)].green = src[RIDX(iThree, j, dim)].green;
            dst[RIDX(first, iThree, dim)].blue  = src[RIDX(iThree, j, dim)].blue;
            //******************************
            //fifth i, first j
            dst[RIDX(first, iFour, dim)].red   = src[RIDX(iFour, j, dim)].red;
            dst[RIDX(first, iFour, dim)].green = src[RIDX(iFour, j, dim)].green;
            dst[RIDX(first, iFour, dim)].blue  = src[RIDX(iFour, j, dim)].blue;
            //sixth i, first j
            dst[RIDX(first, iFive, dim)].red   = src[RIDX(iFive, j, dim)].red;
            dst[RIDX(first, iFive, dim)].green = src[RIDX(iFive, j, dim)].green;
            dst[RIDX(first, iFive, dim)].blue  = src[RIDX(iFive, j, dim)].blue;
            //seventh i, first j
            dst[RIDX(first, iSix, dim)].red   = src[RIDX(iSix, j, dim)].red;
            dst[RIDX(first, iSix, dim)].green = src[RIDX(iSix, j, dim)].green;
            dst[RIDX(first, iSix, dim)].blue  = src[RIDX(iSix, j, dim)].blue;
            //eighth i, first j
            dst[RIDX(first, iSeven, dim)].red   = src[RIDX(iSeven, j, dim)].red;
            dst[RIDX(first, iSeven, dim)].green = src[RIDX(iSeven, j, dim)].green;
            dst[RIDX(first, iSeven, dim)].blue  = src[RIDX(iSeven, j, dim)].blue;
            //******************************
            //first i, second j
            dst[RIDX(second, i, dim)].red   = src[RIDX(i, (jOne), dim)].red;
            dst[RIDX(second, i, dim)].green = src[RIDX(i, (jOne), dim)].green;
            dst[RIDX(second, i, dim)].blue  = src[RIDX(i, (jOne), dim)].blue;
            //second i, second j
            dst[RIDX(second, iOne, dim)].red   = src[RIDX(iOne, (jOne), dim)].red;
            dst[RIDX(second, iOne, dim)].green = src[RIDX(iOne, (jOne), dim)].green;
            dst[RIDX(second, iOne, dim)].blue  = src[RIDX(iOne, (jOne), dim)].blue;
            //third i, second j
            dst[RIDX(second, iTwo, dim)].red   = src[RIDX(iTwo, (jOne), dim)].red;
            dst[RIDX(second, iTwo, dim)].green = src[RIDX(iTwo, (jOne), dim)].green;
            dst[RIDX(second, iTwo, dim)].blue  = src[RIDX(iTwo, (jOne), dim)].blue;
            //fourth i, second j
            dst[RIDX(second, iThree, dim)].red   = src[RIDX(iThree, (jOne), dim)].red;
            dst[RIDX(second, iThree, dim)].green = src[RIDX(iThree, (jOne), dim)].green;
            dst[RIDX(second, iThree, dim)].blue  = src[RIDX(iThree, (jOne), dim)].blue;
            //******************************
            //fifth i, second j
            dst[RIDX(second, iFour, dim)].red   = src[RIDX(iFour, (jOne), dim)].red;
            dst[RIDX(second, iFour, dim)].green = src[RIDX(iFour, (jOne), dim)].green;
            dst[RIDX(second, iFour, dim)].blue  = src[RIDX(iFour, (jOne), dim)].blue;
            //sixth i, second j
            dst[RIDX(second, iFive, dim)].red   = src[RIDX(iFive, (jOne), dim)].red;
            dst[RIDX(second, iFive, dim)].green = src[RIDX(iFive, (jOne), dim)].green;
            dst[RIDX(second, iFive, dim)].blue  = src[RIDX(iFive, (jOne), dim)].blue;
            //seventh i, second j
            dst[RIDX(second, iSix, dim)].red   = src[RIDX(iSix, (jOne), dim)].red;
            dst[RIDX(second, iSix, dim)].green = src[RIDX(iSix, (jOne), dim)].green;
            dst[RIDX(second, iSix, dim)].blue  = src[RIDX(iSix, (jOne), dim)].blue;
            //eighth i, second j
            dst[RIDX(second, iSeven, dim)].red   = src[RIDX(iSeven, (jOne), dim)].red;
            dst[RIDX(second, iSeven, dim)].green = src[RIDX(iSeven, (jOne), dim)].green;
            dst[RIDX(second, iSeven, dim)].blue  = src[RIDX(iSeven, (jOne), dim)].blue;
            //******************************
             //first i, third j
            dst[RIDX(third, i, dim)].red   = src[RIDX(i, (jTwo), dim)].red;
            dst[RIDX(third, i, dim)].blue  = src[RIDX(i, (jTwo), dim)].blue;
            dst[RIDX(third, i, dim)].green = src[RIDX(i, (jTwo), dim)].green;
            //second i, third j
            dst[RIDX(third, iOne, dim)].red   = src[RIDX(iOne, (jTwo), dim)].red;
            dst[RIDX(third, iOne, dim)].green = src[RIDX(iOne, (jTwo), dim)].green;
            dst[RIDX(third, iOne, dim)].blue  = src[RIDX(iOne, (jTwo), dim)].blue;
            //third i, third j
            dst[RIDX(third, iTwo, dim)].red   = src[RIDX(iTwo, (jTwo), dim)].red;
            dst[RIDX(third, iTwo, dim)].green = src[RIDX(iTwo, (jTwo), dim)].green;
            dst[RIDX(third, iTwo, dim)].blue  = src[RIDX(iTwo, (jTwo), dim)].blue;
            //fourth i, third j
            dst[RIDX(third, iThree, dim)].red   = src[RIDX(iThree, (jTwo), dim)].red;
            dst[RIDX(third, iThree, dim)].green = src[RIDX(iThree, (jTwo), dim)].green;
            dst[RIDX(third, iThree, dim)].blue  = src[RIDX(iThree, (jTwo), dim)].blue;
            //*******************************
            //fifth i, third j
            dst[RIDX(third, iFour, dim)].red   = src[RIDX(iFour, (jTwo), dim)].red;
            dst[RIDX(third, iFour, dim)].blue  = src[RIDX(iFour, (jTwo), dim)].blue;
            dst[RIDX(third, iFour, dim)].green = src[RIDX(iFour, (jTwo), dim)].green;
            //sixth i, third j
            dst[RIDX(third, iFive, dim)].red   = src[RIDX(iFive, (jTwo), dim)].red;
            dst[RIDX(third, iFive, dim)].green = src[RIDX(iFive, (jTwo), dim)].green;
            dst[RIDX(third, iFive, dim)].blue  = src[RIDX(iFive, (jTwo), dim)].blue;
            //seventh i, third j
            dst[RIDX(third, iSix, dim)].red   = src[RIDX(iSix, (jTwo), dim)].red;
            dst[RIDX(third, iSix, dim)].green = src[RIDX(iSix, (jTwo), dim)].green;
            dst[RIDX(third, iSix, dim)].blue  = src[RIDX(iSix, (jTwo), dim)].blue;
            //eighth i, third j
            dst[RIDX(third, iSeven, dim)].red   = src[RIDX(iSeven, (jTwo), dim)].red;
            dst[RIDX(third, iSeven, dim)].green = src[RIDX(iSeven, (jTwo), dim)].green;
            dst[RIDX(third, iSeven, dim)].blue  = src[RIDX(iSeven, (jTwo), dim)].blue;
            //***************************
            //first i, fourth j
            dst[RIDX(fourth, i, dim)].red   = src[RIDX(i, (jThree), dim)].red;
            dst[RIDX(fourth, i, dim)].green = src[RIDX(i, (jThree), dim)].green;
            dst[RIDX(fourth, i, dim)].blue  = src[RIDX(i, (jThree), dim)].blue;
            //second i, fourth j
            dst[RIDX(fourth, iOne, dim)].red   = src[RIDX(iOne, (jThree), dim)].red;
            dst[RIDX(fourth, iOne, dim)].green = src[RIDX(iOne, (jThree), dim)].green;
            dst[RIDX(fourth, iOne, dim)].blue  = src[RIDX(iOne, (jThree), dim)].blue;
            //third i, fourth j
            dst[RIDX(fourth, iTwo, dim)].red   = src[RIDX(iTwo, (jThree), dim)].red;
            dst[RIDX(fourth, iTwo, dim)].green = src[RIDX(iTwo, (jThree), dim)].green;
            dst[RIDX(fourth, iTwo, dim)].blue  = src[RIDX(iTwo, (jThree), dim)].blue;
            //fourth i,fourth j
            dst[RIDX(fourth, iThree, dim)].red   = src[RIDX(iThree, (jThree), dim)].red;
            dst[RIDX(fourth, iThree, dim)].green = src[RIDX(iThree, (jThree), dim)].green;
            dst[RIDX(fourth, iThree, dim)].blue  = src[RIDX(iThree, (jThree), dim)].blue;
            //*******************************
            //fifth i, fourth j
            dst[RIDX(fourth, iFour, dim)].red   = src[RIDX(iFour, (jThree), dim)].red;
            dst[RIDX(fourth, iFour, dim)].green = src[RIDX(iFour, (jThree), dim)].green;
            dst[RIDX(fourth, iFour, dim)].blue  = src[RIDX(iFour, (jThree), dim)].blue;
            //sixth i, fourth j
            dst[RIDX(fourth, iFive, dim)].red   = src[RIDX(iFive, (jThree), dim)].red;
            dst[RIDX(fourth, iFive, dim)].green = src[RIDX(iFive, (jThree), dim)].green;
            dst[RIDX(fourth, iFive, dim)].blue  = src[RIDX(iFive, (jThree), dim)].blue;
            //seventh i, fourth j
            dst[RIDX(fourth, iSix, dim)].red   = src[RIDX(iSix, (jThree), dim)].red;
            dst[RIDX(fourth, iSix, dim)].green = src[RIDX(iSix, (jThree), dim)].green;
            dst[RIDX(fourth, iSix, dim)].blue  = src[RIDX(iSix, (jThree), dim)].blue;
            //eighth i,fourth j
            dst[RIDX(fourth, iSeven, dim)].red   = src[RIDX(iSeven, (jThree), dim)].red;
            dst[RIDX(fourth, iSeven, dim)].green = src[RIDX(iSeven, (jThree), dim)].green;
            dst[RIDX(fourth, iSeven, dim)].blue  = src[RIDX(iSeven, (jThree), dim)].blue;
        }// for j
    }// for i
}// new_rotate_13
/**********************/

/*
 * new_rotate_14 - Twelth new version of rotate with 16 actions in loop
 */
char new_rotate14_descr[] = "new_rotate14: 14th new version with i to 16, j++--parallelism, code motion, and less calls to RIDX";
void new_rotate14(int dim, pixel *src, pixel *dst)
{
    int i, j, newDim, newDimI, iOne, iTwo, iThree, iFour, iFive, iSix, iSeven, iEight, iNine, iTen, iEleven, iTwelve, iThirteen, iFourteen, iFifteen;
    for (i = 0; i < dim; i+=16){
        iOne=i+1;
        iTwo=i+2;
        iThree=i+3;
        iFour=i+4;
        iFive=i+5;
        iSix=i+6;
        iSeven=i+7;
        iEight=i+8;
        iNine=i+9;
        iTen=i+10;
        iEleven=i+11;
        iTwelve=i+12;
        iThirteen=i+13;
        iFourteen=i+14;
        iFifteen=i+15;
        for (j = 0; j < dim; j++){
            newDim = (dim - 1 -j)*dim;
            newDimI = newDim + i;
            dst[newDimI] = src[i * dim + j];
            dst[newDimI + 1] = src[iOne * dim + j];
            dst[newDimI + 2] = src[iTwo * dim + j];
            dst[newDimI + 3] = src[iThree * dim + j];
            dst[newDimI + 4] = src[iFour * dim + j];
            dst[newDimI + 5] = src[iFive * dim + j];
            dst[newDimI + 6] = src[iSix * dim + j];
            dst[newDimI + 7] = src[iSeven * dim + j];
            dst[newDimI + 8] = src[iEight * dim + j];
            dst[newDimI + 9] = src[iNine * dim + j];
            dst[newDimI + 10] = src[iTen * dim + j];
            dst[newDimI + 11] = src[iEleven * dim + j];
            dst[newDimI + 12] = src[iTwelve * dim + j];
            dst[newDimI + 13] = src[iThirteen * dim + j];
            dst[newDimI + 14] = src[iFourteen * dim + j];
            dst[newDimI + 15] = src[iFifteen * dim + j];
        }// for j
    }// for i
}// new_rotate_14

/**********************/
/*
 * new_rotate_15 - Fifteenth new version of rotate with 16 actions in loop
 */
char new_rotate15_descr[] = "new_rotate_15: Tenth new version of rotate with 16 actions in loop";
void new_rotate15(int dim, pixel *src, pixel *dst)
{
    int i, j;
    int a1,b1,c1,d1,A1,B1,C1,D1;
    int a2,b2,c2,d2,A2,B2,C2,D2;
    int a3,b3,c3,d3,A3,B3,C3,D3;
    int a4,b4,c4,d4,A4,B4,C4,D4;

    for (i = 0; i < dim; i+=4){
        for (j = 0; j < dim; j+=4){

            a1=RIDX(dim-1-j, i, dim);
            b1=a1+1;
            c1=b1+1;
            d1=c1+1;
            A1=RIDX(i, j, dim);
            B1=A1+dim;
            C1=B1+dim;
            D1=C1+dim;

            a2=RIDX(dim-1-(j+1), i, dim);
            b2=a2+1;
            c2=b2+1;
            d2=c2+1;
            A2=RIDX(i, j+1, dim);
            B2=A2+dim;
            C2=B2+dim;
            D2=C2+dim;

            a3=RIDX(dim-1-(j+2), i, dim);
            b3=a3+1;
            c3=b3+1;
            d3=c3+1;
            A3=RIDX(i, (j+2), dim);
            B3=A3+dim;
            C3=B3+dim;
            D3=C3+dim;

            a4=RIDX(dim-1-(j+3), i, dim);
            b4=a4+1;
            c4=b4+1;
            d4=c4+1;
            A4=RIDX(i, (j+3), dim);
            B4=A4+dim;
            C4=B4+dim;
            D4=C4+dim;

            dst[a1] = src[A1];
            dst[b1] = src[B1];
            dst[c1] = src[C1];
            dst[d1] = src[D1];

            dst[a2] = src[A2];
            dst[b2] = src[B2];
            dst[c2] = src[C2];
            dst[d2] = src[D2];

            dst[a3] = src[A3];
            dst[b3] = src[B3];
            dst[c3] = src[C3];
            dst[d3] = src[D3];

            dst[a4] = src[A4];
            dst[b4] = src[B4];
            dst[c4] = src[C4];
            dst[d4] = src[D4];
        }// for j
    }// for i
}// new_rotate_15
/**********************/

/*
 * naive_rotate - The naive baseline version of rotate
 */
char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel *src, pixel *dst)
{
    int i, j;
    for (i = 0; i < dim; i++){
        for (j = 0; j < dim; j++){
            dst[RIDX(dim-1-j, i, dim)].red   = src[RIDX(i, j, dim)].red;
            dst[RIDX(dim-1-j, i, dim)].green = src[RIDX(i, j, dim)].green;
            dst[RIDX(dim-1-j, i, dim)].blue  = src[RIDX(i, j, dim)].blue;
        }
    }
}

/*
 * rotate - Your current working version of rotate
 * IMPORTANT: This is the version you will be graded on
 */
char rotate_descr[] = "rotate: Current working version";
void rotate(int dim, pixel *src, pixel *dst)
{
    //naive_rotate(dim, src, dst);
    //new_rotate1(dim, src, dst);
    //new_rotate2(dim, src, dst);
    //new_rotate3(dim, src, dst);
    new_rotate14(dim, src, dst);
    //new_rotate5(dim, src, dst);
    //new_rotate6(dim, src, dst);

}

/*********************************************************************
 * register_rotate_functions - Register all of your different versions
 *     of the rotate kernel with the driver by calling the
 *     add_rotate_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 *********************************************************************/

void register_rotate_functions()
{
    add_rotate_function(&naive_rotate, naive_rotate_descr);
    /*add_rotate_function(&new_rotate1, new_rotate1_descr);
    add_rotate_function(&new_rotate2, new_rotate2_descr);
    add_rotate_function(&new_rotate3, new_rotate3_descr);
    add_rotate_function(&new_rotate4, new_rotate4_descr);
    add_rotate_function(&new_rotate5, new_rotate5_descr);
    add_rotate_function(&new_rotate6, new_rotate6_descr);
    add_rotate_function(&new_rotate7, new_rotate7_descr);
    add_rotate_function(&new_rotate8, new_rotate8_descr);
    add_rotate_function(&new_rotate9, new_rotate9_descr);
    add_rotate_function(&new_rotate10, new_rotate10_descr);
    add_rotate_function(&new_rotate11, new_rotate11_descr);
    add_rotate_function(&new_rotate12, new_rotate12_descr);
    add_rotate_function(&new_rotate13, new_rotate13_descr);*/
    //add_rotate_function(&new_rotate14, new_rotate14_descr);
    //add_rotate_function(&new_rotate15, new_rotate15_descr);





    /*for (int i = 0; i<10;i++){
        add_rotate_function(&new_rotate15, new_rotate15_descr);
    }*/


    add_rotate_function(&rotate, rotate_descr);
    /* ... Register additional test functions here */
}


/***************
 * SMOOTH KERNEL
 **************/

/***************************************************************
 * Various typedefs and helper functions for the smooth function
 * You may modify these any way you like.
 **************************************************************/

/* Compute min of two integers */
static int min(int a, int b) {
    if(a<b){
        return a;
    }else{
        return b;
    }
}

/* Compute max of two integers */
static int max(int a, int b) {
    if(a>b){
        return a;
    }else{
        return b;
    }
}

/* A struct used to compute averaged pixel value */
typedef struct {
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    unsigned int num;
} pixel_sum;

/*
 * initialize_pixel_sum - Initializes all fields of sum to 0
 */
static void initialize_pixel_sum(pixel_sum *sum){
    sum->red = 0;
    sum->green = 0;
    sum->blue = 0;
    sum->num = 0;
}

static void accumulate_sum(pixel_sum *sum, pixel p){
    sum->red += (unsigned int) p.red;
    sum->green += (unsigned int) p.green;
    sum->blue += (unsigned int) p.blue;
    sum->num++;
}
/******************************************************
 * Your different versions of the smooth kernel go here
 ******************************************************/

/*
 * naive_smooth - The naive baseline version of smooth
 */
char naive_smooth_descr[] = "naive_smooth: Naive baseline implementation";
void naive_smooth(int dim, pixel *src, pixel *dst)
{
    int i, j, ii, jj;
    pixel_sum ps;

    for (j = 0; j < dim; j++){
        for (i = 0; i < dim; i++){
            initialize_pixel_sum(&ps);
            for(ii = max(i-1, 0); ii <= min(i+1, dim-1); ii++){
                for(jj = max(j-1, 0); jj <= min(j+1, dim-1); jj++){
                    accumulate_sum(&ps, src[RIDX(ii,jj,dim)]);
                }
            }
            dst[RIDX(i,j,dim)].red   = ps.red/ps.num;
            dst[RIDX(i,j,dim)].green = ps.green/ps.num;
            dst[RIDX(i,j,dim)].blue  = ps.blue/ps.num;
        }
    }
}

/*
 * naive_smooth - The naive baseline version of smooth
 */
char new_smooth1_descr[] = "new_smooth1: change to i first, removed calls to RIDX and replaced with var. ";
void new_smooth1(int dim, pixel *src, pixel *dst)
{
    int i, j, ii, jj, index,iTimesDim, iiTimesDim;
    pixel_sum ps;

    for (i = 0; i < dim; i++){
        iTimesDim = i * dim;
        for (j = 0; j < dim; j++){
            initialize_pixel_sum(&ps);
            for(jj = max(j-1, 0); jj <= min(j+1, dim-1); jj++){
                for(ii = max(i-1, 0); ii <= min(i+1, dim-1); ii++){
                    iiTimesDim = ii * dim;
                    accumulate_sum(&ps, src[(iiTimesDim)+jj]);
                }//end of fourth for
            }//end of third for
            index = (iTimesDim)+j;
            dst[index].red   = ps.red/ps.num;
            dst[index].green = ps.green/ps.num;
            dst[index].blue  = ps.blue/ps.num;
        }//end of second for
    }//end of first for
}//end of smooth1

/**********************/
/*
 * smooth_2 - Second version of smooth
 */
char new_smooth2_descr[] = "new_smooth_2: rearrange pixel math";
void new_smooth2(int dim, pixel *src, pixel *dst)
{
    int i, j, ii, jj, indx1, indx2;
    int iTimesDim, iiTimesDim;
    pixel_sum ps;

    //corners
    //upper left
    //printf("\n");
    //printf("Upper left corner \n");
    i=0;
    j=0;
    iTimesDim=i*dim;
    initialize_pixel_sum(&ps);
    for(ii = i; ii <= i+1; ii++){
        iiTimesDim=ii*dim;
        for(jj = j; jj <= j+1; jj++){
            indx2=iiTimesDim+jj;
            accumulate_sum(&ps, src[indx2]);
            //printf("ii %d jj %d indx2 %d red %d green %d blue %d\n",
                   //ii,jj,indx2,src[indx2].red,src[indx2].green,src[indx2].blue);
        }//for jj
    }//for ii
    indx1=iTimesDim+j;
    dst[indx1].red   = ps.red/ps.num;
    dst[indx1].green = ps.green/ps.num;
    dst[indx1].blue  = ps.blue/ps.num;
    //printf("i %d j %d indx1 %d red %d green %d blue %d\n",
           //i,j,indx1,dst[indx1].red ,dst[indx1].green,dst[indx1].blue);

    //upper right
    //printf("\n");
    //printf("Upper right corner \n");
    i=dim-1;
    j=0;
    iTimesDim=i*dim;
    initialize_pixel_sum(&ps);
    for(ii = i-1; ii <= i; ii++){
        iiTimesDim=ii*dim;
        for(jj = j; jj <= j+1; jj++){
            indx2=iiTimesDim+jj;
            accumulate_sum(&ps, src[indx2]);
            //printf("ii %d jj %d indx2 %d red %d green %d blue %d\n",
                   //ii,jj,indx2,src[indx2].red,src[indx2].green,src[indx2].blue);
        }//for jj
    }//for ii
    indx1=iTimesDim+j;
    dst[indx1].red   = ps.red/ps.num;
    dst[indx1].green = ps.green/ps.num;
    dst[indx1].blue  = ps.blue/ps.num;
    //printf("i %d j %d indx1 %d red %d green %d blue %d\n",
           //i,j,indx1,dst[indx1].red ,dst[indx1].green,dst[indx1].blue);

    //lower left
    //printf("\n");
    //printf("Lower left corner \n");
    i=0;
    j=dim-1;
    iTimesDim=i*dim;
    initialize_pixel_sum(&ps);
    for(ii = i; ii <= i+1; ii++){
        iiTimesDim=ii*dim;
        for(jj = j-1; jj <= j; jj++){
            indx2=iiTimesDim+jj;
            accumulate_sum(&ps, src[indx2]);
            //printf("ii %d jj %d indx2 %d red %d green %d blue %d\n",
                   //ii,jj,indx2,src[indx2].red,src[indx2].green,src[indx2].blue);
        }//for jj
    }//for ii
    indx1=iTimesDim+j;
    dst[indx1].red   = ps.red/ps.num;
    dst[indx1].green = ps.green/ps.num;
    dst[indx1].blue  = ps.blue/ps.num;
    //printf("i %d j %d indx1 %d red %d green %d blue %d\n",
           //i,j,indx1,dst[indx1].red ,dst[indx1].green,dst[indx1].blue);

    //lower right
    //printf("\n");
    //printf("Lower right corner \n");
    i=dim-1;
    j=dim-1;
    iTimesDim=i*dim;
    initialize_pixel_sum(&ps);
    for(ii = i-1; ii <= i; ii++){
        iiTimesDim=ii*dim;
        for(jj = j-1; jj <= j; jj++){
            indx2=iiTimesDim+jj;
            accumulate_sum(&ps, src[indx2]);
            //printf("ii %d jj %d indx2 %d red %d green %d blue %d\n",
                   //ii,jj,indx2,src[indx2].red,src[indx2].green,src[indx2].blue);
        }//for jj
    }//for ii
    indx1=iTimesDim+j;
    dst[indx1].red   = ps.red/ps.num;
    dst[indx1].green = ps.green/ps.num;
    dst[indx1].blue  = ps.blue/ps.num;
    //printf("i %d j %d indx1 %d red %d green %d blue %d\n",
           //i,j,indx1,dst[indx1].red ,dst[indx1].green,dst[indx1].blue);

    //edges
    //left edge (no corners)
    i=0;
    iTimesDim=i*dim;
    for (j = 1; j < dim-1; j++){
        initialize_pixel_sum(&ps);
        for(ii = i; ii <= i+1; ii++){
            iiTimesDim=ii*dim;
            for(jj = j-1; jj <= j+1; jj++){
                indx2=iiTimesDim+jj;
                accumulate_sum(&ps, src[indx2]);
            }//for jj
        }//for ii
        indx1=iTimesDim+j;
        dst[indx1].red   = ps.red/ps.num;
        dst[indx1].green = ps.green/ps.num;
        dst[indx1].blue  = ps.blue/ps.num;
    }// for

    //right edge (no corners)
    i=dim-1;
    iTimesDim=i*dim;
    for (j = 1; j < dim-1; j++){
        initialize_pixel_sum(&ps);
        for(ii = i-1; ii <= i; ii++){
            iiTimesDim=ii*dim;
            for(jj = j-1; jj <= j+1; jj++){
                indx2=iiTimesDim+jj;
                accumulate_sum(&ps, src[indx2]);
            }//for jj
        }//for ii
        indx1=iTimesDim+j;
        dst[indx1].red   = ps.red/ps.num;
        dst[indx1].green = ps.green/ps.num;
        dst[indx1].blue  = ps.blue/ps.num;
    }// for

    //top edge (no corners)
    j=0;
    for (i = 1; i < dim-1; i++){
        iTimesDim=i*dim;
        initialize_pixel_sum(&ps);
        for(ii = i-1; ii <= i+1; ii++){
            iiTimesDim=ii*dim;
            for(jj = j; jj <= j+1; jj++){
                indx2=iiTimesDim+jj;
                accumulate_sum(&ps, src[indx2]);
            }//for jj
        }//for ii
        indx1=iTimesDim+j;
        dst[indx1].red   = ps.red/ps.num;
        dst[indx1].green = ps.green/ps.num;
        dst[indx1].blue  = ps.blue/ps.num;
    }// for i

    //bottom edge (no corners)
    j=dim-1;
    for (i = 1; i < dim-1; i++){
        iTimesDim=i*dim;
        initialize_pixel_sum(&ps);
        for(ii = i-1; ii <= i+1; ii++){
            iiTimesDim=ii*dim;
            for(jj = j-1; jj <= j; jj++){
                indx2=iiTimesDim+jj;
                accumulate_sum(&ps, src[indx2]);
            }//for jj
        }//for ii
        indx1=iTimesDim+j;
        dst[indx1].red   = ps.red/ps.num;
        dst[indx1].green = ps.green/ps.num;
        dst[indx1].blue  = ps.blue/ps.num;
    }// for i

    //middle of image
    for (i = 1; i < dim-1; i++){
        iTimesDim=i*dim;
        for (j = 1; j < dim-1; j++){
            initialize_pixel_sum(&ps);
            for(ii = i-1; ii <= i+1; ii++){
                iiTimesDim=ii*dim;
                for(jj = j-1; jj <= j+1; jj++){
                    indx2=iiTimesDim+jj;
                    accumulate_sum(&ps, src[indx2]);
                }//for jj
            }//for ii
            indx1=iTimesDim+j;
            dst[indx1].red   = ps.red/ps.num;
            dst[indx1].green = ps.green/ps.num;
            dst[indx1].blue  = ps.blue/ps.num;
        }// for j
    }//for i
}//smooth_2
/**********************/

/*
 * smooth_4 - 4th version of smooth
 */
char new_smooth4_descr[] = "new_smooth4: Dropbox uploaded this";
void new_smooth4(int dim, pixel *src, pixel *dst)
{
    int i, j, ii, jj, indx1, indx2, indx3, indx4;
    int iiTimesDimTopRow1, iiTimesDimMidRow1, iiTimesDimBotRow1;
    int iiTimesDimTopRow2, iiTimesDimMidRow2, iiTimesDimBotRow2;
    int iiTimesDimTopRow3, iiTimesDimMidRow3, iiTimesDimBotRow3;
    int iiTimesDimTopRow4, iiTimesDimMidRow4, iiTimesDimBotRow4;

    int iTimesDim, iiTimesDim;
    pixel_sum ps;

    //corners
    //upper left
    //printf("\n");
    //printf("Upper left corner \n");
    i=0;
    j=0;
    iTimesDim=i*dim;
    initialize_pixel_sum(&ps);
    for(ii = i; ii <= i+1; ii++){
        iiTimesDim=ii*dim;
        for(jj = j; jj <= j+1; jj++){
            indx2=iiTimesDim+jj;
            accumulate_sum(&ps, src[indx2]);
            //printf("ii %d jj %d indx2 %d red %d green %d blue %d\n",
                   //ii,jj,indx2,src[indx2].red,src[indx2].green,src[indx2].blue);
        }//for jj
    }//for ii
    indx1=iTimesDim+j;
    dst[indx1].red   = ps.red/ps.num;
    dst[indx1].green = ps.green/ps.num;
    dst[indx1].blue  = ps.blue/ps.num;
    //printf("i %d j %d indx1 %d red %d green %d blue %d\n",
           //i,j,indx1,dst[indx1].red ,dst[indx1].green,dst[indx1].blue);

    //upper right
    //printf("\n");
    //printf("Upper right corner \n");
    i=dim-1;
    j=0;
    iTimesDim=i*dim;
    initialize_pixel_sum(&ps);
    for(ii = i-1; ii <= i; ii++){
        iiTimesDim=ii*dim;
        for(jj = j; jj <= j+1; jj++){
            indx2=iiTimesDim+jj;
            accumulate_sum(&ps, src[indx2]);
            //printf("ii %d jj %d indx2 %d red %d green %d blue %d\n",
                   //ii,jj,indx2,src[indx2].red,src[indx2].green,src[indx2].blue);
        }//for jj
    }//for ii
    indx1=iTimesDim+j;
    dst[indx1].red   = ps.red/ps.num;
    dst[indx1].green = ps.green/ps.num;
    dst[indx1].blue  = ps.blue/ps.num;
    //printf("i %d j %d indx1 %d red %d green %d blue %d\n",
           //i,j,indx1,dst[indx1].red ,dst[indx1].green,dst[indx1].blue);

    //lower left
    //printf("\n");
    //printf("Lower left corner \n");
    i=0;
    j=dim-1;
    iTimesDim=i*dim;
    initialize_pixel_sum(&ps);
    for(ii = i; ii <= i+1; ii++){
        iiTimesDim=ii*dim;
        for(jj = j-1; jj <= j; jj++){
            indx2=iiTimesDim+jj;
            accumulate_sum(&ps, src[indx2]);
            //printf("ii %d jj %d indx2 %d red %d green %d blue %d\n",
                   //ii,jj,indx2,src[indx2].red,src[indx2].green,src[indx2].blue);
        }//for jj
    }//for ii
    indx1=iTimesDim+j;
    dst[indx1].red   = ps.red/ps.num;
    dst[indx1].green = ps.green/ps.num;
    dst[indx1].blue  = ps.blue/ps.num;
    //printf("i %d j %d indx1 %d red %d green %d blue %d\n",
           //i,j,indx1,dst[indx1].red ,dst[indx1].green,dst[indx1].blue);

    //lower right
    //printf("\n");
    //printf("Lower right corner \n");
    i=dim-1;
    j=dim-1;
    iTimesDim=i*dim;
    initialize_pixel_sum(&ps);
    for(ii = i-1; ii <= i; ii++){
        iiTimesDim=ii*dim;
        for(jj = j-1; jj <= j; jj++){
            indx2=iiTimesDim+jj;
            accumulate_sum(&ps, src[indx2]);
            //printf("ii %d jj %d indx2 %d red %d green %d blue %d\n",
                   //ii,jj,indx2,src[indx2].red,src[indx2].green,src[indx2].blue);
        }//for jj
    }//for ii
    indx1=iTimesDim+j;
    dst[indx1].red   = ps.red/ps.num;
    dst[indx1].green = ps.green/ps.num;
    dst[indx1].blue  = ps.blue/ps.num;
    //printf("i %d j %d indx1 %d red %d green %d blue %d\n",
           //i,j,indx1,dst[indx1].red ,dst[indx1].green,dst[indx1].blue);

    //edges
    //left edge (no corners)
    i=0;
    iTimesDim=i*dim;
    for (j = 1; j < dim-1; j++){
        initialize_pixel_sum(&ps);
        for(ii = i; ii <= i+1; ii++){
            iiTimesDim=ii*dim;
            for(jj = j-1; jj <= j+1; jj++){
                indx2=iiTimesDim+jj;
                accumulate_sum(&ps, src[indx2]);
            }//for jj
        }//for ii
        indx1=iTimesDim+j;
        dst[indx1].red   = ps.red/ps.num;
        dst[indx1].green = ps.green/ps.num;
        dst[indx1].blue  = ps.blue/ps.num;
    }// for

    //right edge (no corners)
    i=dim-1;
    iTimesDim=i*dim;
    for (j = 1; j < dim-1; j++){
        initialize_pixel_sum(&ps);
        for(ii = i-1; ii <= i; ii++){
            iiTimesDim=ii*dim;
            for(jj = j-1; jj <= j+1; jj++){
                indx2=iiTimesDim+jj;
                accumulate_sum(&ps, src[indx2]);
            }//for jj
        }//for ii
        indx1=iTimesDim+j;
        dst[indx1].red   = ps.red/ps.num;
        dst[indx1].green = ps.green/ps.num;
        dst[indx1].blue  = ps.blue/ps.num;
    }// for

    //top edge (no corners)
    j=0;
    for (i = 1; i < dim-1; i++){
        iTimesDim=i*dim;
        initialize_pixel_sum(&ps);
        for(ii = i-1; ii <= i+1; ii++){
            iiTimesDim=ii*dim;
            for(jj = j; jj <= j+1; jj++){
                indx2=iiTimesDim+jj;
                accumulate_sum(&ps, src[indx2]);
            }//for jj
        }//for ii
        indx1=iTimesDim+j;
        dst[indx1].red   = ps.red/ps.num;
        dst[indx1].green = ps.green/ps.num;
        dst[indx1].blue  = ps.blue/ps.num;
    }// for i

    //bottom edge (no corners)
    j=dim-1;
    for (i = 1; i < dim-1; i++){
        iTimesDim=i*dim;
        initialize_pixel_sum(&ps);
        for(ii = i-1; ii <= i+1; ii++){
            iiTimesDim=ii*dim;
            for(jj = j-1; jj <= j; jj++){
                indx2=iiTimesDim+jj;
                accumulate_sum(&ps, src[indx2]);
            }//for jj
        }//for ii
        indx1=iTimesDim+j;
        dst[indx1].red   = ps.red/ps.num;
        dst[indx1].green = ps.green/ps.num;
        dst[indx1].blue  = ps.blue/ps.num;
    }// for i

    //middle of image
    for (i = 1; i <= dim-3; i+=4){
        iiTimesDimTopRow1=(i-1)*dim;
        iiTimesDimMidRow1=iiTimesDimTopRow1+dim;
        iiTimesDimBotRow1=iiTimesDimMidRow1+dim;

        iiTimesDimTopRow2=(iiTimesDimTopRow1)+dim;
        iiTimesDimMidRow2=iiTimesDimTopRow2+dim;
        iiTimesDimBotRow2=iiTimesDimMidRow2+dim;

        iiTimesDimTopRow3=iiTimesDimTopRow2+dim;
        iiTimesDimMidRow3=iiTimesDimTopRow3+dim;
        iiTimesDimBotRow3=iiTimesDimMidRow3+dim;

        iiTimesDimTopRow4=iiTimesDimTopRow3+dim;
        iiTimesDimMidRow4=iiTimesDimTopRow4+dim;
        iiTimesDimBotRow4=iiTimesDimMidRow4+dim;
        for (j = 1; j < dim-1; j++){
            initialize_pixel_sum(&ps);
            //top row of 9 block
            //ii = i-1;

            indx2=iiTimesDimTopRow1+(j-1);
            ps.red += src[indx2].red;
            ps.green += src[indx2].green;
            ps.blue += src[indx2].blue;
            ps.num++;

            indx3=iiTimesDimTopRow1 + (j);
            ps.red += src[indx3].red;
            ps.green += src[indx3].green;
            ps.blue += src[indx3].blue;
            ps.num++;

            indx4=iiTimesDimTopRow1 + (j+1);
            ps.red += src[indx4].red;
            ps.green += src[indx4].green;
            ps.blue += src[indx4].blue;
            ps.num++;

            //middle row of 9 block
            //ii = i;
            indx2=iiTimesDimMidRow1+(j-1);
            ps.red += src[indx2].red;
            ps.green += src[indx2].green;
            ps.blue += src[indx2].blue;
            ps.num++;

            indx3=iiTimesDimMidRow1 + (j);
            ps.red += src[indx3].red;
            ps.green += src[indx3].green;
            ps.blue += src[indx3].blue;
            ps.num++;

            indx4=iiTimesDimMidRow1 + (j+1);
            ps.red += src[indx4].red;
            ps.green += src[indx4].green;
            ps.blue += src[indx4].blue;
            ps.num++;

            //bottom row of 9 block
            //ii = i+1;
            indx2=iiTimesDimBotRow1+(j-1);
            ps.red += src[indx2].red;
            ps.green += src[indx2].green;
            ps.blue += src[indx2].blue;
            ps.num++;

            indx3=iiTimesDimBotRow1 + (j);
            ps.red += src[indx3].red;
            ps.green += src[indx3].green;
            ps.blue += src[indx3].blue;
            ps.num++;

            indx4=iiTimesDimBotRow1 + (j+1);
            ps.red += src[indx4].red;
            ps.green += src[indx4].green;
            ps.blue += src[indx4].blue;
            ps.num++;

            indx1=iiTimesDimMidRow1+j;
            dst[indx1].red   = ps.red/ps.num;
            dst[indx1].green = ps.green/ps.num;
            dst[indx1].blue  = ps.blue/ps.num;

            //second step
            initialize_pixel_sum(&ps);
            //top row of 9 block
            //ii = i-1;

            indx2=iiTimesDimTopRow2+(j-1);
            ps.red += src[indx2].red;
            ps.green += src[indx2].green;
            ps.blue += src[indx2].blue;
            ps.num++;

            indx3=iiTimesDimTopRow2 + (j);
            ps.red += src[indx3].red;
            ps.green += src[indx3].green;
            ps.blue += src[indx3].blue;
            ps.num++;

            indx4=iiTimesDimTopRow2 + (j+1);
            ps.red += src[indx4].red;
            ps.green += src[indx4].green;
            ps.blue += src[indx4].blue;
            ps.num++;

            //middle row of 9 block
            //ii = i;
            indx2=iiTimesDimMidRow2+(j-1);
            ps.red += src[indx2].red;
            ps.green += src[indx2].green;
            ps.blue += src[indx2].blue;
            ps.num++;

            indx3=iiTimesDimMidRow2 + (j);
            ps.red += src[indx3].red;
            ps.green += src[indx3].green;
            ps.blue += src[indx3].blue;
            ps.num++;

            indx4=iiTimesDimMidRow2 + (j+1);
            ps.red += src[indx4].red;
            ps.green += src[indx4].green;
            ps.blue += src[indx4].blue;
            ps.num++;

            //bottom row of 9 block
            //ii = i+1;
            indx2=iiTimesDimBotRow2+(j-1);
            ps.red += src[indx2].red;
            ps.green += src[indx2].green;
            ps.blue += src[indx2].blue;
            ps.num++;

            indx3=iiTimesDimBotRow2 + (j);
            ps.red += src[indx3].red;
            ps.green += src[indx3].green;
            ps.blue += src[indx3].blue;
            ps.num++;

            indx4=iiTimesDimBotRow2 + (j+1);
            ps.red += src[indx4].red;
            ps.green += src[indx4].green;
            ps.blue += src[indx4].blue;
            ps.num++;

            indx1=iiTimesDimMidRow2+j;
            dst[indx1].red   = ps.red/ps.num;
            dst[indx1].green = ps.green/ps.num;
            dst[indx1].blue  = ps.blue/ps.num;

            if (i<(dim-3)){
                //third block
                initialize_pixel_sum(&ps);
                //top row of 9 block
                //ii = i-1;

                indx2=iiTimesDimTopRow3+(j-1);
                ps.red += src[indx2].red;
                ps.green += src[indx2].green;
                ps.blue += src[indx2].blue;
                ps.num++;

                indx3=iiTimesDimTopRow3 + (j);
                ps.red += src[indx3].red;
                ps.green += src[indx3].green;
                ps.blue += src[indx3].blue;
                ps.num++;

                indx4=iiTimesDimTopRow3 + (j+1);
                ps.red += src[indx4].red;
                ps.green += src[indx4].green;
                ps.blue += src[indx4].blue;
                ps.num++;

                //middle row of 9 block
                //ii = i;
                indx2=iiTimesDimMidRow3+(j-1);
                ps.red += src[indx2].red;
                ps.green += src[indx2].green;
                ps.blue += src[indx2].blue;
                ps.num++;

                indx3=iiTimesDimMidRow3 + (j);
                ps.red += src[indx3].red;
                ps.green += src[indx3].green;
                ps.blue += src[indx3].blue;
                ps.num++;

                indx4=iiTimesDimMidRow3 + (j+1);
                ps.red += src[indx4].red;
                ps.green += src[indx4].green;
                ps.blue += src[indx4].blue;
                ps.num++;

                //bottom row of 9 block
                //ii = i+1;
                indx2=iiTimesDimBotRow3+(j-1);
                ps.red += src[indx2].red;
                ps.green += src[indx2].green;
                ps.blue += src[indx2].blue;
                ps.num++;

                indx3=iiTimesDimBotRow3 + (j);
                ps.red += src[indx3].red;
                ps.green += src[indx3].green;
                ps.blue += src[indx3].blue;
                ps.num++;

                indx4=iiTimesDimBotRow3 + (j+1);
                ps.red += src[indx4].red;
                ps.green += src[indx4].green;
                ps.blue += src[indx4].blue;
                ps.num++;

                indx1=iiTimesDimMidRow3+j;
                dst[indx1].red   = ps.red/ps.num;
                dst[indx1].green = ps.green/ps.num;
                dst[indx1].blue  = ps.blue/ps.num;
                //four block
                initialize_pixel_sum(&ps);
                //top row of 9 block
                //ii = i-1;

                indx2=iiTimesDimTopRow4+(j-1);
                ps.red += src[indx2].red;
                ps.green += src[indx2].green;
                ps.blue += src[indx2].blue;
                ps.num++;

                indx3=iiTimesDimTopRow4 + (j);
                ps.red += src[indx3].red;
                ps.green += src[indx3].green;
                ps.blue += src[indx3].blue;
                ps.num++;

                indx4=iiTimesDimTopRow4 + (j+1);
                ps.red += src[indx4].red;
                ps.green += src[indx4].green;
                ps.blue += src[indx4].blue;
                ps.num++;

                //middle row of 9 block
                //ii = i;
                indx2=iiTimesDimMidRow4+(j-1);
                ps.red += src[indx2].red;
                ps.green += src[indx2].green;
                ps.blue += src[indx2].blue;
                ps.num++;

                indx3=iiTimesDimMidRow4 + (j);
                ps.red += src[indx3].red;
                ps.green += src[indx3].green;
                ps.blue += src[indx3].blue;
                ps.num++;

                indx4=iiTimesDimMidRow4 + (j+1);
                ps.red += src[indx4].red;
                ps.green += src[indx4].green;
                ps.blue += src[indx4].blue;
                ps.num++;

                //bottom row of 9 block
                //ii = i+1;
                indx2=iiTimesDimBotRow4+(j-1);
                ps.red += src[indx2].red;
                ps.green += src[indx2].green;
                ps.blue += src[indx2].blue;
                ps.num++;

                indx3=iiTimesDimBotRow4 + (j);
                ps.red += src[indx3].red;
                ps.green += src[indx3].green;
                ps.blue += src[indx3].blue;
                ps.num++;

                indx4=iiTimesDimBotRow4 + (j+1);
                ps.red += src[indx4].red;
                ps.green += src[indx4].green;
                ps.blue += src[indx4].blue;
                ps.num++;

                indx1=iiTimesDimMidRow4+j;
                dst[indx1].red   = ps.red/ps.num;
                dst[indx1].green = ps.green/ps.num;
                dst[indx1].blue  = ps.blue/ps.num;
            }
        }// for j
    }//for i
}//smooth_4

/*
 * smooth - Your current working version of smooth.
 * IMPORTANT: This is the version you will be graded on
 */
char smooth_descr[] = "smooth: Current working version";
void smooth(int dim, pixel *src, pixel *dst)
{
    //naive_smooth(dim, src, dst);
    //new_smooth4(dim, src, dst);
    new_smooth4(dim,src,dst);
}


/*********************************************************************
 * register_smooth_functions - Register all of your different versions
 *     of the smooth kernel with the driver by calling the
 *     add_smooth_function() for each test function.  When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 *********************************************************************/

void register_smooth_functions() {
    add_smooth_function(&smooth, smooth_descr);
    add_smooth_function(&naive_smooth, naive_smooth_descr);

    /*for (int i =0;i<=10;i++){
    add_smooth_function(&new_smooth1, new_smooth1_descr);
    }*/
    //add_smooth_function(&new_smooth2, new_smooth2_descr);
    //add_smooth_function(&new_smooth3, new_smooth3_descr);
    add_smooth_function(&new_smooth4, new_smooth4_descr);
    /* ... Register additional test functions here */
}

