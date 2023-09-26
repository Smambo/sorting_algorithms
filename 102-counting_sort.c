#include "sort.h"

/**
 * counting_sort - sorts array of ints in ascending
 *               order using Counting sort algo
 * @array: array to be sorted
 * @size: number of elements in array
 * Return: nothing
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int *counter, j, k, num, dup;

	if (array == NULL || size < 2)
		return;
	k = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	counter = malloc(sizeof(int) * (k + 1));
	if (counter == NULL)
		return;
	for (j = 0; j < (k + 1); j++)
		counter[j] = 0;
	for (i = 0; i < size; i++)
	{
		num = array[i];
		counter[num] += 1;
	}
	for (j = 0; j < k; j++)
		counter[j + 1] += counter[j];

	print_array(counter, k + 1);
	for (i = 0, j = 0; j < k; j++) /*replaces array with sorted one*/
	{
		if ((j == 0) && counter[j] != 0)
		{
			for ((dup = counter[j]); dup > 0; dup--)
				array[i++] = j;
		}
		if (counter[j + 1] > counter[j])
		{
			for ((dup = counter[j + 1] - counter[j]); dup > 0; dup--)
				array[i++] = (j + 1);
		}
	}
	free(counter);
}
