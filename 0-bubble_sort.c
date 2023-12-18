#include "sort.h"

/**
 * bubble_sort - sort the array
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	int i, j, tmp, flag;

	j = 0;
	i = size;
	flag = 0;
	if (array == NULL || size < 2)
		return;
	while (i > 0)
	{
		j = 0;
		while (j + 1 < i)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tmp;
				flag = 1;
				print_array(array, size);
			}
			j++;
		}
		i--;
		if (flag == 0)
			break;
	}
}
