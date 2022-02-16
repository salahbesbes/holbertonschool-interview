#include "sort.h"

/**
 * radix_sort - radis sort
 * @array: array
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{

	int i, *result, maxVal = 0, digitPosition = 1, arraySize = size;
	int *digitCount;

	if (size == 1)
		return;
	result = malloc((sizeof(int) * arraySize));
	if (result == NULL)
		return;
	for (i = 0; i < arraySize; i++)
	{
		if (array[i] > maxVal)
			maxVal = array[i];
	}
	while (maxVal / digitPosition > 0)
	{
		digitCount = malloc((sizeof(int) * 100));
		if (digitCount == NULL)
			break;
		for (i = 0; i < 10; ++i)
			digitCount[i] = 0;
		for (i = 0; i < arraySize; i++)
			digitCount[array[i] / digitPosition % 10]++;

		for (i = 1; i < 10; i++)
			digitCount[i] += digitCount[i - 1];

		for (i = arraySize - 1; i >= 0; i--)
		{
			result[--digitCount[array[i] / digitPosition % 10]] = array[i];
		}
		for (i = 0; i < arraySize; i++)
			array[i] = result[i];
		print_array(array, arraySize);
		digitPosition *= 10;
		free(digitCount);
	}
	free(result);
}
