#include "sort.h"
/**
 * quick_sort_helper - quick sort helper function
 *
 * @array: The array
 * @low: a variable
 * @high: a variable
 * @size: The size of the array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pivot = array[high], left = low - 1, i = low, tmp;

	if (low < high)
	{
		while (i <= high - 1)
		{
			if (array[i] <= pivot)
			{
				left++;
				if (i != left)
				{
					tmp = array[left];
					array[left] = array[i];
					array[i] = tmp;
					print_array(array, size);
				}
			}
			i++;
		}
		if (left + 1 != high)
		{
			tmp = array[left + 1];
			array[left + 1] = array[high];
			array[high] = tmp;
			print_array(array, size);
		}
		quick_sort_helper(array, low, left + 1 - 1, size);
		quick_sort_helper(array, left + 1 + 1, high, size);
	}
}
/**
 * quick_sort - quick sort function
 *
 * @array: The array
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_helper(array, 0, size - 1, size);
}
