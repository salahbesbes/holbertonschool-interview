#include <stdio.h>
#include "sort.h"
// Function to swap the the position of two elements
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int arr[], int n, int i, int size)
{
	// Find largest among root, left child and right child
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	// Swap and continue heapifying if root is not largest
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		print_array(arr, size);
		heapify(arr, n, largest, size);
	}
}

// Main function to do heap sort
void heap_sort(int *arr, size_t n)
{
	// Build max heap
	for (int i = (int)n / 2 - 1; i >= 0; i--)
		heapify(arr, (int)n, i, (int)n);

	// Heap sort
	for (int i = (int)n - 1; i >= 0; i--)
	{
		swap(&arr[0], &arr[i]);
		print_array(arr, (int)n);
		// Heapify root element to get highest element at root again
		heapify(arr, i, 0, (int)n);
	}
}
