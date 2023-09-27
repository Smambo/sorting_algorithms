#include "sort.h"

/**
 * hoare_partition - implements Hoare partition scheme
 * @array: pointer to array of integers
 * @low: start index of partition
 * @high: end index of partition
 * @size: number of elements in array
 * Return: nothing
 */
int hoare_partition(int *array, int low, int high, int size)
{
	int i, j, temp, pivot = array[high];

	i = low - 1;
	j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		if (i != j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
}

/**
 * qs_helper - recursively sorts partition
 * @array: pointer to array of integers
 * @low: start index of partition
 * @high: end index of partition
 * @size: number of elements in array
 * Return: nothing
 */
void qs_helper(int *array, int low, int high, int size)
{
	int partition_idx; /* pivot */

	if (low < high)
	{
		partition_idx = hoare_partition(array, low, high, size);
		qs_helper(array, low, partition_idx, size);
		qs_helper(array, partition_idx + 1, high, size);
	}
}

/**
 * quick_sort_hoare - sorts an array of ints in ascending order
 *                  using the Hoare partition scheme of Quick sort algo
 * @array: array to be sorted
 * @size: number of elements in array
 * Return: nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	qs_helper(array, 0, size - 1, size);
}
