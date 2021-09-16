#include "sort.h"

/**
 * @brief
 *
 *
 *
 */

void quick_sort(int *array, size_t size)
{ /* checks if array is valid */
	if (array != NULL)
	{ /* recursive low to highest */
		sort(array, 0, size - 1, size);
	}
}

/**
 * @brief
 *
 *
 *
 */

void sort(int *array, int low, int high, size_t size)
{
	int pivotINDEX;
	/* checks for two values */
	if (low < high)
	{ /* find index of pivot */
		pivotINDEX = partition(array, low, high, size);
		/* quicksort to go both directions */
		sort(array, low, pivotINDEX - 1, size);
		sort(array, pivotINDEX + 1, high, size);
	}
}
/**
 * @brief
 *
 * @param array
 * @param low
 * @param high
 * @param size
 * @return int
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], pivotINDEX = low, i;
	/* move smallest # to left and greatest # to right */
	for (i = low; i < high; i++)
	{ /* checks if our index is larger than pivot */
		if (array[i] <= pivot)
		{ /* index in our array becomes our pivotINDEX */
			swapArray(array, i, pivotINDEX);
			/* print the array if our pivotINDEX does not equal array index */
			if (pivotINDEX != i)
			{
				print_array(array, size);
			}
			/* move right till we hit # greater than pivot */
			pivotINDEX++;
		}
	}
	/* swap pivotINDEX and high to find our high */
	swapArray(array, pivotINDEX, high);
	if (pivotINDEX != high)
	{
		print_array(array, size);
	}
	return (pivotINDEX);
}

/**
 * @brief
 *
 *
 */

void swapArray(int *array, int first, int second)
{
	int tmp;

	tmp = array[first];
	array[first] = array[second];
	array[second] = tmp;
}
