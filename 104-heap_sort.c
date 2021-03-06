#include "sort.h"

/**
 * heapify - recursive function to build heap
 *
 * @array: the array
 * @heap: the size of heap data
 * @i: the index
 * @size: the size of array
 *
 */

void heapify(int *array, int heap, int i, int size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int tmp;

	/* if left is larger than largest */
	if (left < heap && array[left] > array[largest])
	{
		largest = left;
	}

	/* if right is larger than largest */
	if (right < heap && array[right] > array[largest])
	{
		largest = right;
	}

	/* if largest is not root */
	if (largest != i)
	{	/* swap the array if largest is not root */
		tmp = array[i];
		array[i] = array[largest];
		array[largest] = tmp;
		/* print and call heapify to recursively sort */
		print_array(array, size);
		heapify(array, heap, largest, size);
	}

}

/**
 * heap_sort - sorts array with heap sort
 *
 * @array: the array
 * @size: the size of the array
 *
 */

void heap_sort(int *array, size_t size)
{
	int i = size / 2 - 1;
	int tmp;

	if (array == NULL || size < 2)
	{
		return;
	}

	/* build heap */
	while (i >= 0)
	{
		heapify(array, size, i, size);
		i--;
	}

	/* one by one extract an element from heap */
	for (i = size - 1; i >= 0; i--)
	{	/* move current root to end */
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;

		if (i > 0)
		{	/* as long as we're above 0, print the array */
			print_array(array, size);
		}

		/* call max heapify on the reduced heap */
		heapify(array, i, 0, size);
	}
}
