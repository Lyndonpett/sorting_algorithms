#include "sort.h"

/**
 * bubble_sort - bubble sorts an array.
 *
 * @array: the array
 * @size: the size of the array
 *
 * Return: void.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, tmp;
	/* loop through array equal to the size of the array */
	for (i = 0; i < size; i++)
	{ /* last i elements are sorted already */
		for (j = 0; j < size - i - 1; j++)
		{ /* swap if order is broken */
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
