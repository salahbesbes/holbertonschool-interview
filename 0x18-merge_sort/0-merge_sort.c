#include <stdlib.h>
#include "sort.h"

/**
 * top_down_merge - putting elements in the newly created array
 * @array: original array
 * @first: first index of array
 * @mid: middle index of array
 * @last: last index of array
 * @t: sorted array
 */
void top_down_merge(int *array, int first, int mid, int last, int *t)
{
	int i = first;
	int j = mid;
	int k = 0;

	for (k = first; k < last; k++)
	{
		if (i < mid && (j >= last || t[i] <= t[j]))
		{
			array[k] = t[i];
			i = i + 1;
		}
		else
		{
			array[k] = t[j];
			j = j + 1;
		}
	}
}

/**
 * top_down_split_merge - splitting array in halfs
 * @t: sorted array
 * @first: first index of array
 * @last: last index of array
 * @array: original array
 */
void top_down_split_merge(int *t, int first, int last, int *array)
{
	int mid;
	int i = 0;

	if (last - first <= 1)
		return;
	mid = (last + first) / 2;

	top_down_split_merge(array, first, mid, t);

	top_down_split_merge(array, mid, last, t);

	printf("Merging...\n");
	printf("[left]: ");
	for (i = first; i < mid; i++)
	{
		printf("%d", t[i]);
		if (i < mid - 1)
			printf(", ");
	}

	printf("\n[right]: ");
	for (i = mid; i < last; i++)
	{
		printf("%d", t[i]);
		if (i < last - 1)
			printf(", ");
	}

	top_down_merge(array, first, mid, last, t);

	printf("\n");
	printf("[Done]: ");
	for (i = first; i < last; i++)
	{
		printf("%d", array[i]);
		if (i < last - 1)
			printf(", ");
	}
	printf("\n");
}

/**
 * top_down_merge_sort - using top down method
 * @array: original array
 * @t: sorted array
 * @size: size of original array
 */
void top_down_merge_sort(int *array, int *t, int size)
{
	int i;

	for (i = 0; i < size; i++)
		t[i] = array[i];
	top_down_split_merge(t, 0, size, array);
}

/**
 * merge_sort - sorts an array of integers in ascending order using
 * the Merge Sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *t;

	if (array == NULL)
		return;

	t = malloc(sizeof(int) * size);

	top_down_merge_sort(array, t, size);

	free(t);
}
