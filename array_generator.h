#pragma once
#include <time.h>
#include <stdlib.h>

void generate_random_array(double* array, int array_size) 
{
    time_t t;
    srand((unsigned) time(&t));
    for (unsigned int i = 0; i < array_size; i++)
        array[i] = rand() % array_size + 1;
}

void generate_ascending_array(double* array, int array_size) 
{
    for (unsigned int i = 0; i < array_size; i++)
        array[i] = i + 1;
}

void generate_descending_array(double* array, int array_size)
{
    for (unsigned int i = 0; i < array_size; i++)
        array[i] = array_size - i;
}