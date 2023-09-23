#include "sort.h"

/**
 * partition - creates partition in array
 * @array: array to be partitioned
 * @start: start of array
 * @end: end of array
 * @size: number of elements in array
 * Return: index of pivot
 */
int partition(int *array, int start, int end, int size)
{
	int i = start, j, temp;
	int pivot = array[end];

	for (j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != end)
	{
		temp = array[i];
		array[i] = array[end];
		array[end] = temp;
		print_array(array, size);
	}
	return (i);
}

/**
 * recursive_quick_sort - recursively quick sorts array
 * @array: array to be sorted
 * @start: start of array/partioned array
 * @end: end of array/partitioned array
 * @size: number of elements in array
 * Return: nothing
 */
void recursive_quick_sort(int *array, int start, int end, int size)
{
	int pivot;

	if (start < end)
	{
		pivot = partition(array, start, end, size);
		recursive_quick_sort(array, start, pivot - 1, size);
		recursive_quick_sort(array, pivot + 1, end, size);
	}
}

/**
 * quick_sort - sorts array of ints in
 *           ascending order using quicksort algo
 * @array: array to be sorted
 * @size: number of elements in array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	recursive_quick_sort(array, 0, size - 1, size);
}
