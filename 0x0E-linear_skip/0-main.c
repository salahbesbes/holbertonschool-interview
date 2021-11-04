#include <stdio.h>
#include <stdlib.h>

#include "search.h"

skiplist_t *create_skiplist(int *array, size_t size);
void print_skiplist(const skiplist_t *list);
void free_skiplist(skiplist_t *list);

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
	skiplist_t *list, *res;
	int array[] = {
		0, 1};
	size_t size = sizeof(array) / sizeof(array[0]);

	list = create_skiplist(array, size);
	print_skiplist(list);

	// res = linear_skip(list, 53);
	// printf("Found %d at index: %lu\n\n", 53, res->index);
	// res = linear_skip(list, 2);
	// printf("Found %d at index: %lu\n\n", 2, res->index);
	// res = linear_skip(list, 99);
	// printf("Found %d at index: %lu\n\n", 99, res->index);
	res = linear_skip(list, 0);
	printf("Found %d at index: %lu\n\n", 0, res->index);
	res = linear_skip(list, 1);
	printf("Found %d at index: %lu\n\n", 1, res->index);
	res = linear_skip(list, 999);
	printf("Found %d at index: %p\n", 999, (void *)res);
	return (EXIT_SUCCESS);
}
