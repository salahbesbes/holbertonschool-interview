#include "search_algos.h"
/**
 * advanced_binary - binary search in array
 * @array:array to search in
 * @size: size of the array
 * @value: the value to search for
 * Return: - 1 or index of @value
 */

int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (recursive_binary(array, 0, size - 1, value));
}
/**
 * recursive_binary - helper of binary search adv function
 *
 * @array: sorted array of int.
 * @start: starting index of the subarray
 * @finish: finishing index of the subarray
 * @value: value we are looking for
 *
 * Return: index, -1 if doesn't find it.
 */
int recursive_binary(int *array, size_t start, size_t finish, int value)
{
	size_t mid;

	print_array(array, start, finish);
	if (value == array[start])
		return (start);
	if (start == finish && array[start] != value)
		return (-1);

	if (value == array[start] && value == array[finish])
	{
		if (value == array[start - 1])
			return (recursive_binary(array, start - 1, finish, value));
		return (start);
	}
	mid = (start + finish) / 2;
	if (value > array[mid])
	{
		return (recursive_binary(array, mid + 1, finish, value));
	}
	else
	{
		return (recursive_binary(array, start, mid, value));
	}
}
/**
 * print_array - prints array or subarray we are going to use to binary search
 *
 * @array: sorted array of int.
 * @start: starting index of the subarray
 * @finish: finishing index of the subarray
 *
 * Return: void.
 */
void print_array(int *array, size_t start, size_t finish)
{
	size_t i;

	printf("Searching in array: ");
	for (i = start; i < finish; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
}
