#include "sort.h"

/**
 * bubble_sort - sorts an array of ints in ascending
 *             order using bubble sort algo
 * @array: array to be sorted
 * @size: number of elements in array
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	int swap = 0, temp;
	size_t i, new_size = size;

	if (array == NULL || size < 2)
		return;

	while (new_size)
	{
		for (i = 0; i < new_size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				print_array(array, size);
				swap = 1;
			}
		}
		new_size--;
		if (!swap)
			break;
	}
}
