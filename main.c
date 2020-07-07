#include "print_array.h"
#include "array_generator.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"

#define INSERTION_SORT 1
#define SELECTION_SORT 2
#define MERGE_SORT 3
#define QUICK_SORT 4

#define RANDOM_ARRAY 1
#define ASCENDING_ARRAY 2
#define DESCENDING_ARRAY 3

void generate_array(int, double *, int);
void sort_array(int, double *, int);

// Declared as global variable to store it on the heap
double array[100000]; // limit: 523496
double copy[100000];

int main()
{
    int array_size = sizeof(array) / sizeof(array[0]);
    printf("-----------------------------\n");
    printf("Number of elements: %d.\n", array_size);
    printf("-----------------------------\n");

    generate_array(RANDOM_ARRAY, &array[0], array_size);

    sort_array(QUICK_SORT, &array[0], array_size);
    sort_array(MERGE_SORT, &array[0], array_size);
    sort_array(SELECTION_SORT, &array[0], array_size);
    sort_array(INSERTION_SORT, &array[0], array_size);

    generate_array(DESCENDING_ARRAY, &array[0], array_size);

    sort_array(QUICK_SORT, &array[0], array_size);
    sort_array(MERGE_SORT, &array[0], array_size);
    sort_array(SELECTION_SORT, &array[0], array_size);
    sort_array(INSERTION_SORT, &array[0], array_size);

    generate_array(ASCENDING_ARRAY, &array[0], array_size);

    sort_array(QUICK_SORT, &array[0], array_size);
    sort_array(MERGE_SORT, &array[0], array_size);
    sort_array(SELECTION_SORT, &array[0], array_size);
    sort_array(INSERTION_SORT, &array[0], array_size);

    print_array(&array[0], array_size); // For debbuging porpuses

    return 0;
}

void generate_array(int array_type, double *array, int array_size)
{
    switch (array_type)
    {
    case RANDOM_ARRAY:
        generate_random_array(&array[0], array_size);
        printf("\nRandom array.\n");
        break;
    case ASCENDING_ARRAY:
        generate_ascending_array(&array[0], array_size);
        printf("\nAscending array.\n");
        break;
    case DESCENDING_ARRAY:
        generate_descending_array(&array[0], array_size);
        printf("\nDescending array.\n");
        break;
    default:
        printf("You must pick an array size.\n");
    }

    memcpy(copy, array, array_size*sizeof(array[0]));
}

void sort_array(int sort_type, double *array, int array_size)
{
    clock_t start, end;
    double cpu_time_used;

    memcpy(array, copy, array_size*sizeof(array[0]));

    switch (sort_type)
    {
    case INSERTION_SORT:
        printf("Insertion sort. ");
        start = clock();
        insertion_sort(&array[0], array_size);
        end = clock();
        break;
    case SELECTION_SORT:
        printf("Selection sort. ");
        start = clock();
        selection_sort(&array[0], array_size);
        end = clock();
        break;
    case MERGE_SORT:
        printf("Merge sort. ");
        start = clock();
        merge_sort(&array[0], array_size);
        end = clock();
        break;
    case QUICK_SORT:
        printf("Quick sort. ");
        start = clock();
        quick_sort(&array[0], 0, array_size - 1);
        end = clock();
        break;
    default:
        printf("You must pick a sorting algorithm.\n");
    }

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("CPU Time: %.8f s.\n", cpu_time_used);
}
