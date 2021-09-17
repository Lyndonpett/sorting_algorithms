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
	/* handles looping through the array */
	for (step = 0; step < size - 1; step++)
	{ /* set our min to the num found */
		min_idx = step;
		for (i = step + 1; i < size; i++)
		{ /* if size of i is smaller than index, set min to equal i */
			if (array[i] < array[min_idx])
			{
				min_idx = i;
			}
		} /* as long as the two values !=, then swap and print */
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
