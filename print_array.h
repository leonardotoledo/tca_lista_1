#pragma once
#include <stdio.h>

void print_array(double* array, int array_size)
{
    printf("(%.f", array[0]);
    if (array_size > 1) {
        for (int i = 1; i < array_size; i++) {
            printf(", %.f", array[i]);
        }
    }
    printf(")\n");
}