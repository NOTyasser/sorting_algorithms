#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 **/
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * partition_hoare - Hoare partition scheme
 * @array: Pointer to the array
 * @low: Lower index of the partition
 * @high: Higher index of the partition
 * @size: Size of the array
 * Return: Index of the pivot
 **/
int partition_hoare(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1, j = high + 1;

    printf("Partition [%d, %d]: ", low, high);
    print_array(array + low, high - low + 1);

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i < j)
        {
            swap(&array[i], &array[j]);
            print_array(array, size);
        }
        else
        {
            return j;
        }
    }
}

/**
 * quicksort_hoare - Recursive function to perform quicksort
 * @array: Pointer to the array
 * @low: Lower index of the partition
 * @high: Higher index of the partition
 * @size: Size of the array
 **/
void quicksort_hoare(int *array, int low, int high, size_t size)
{
    int pivot;

    if (low < high)
    {
        pivot = partition_hoare(array, low, high, size);
        quicksort_hoare(array, low, pivot, size);
        quicksort_hoare(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using
 * the quicksort algorithm with Hoare Partition Scheme
 * @array: Pointer to the array
 * @size: Size of the array
 **/
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_hoare(array, 0, size - 1, size);
}
