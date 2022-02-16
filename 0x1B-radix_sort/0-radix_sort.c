#include "sort.h"

/**
 * radix_sort - radis sort
 * @array: array
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{

	int i, bucket[10], maxVal = 0, digitPosition = 1, arraySize = size;

	for (i = 0; i < arraySize; i++)
	{
		if (array[i] > maxVal)
			maxVal = array[i];
	}

	/* if maxVal is 3 digits, then we loop through 3 times */
	while (maxVal / digitPosition > 0)
	{
		/* reset counter */
		int digitCount[10] = {0};

		/* count pos-th digits (keys) */
		for (i = 0; i < arraySize; i++)
			digitCount[array[i] / digitPosition % 10]++;

		/* accumulated count */
		for (i = 1; i < 10; i++)
			digitCount[i] += digitCount[i - 1];

		/* To keep the order, start from back side */
		for (i = arraySize - 1; i >= 0; i--)
		{
			bucket[--digitCount[array[i] / digitPosition % 10]] = array[i];
		}

		/* rearrange the original array using elements in the bucket */
		for (i = 0; i < arraySize; i++)
			array[i] = bucket[i];

		/* at this point, a array is sorted by digitPosition-th digit */
		print_array(array, arraySize);

		/* move up the digit position */
		digitPosition *= 10;
	}
}
