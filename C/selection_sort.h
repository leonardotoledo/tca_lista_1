#pragma once

void selection_sort(double* array, int array_size)
{
    int m;
    double aux;

    for (unsigned int i = 0; i < array_size-1; i++) 
    {
        m = i;

        for (unsigned int j = i+1; j < array_size; j++)
            if (array[j] < array[m])
                m = j;
        
        aux = array[i];
        array[i] = array[m];
        array[m] = aux;
    }

}