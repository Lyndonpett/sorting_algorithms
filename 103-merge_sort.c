#include "sort.h"

/**
 * merge_sort - gets the array and size to perform mergesort on
 *
 * @array: the array
 * @size: the size of the array
 *
 */
void merge_sort(int *array, size_t size)
{	/* initialize variables */
	size_t i = 0;
	int *aux = NULL;

	/* make sure array is not null & make sure size is larger than 2 */
	if (array == NULL || size < 2)
	{
		return;
	}

	/* malloc for temp array aux */
	aux = malloc(sizeof(int) * size);
	if (aux == NULL)
	{
		return;
	}

	/* copy the array into aux */
	while (i < size)
	{
		aux[i] = array[i];
		i++;
	}
	/* send arrays, start low at 0, and high is size */
	realMergeSort(array, aux, 0, size);

	/* freeeeeeee*/
	free(aux);
}

/**
 * merge - merges the two halves
 *
 * @low: lowest index
 * @mid: mid index
 * @high: highest index
 * @array: the array
 * @aux: copied array
 *
 */
void merge(int *array, int *aux, size_t low, size_t mid, size_t high)
{ /* initialize variables and set to low and mid */
	size_t i = low, j = mid, k = low;

	/* start printing | left is aux + low, right is aux + mid */
	printf("Merging...\n");
	printf("[left]: ");
	/* print array + low, and size is mid - low */
	print_array(aux + low, mid - low);
	printf("[right]: ");
	/* print array + mid, and size is high - mid */
	print_array(aux + mid, high - mid);

		/* low < high */
		while (k < high)
		{	/* low<mid & mid>=high OR aux[low]<=aux[mid] */
			if (i < mid && (j >= high || aux[i] <= aux[j]))
			{	/* set array[low] to aux[low] and incre */
				array[k] = aux[i];
				i++;
			}
			else
			{	/* set array[low] to aux[mid] and incre */
				array[k] = aux[j];
				j++;
			}
			k++;
		}
	printf("[Done]: ");

	/* print array + low, and size is high - low */
	print_array(array + low, high - low);
}

/**
 * realMergeSort - recursively calls itself to
 * divide the array till size becomes one
 *
 * @low: lowest index
 * @high: highest index
 * @array: the array
 * @aux: copied array
 *
 */
void realMergeSort(int *array, int *aux, size_t low, size_t high)
{	/* initialize mid */
	size_t mid = 0, i = low;

	/* check high - low < 2 to makes sure low(left) < high(right)  */
	if (high - low < 2)
	{
		return;
	}

	/* get the mid */
	mid = (low + high) / 2;

	/* split/merge left(low) half */
	realMergeSort(array, aux, low, mid);
	/* split/merge right(high) half */
	realMergeSort(array, aux, mid, high);

	/* merge the two half runs */
	merge(array, aux, low, mid, high);

	/* copy back to the original array to reflect sorted order */
	while (i < high)
	{
		aux[i] = array[i];
		i++;
	}
}
