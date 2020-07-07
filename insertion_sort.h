#pragma once

void insertion_sort(double* array, int array_size)
{
    int j;
    double v, aux;

    for (unsigned int i = 1; i < array_size; i++) 
    {
        v = array[i];
        j = i;

        while (array[j-1] > v && j > 0)
        {
            aux = array[j];
            array[j] = array[j-1];
            array[j-1] = aux;
            j--;
        }

        array[j] = v;
    }

}