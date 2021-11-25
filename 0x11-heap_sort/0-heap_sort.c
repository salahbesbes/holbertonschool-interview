#include "sort.h"
#include <stdio.h>

/**
 * swap - swap 2 values in a tree
 * @array: array
 * @value1: value1
 * @value2: value2
 * Return: Void
 */
void swap(int *array, int value1, int value2)
{
	int tmp;

	tmp = array[value1];
	array[value1] = array[value2];
	array[value2] = tmp;
}

/**
 * siftDown - siftdown th tree
 * @array: array
 * @start: start
 * @end: end
 * @size: size
 * Return: Void
 */
void siftDown(int *array, int start, int end, int size)
{
	int rootIndex, childIndex;

	rootIndex = start;
	while (rootIndex * 2 + 1 <= end)
	{
		childIndex = rootIndex * 2 + 1;

		if (childIndex + 1 <= end && array[childIndex] < array[childIndex + 1])
		{
			childIndex++;
		}

		if (array[rootIndex] < array[childIndex])
		{
			swap(array, rootIndex, childIndex);
			print_array(array, size);
			rootIndex = childIndex;
		}
		else
		{
			return;
		}
	}
}
/**
 * heapify - siftdown th tree
 * @array: array
 * @size: size
 * Return: Void
 */
void heapify(int *array, int size)
{
	int LastParentNodeIndex;

	LastParentNodeIndex = (size - 2) / 2;

	while (LastParentNodeIndex >= 0)
	{
		siftDown(array, LastParentNodeIndex, size - 1, size);
		LastParentNodeIndex--;
	}
}
/**
 * heap_sort - heap_sort th tree
 * @array: array
 * @size: size
 * Return: Void
 */
void heap_sort(int *array, size_t size)
{

	int lastIndex;

	heapify(array, (int)size);

	lastIndex = size - 1;

	while (lastIndex > 0)
	{
		swap(array, lastIndex, 0);
		print_array(array, (int)size);
		lastIndex--;
		siftDown(array, 0, lastIndex, size);
	}
}
