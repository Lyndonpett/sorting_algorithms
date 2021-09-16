#include "sort.h"

/**
 * selection_sort - does selection sort on an array.
 *
 * @array: the array
 * @size: the size of the array.
 *
 * Return: void.
 */

void selection_sort(int *array, size_t size)
{
	size_t step, min_idx, i;

	if (array == NULL)
	{
		return;
	}

	for (step = 0; step < size - 1; step++)
	{
		min_idx = step;
		for (i = step + 1; i < size; i++)
		{
			if (array[i] < array[min_idx])
			{
				min_idx = i;
			}
		}
		if (min_idx != step)
		{
			swap(&array[min_idx], &array[step]);
			print_array(array, size);
		}
	}
}

/**
 * swap - swaps the array
 *
 * @a: array 1
 * @b: array 2
 *
 */

void swap(int *a, int *b)
{
	size_t temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
