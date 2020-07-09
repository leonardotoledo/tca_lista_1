#pragma once
#include <stdlib.h>
#include <string.h>


void merge_sort(double* array, int array_size)
{
    if (array_size < 2)
    {
        return;
    }
    else
    {
        int m = (int) (.5*array_size);

        double* l = (double*) malloc(m*sizeof(array[0]));               // Allocating memory for l
        double *r = (double*) malloc((array_size-m)*sizeof(array[0]));  // Allocating memory for r

        memcpy(l, array, m*sizeof(array[0]));                           // Making a copy of array from index 0
        memcpy(r, array+m, (array_size-m)*sizeof(array[0]));            // Making a copy of array from index m

        merge_sort(&l[0], m);                                           // Recursively applying merge_sort
        merge_sort(&r[0], array_size-m);                                // Recursively applying merge_sort

        unsigned int i = 0, j = 0;

        for (unsigned int k = 0; k < array_size; k++)
        {
            if (i == m)
            {
                array[k] = r[j];
                j++;
            }
            else if (j == array_size-m)
            {
                array[k] = l[i];
                i++;
            }
            else
            {
                if (l[i] < r[j]) 
                {
                    array[k] = l[i];
                    i++;
                } 
                else
                {
                    array[k] = r[j];
                    j++;
                }
            }
        }

        free(l);                                                          // Freeing memory from l
        free(r);                                                          // Freeing memory from r
    }
}