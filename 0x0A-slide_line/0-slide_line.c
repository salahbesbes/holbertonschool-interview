#include "slide_line.h"

#define Pass 0
#define Merge 1
#define Slide 2

/**
 * getFirstIndexToLeft - get the index of the first int to the left in the arr
 * @arr: array
 * @currentIndex: index
 *
 * Return: index of first int to the left
 */
int getFirstIndexToLeft(int *arr, int currentIndex)
{
	currentIndex--;
	while (arr[currentIndex] == 0)
	{
		currentIndex--;
	}

	return (currentIndex < 0 ? -1 : currentIndex);
}
/**
 * getFirstIndexToRight - get the index of the first int to the Right in the arr
 * @arr: array
 * @currentIndex: index
 * @size: length of array
 *
 * Return: index of first int to the Right
 */
int getFirstIndexToRight(int *arr, int currentIndex, int size)
{
	currentIndex++;
	if (currentIndex >= size - 1)
		return (size - 1);
	while (arr[currentIndex] == 0)
	{
		currentIndex++;
	}

	return (currentIndex);
}

/**
 * slideAllLeft - get ride of the 0 in the array
 * @arr: array
 * @size: size of the array
 *
 * Return: new slidePosition
 */
int slideAllLeft(int *arr, int size)
{
	int i = 0, slideIndex = 0;

	slideIndex = getFirstIndexToLeft(arr, 1) + 1;
	for (i = 1; i < size; i++)
	{
		if (arr[i] > 0)
		{
			slideIndex = slideLeft(arr, slideIndex, i);
		}
	}

	return (slideIndex);
}
/**
 * slideAllRight - get ride of the 0 in the array
 * @arr: array
 * @size: size of the array
 *
 * Return: new slidePosition
 */
int slideAllRight(int *arr, int size)
{
	int i = 0, slideIndex = 0;

	slideIndex = getFirstIndexToRight(arr, size - 2, size) - 1;
	for (i = size - 2; i >= 0; i--)
	{
		if (arr[i] > 0)
		{
			slideIndex = slideRight(arr, slideIndex, i);
		}
	}

	return (slideIndex);
}

/**
 * mergeLeft - merge to 2 integer to the left in the array
 * @arr: array
 * @currentidex: index
 *
 * Return: void
 */
void mergeLeft(int *arr, int currentidex)
{

	arr[currentidex - 1] += arr[currentidex];
	arr[currentidex] = 0;
}
/**
 * mergeRight - merge to 2 integer to the Right in the array
 * @arr: array
 * @currentidex: index
 *
 * Return: void
 */
void mergeRight(int *arr, int currentidex)
{

	arr[currentidex] += arr[currentidex - 1];
	arr[currentidex - 1] = 0;
}

/**
 * checkForMergeLeft - check if we have 2 int to merge from the left
 * @arr: array
 * @size: length of array
 *
 * Return: void
 */
void checkForMergeLeft(int *arr, int size)
{
	int i = 0;

	for (i = 1; i < size; i += 2)
	{
		if (arr[i] == arr[i - 1])
			mergeLeft(arr, i);
	}
	if (size % 2 == 1)
	{
		if (arr[size - 1] == arr[size - 3])
			mergeLeft(arr, size - 1);
	}
}
/**
 * checkForMergeRight - check if we have 2 int to merge from the right
 * @arr: array
 * @size: length of array
 *
 * Return: void
 */
void checkForMergeRight(int *arr, int size)
{
	int i = 0;

	for (i = size - 1; i >= 0; i -= 2)
	{
		if (arr[i] == arr[i - 1])
			mergeRight(arr, i);
	}
}

/**
 * slide_line - handle sigle line of the 2084 game
 * @line: array
 * @size: length of array
 * @direction: left or right
 *
 * Return: 1 or 0
 */
int slide_line(int *line, size_t size, int direction)
{
	int mergeIndex, slideIndex, res, i, newArraySize;

	if (direction == SLIDE_LEFT)
	{

		newArraySize = slideAllLeft(line, size);
		checkForMergeLeft(line, newArraySize);
		newArraySize = slideAllLeft(line, size);
	}
	else if (direction == SLIDE_RIGHT)
	{
		newArraySize = slideAllRight(line, size);
		checkForMergeRight(line, size);
		newArraySize = slideAllRight(line, size);
	}

	return 1;
}
