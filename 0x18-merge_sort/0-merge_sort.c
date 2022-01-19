#include <stdlib.h>
#include "sort.h"

/**
 * merge - sort the 2 chunks of array by compairing each value
 * and save it into temperaty Array then coppy it into
 * the right place in the main Array
 * @arr: main array
 * @start: start index
 * @mid: mid index
 * @end: end index
 *
 * Return: Void
 */
void merge(int *arr, int *tmp, int start, int mid, int end)
{
	int k, i, j;

	i = start, k = 0, j = mid;
	while (i < mid && j < end)
	{
		if (arr[j] <= arr[i])
		{
			tmp[k] = arr[j];
			j++;
		}
		else
		{
			tmp[k] = arr[i];
			i++;
		}
		k++;
	}
	while (j < end)
	{
		tmp[k] = arr[j];
		k++;
		j++;
	}
	while (i < mid)
	{
		tmp[k] = arr[i];
		k++;
		i++;
	}
	printf("[Done]: ");
	for (i = start; i < end; i += 1)
	{
		arr[i] = tmp[i - start];
		printf("%d", arr[i]);
		if (i < end - 1)
			printf(", ");
	}
	printf("\n");
}

/**
 * recursive_merge_sort - handle sort Array
 * @arr: main array
 * @start: start index
 * @end: end index
 *
 * Return: Void
 */
void recursive_merge_sort(int *arr, int *tmp, int start, int end)
{
	int mid, i;

	if (end - start <= 1)
		return;
	mid = (end + start) / 2;
	recursive_merge_sort(arr, tmp, start, mid);
	recursive_merge_sort(arr, tmp, mid, end);

	printf("Merging...\n");
	printf("[left]: ");
	for (i = start; i < mid; i++)
	{
		printf("%d", arr[i]);
		if (i < mid - 1)
			printf(", ");
	}

	printf("\n[right]: ");
	for (i = mid; i < end; i++)
	{
		printf("%d", arr[i]);
		if (i < end - 1)
			printf(", ");
	}
	printf("\n");
	merge(arr, tmp, start, mid, end);
}

/**
 * merge_sort - handle sort Array
 * @array: main array
 * @size: length of array
 *
 * Return: Void
 */

void merge_sort(int *array, size_t size)
{

	int length, *tmp;

	length = (int)size;

	tmp = malloc(sizeof(int) * length);

	recursive_merge_sort(array, tmp, 0, length);
	free(tmp);
}
