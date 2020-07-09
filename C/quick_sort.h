#pragma once

void quick_sort(double* array, int r, int s)
{
    if (s <= r)
    {
        return;
    }
    else
    {
        double v = array[r];
        int i = r;
        int j = s;

        double aux;
        while(j >= i)
	    {
            while(array[i] < v)
            {
                i++;
            }
            while(array[j] > v)
            {
                j--;
            }
            if (i <= j)
            {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
                i++;
                j--;
            }
        }

        quick_sort(&array[0], r, i-1);
        quick_sort(&array[0], i, s);
    }
}