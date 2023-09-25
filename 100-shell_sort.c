#include "sort.h"

/**
 * shell_sort - sorts array of ints in ascending order
 *         using shell sort algo, using Knuth sequence
 * @array: array to be sorted
 * @size: number of elements in array
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, gap = 1;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = (gap * 3) + 1;

	while (gap)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
		gap /= 3;
	}
}
