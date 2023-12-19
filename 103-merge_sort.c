#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merge two subarrays
 * @array: Pointer to the array
 * @left: Pointer to the left subarray
 * @left_size: Size of the left subarray
 * @right: Pointer to the right subarray
 * @right_size: Size of the right subarray
 **/
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
    size_t i = 0, j = 0, k = 0;
    int *merged;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(left, left_size);
    printf("[right]: ");
    print_array(right, right_size);

    merged = malloc(sizeof(int) * (left_size + right_size));
    if (!merged)
        exit(1);

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
        {
            merged[k] = left[i];
            i++;
        }
        else
        {
            merged[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size)
    {
        merged[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size)
    {
        merged[k] = right[j];
        j++;
        k++;
    }

    for (i = 0; i < left_size + right_size; i++)
        array[i] = merged[i];

    printf("[Done]: ");
    print_array(array, left_size + right_size);

    free(merged);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using merge sort
 * @array: Pointer to the array
 * @size: Size of the array
 **/
void merge_sort(int *array, size_t size)
{
    if (size > 1)
    {
        size_t mid = size / 2;
        int *left = array;
        int *right = array + mid;

        printf("Merging...\n");
        printf("[left]: ");
        print_array(left, mid);
        printf("[right]: ");
        print_array(right, size - mid);

        merge_sort(left, mid);
        merge_sort(right, size - mid);

        merge(array, left, mid, right, size - mid);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merge two subarrays
 * @array: Pointer to the array
 * @left: Pointer to the left subarray
 * @left_size: Size of the left subarray
 * @right: Pointer to the right subarray
 * @right_size: Size of the right subarray
 **/
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
    size_t i = 0, j = 0, k = 0;
    int *merged;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(left, left_size);
    printf("[right]: ");
    print_array(right, right_size);

    merged = malloc(sizeof(int) * (left_size + right_size));
    if (!merged)
        exit(1);

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
        {
            merged[k] = left[i];
            i++;
        }
        else
        {
            merged[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size)
    {
        merged[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size)
    {
        merged[k] = right[j];
        j++;
        k++;
    }

    for (i = 0; i < left_size + right_size; i++)
        array[i] = merged[i];

    printf("[Done]: ");
    print_array(array, left_size + right_size);

    free(merged);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using merge sort
 * @array: Pointer to the array
 * @size: Size of the array
 **/
void merge_sort(int *array, size_t size)
{
    if (size > 1)
    {
        size_t mid = size / 2;
        int *left = array;
        int *right = array + mid;

        printf("Merging...\n");
        printf("[left]: ");
        print_array(left, mid);
        printf("[right]: ");
        print_array(right, size - mid);

        merge_sort(left, mid);
        merge_sort(right, size - mid);

        merge(array, left, mid, right, size - mid);
    }
}

