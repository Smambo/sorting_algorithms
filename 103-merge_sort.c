#include "sort.h"

/**
 * print - prints text for splitting and merging
 * @array: array to be sorted
 * @side: left, right, merged side
 * @start: start index
 * @end: end index
 * Return: nothing
 */
void print(int *array, char *side, size_t start, size_t end)
{
	size_t i;

	printf("[%s]: ", side);

	for (i = start; i < end; i++)
	{
		if (i != (end - 1))
			printf("%d, ", array[i]);
		else
			printf("%d\n", array[i]);
	}
}

/**
 * recursive_merge_sort - recursively splits and merges
 *                        halves of array
 * @array: array to be split and merged
 * @tmp_array: temporary array to hold sorted elements
 * @l: (left) start index
 * @r: (right) end index
 * Return: nothing
 */
void recursive_merge_sort(int *array, int *tmp_array, size_t l, size_t r)
{
	size_t i, l_side, r_side, mid;

	mid = (l + r) / 2;
	if (r - l <= 1)
		return;
	recursive_merge_sort(array, tmp_array, l, mid);
	recursive_merge_sort(array, tmp_array, mid, r);
	printf("Merging...\n");
	print(array, "left", l, mid);
	print(array, "right", mid, r);
	l_side = l;
	r_side = mid;

	for (i = l; i < r; i++)
	{
		if ((l_side < mid) && ((r_side == r) ||
					(array[l_side] < array[r_side])))
		{
			tmp_array[i] = array[l_side];
			l_side++;
		} else
		{
			tmp_array[i] = array[r_side];
			r_side++;
		}
	}
	print(tmp_array, "Done", l, r);

	for (i = l; i < r; i++)
		array[i] = tmp_array[i];
}

/**
 * merge_sort - sorts array of ints in ascending
 *              order using Merge sort algo
 * @array: array to be sorted
 * @size: number of elements in array
 * Return: nothing
 */
void merge_sort(int *array, size_t size)
{
	int *tmp_array;

	if (!(array) || size < 2)
		return;

	tmp_array = malloc(sizeof(int) * size);

	if (!(tmp_array))
		return;

	recursive_merge_sort(array, tmp_array, 0, size);
	free(tmp_array);
}
