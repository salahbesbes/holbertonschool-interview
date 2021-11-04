#include "search.h"

/**
 * printCheck - print comparison
 * @current: current node to compair to
 * Return: Void
 */
void printCheck(skiplist_t *current)
{
	printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
}

/**
 * linear_skip - print comparison
 * @list: head of express layer
 * @value: value to searh for
 * Return: Node founded ot Null
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{

	skiplist_t *current, *old_express, *next_express;
	size_t diff = 1;

	if (list == NULL)
		return (NULL);
	current = list;
	old_express = list;
	next_express = list->express;
	while (current->express)
	{
		printCheck(current->express);
		if (value < current->express->n)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
				   current->index, current->express->index);
			break;
		}
		old_express = current;
		current = current->express;
	}
	diff = current->index - old_express->index;
	next_express = current->express;
	if (next_express == NULL)
	{
		printf("Value found between indexes [%lu] and [%lu]\n",
			   current->index, current->index);
	}
	while (current)
	{
		printCheck(current);
		if (current->n == value)
			return (current);
		current = current->next;
	}

	return (NULL);
}
