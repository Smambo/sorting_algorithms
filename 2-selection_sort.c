#include "sort.h"

/**
 * selection_sort - sorts an array of ints in
 *             ascending order using selection sort
 * @array: array to be sorted
 * @size: number of elements in array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	int idx = 0, temp, min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				idx = j;
			}
		}
		if (min != array[i])
		{
			temp = array[i];
			array[i] = array[idx];
			array[idx] = temp;
			print_array(array, size);
		}
	}
}
