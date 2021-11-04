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
	skiplist_t *current;
	size_t lastIndex;

	if (list == NULL)
		return (NULL);
	current = list;
	while (current->next)
		current = current->next;
	lastIndex = current->index;
	current = list;
	while (current->express)
	{
		printCheck(current->express);
		if (value < current->express->n)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
				   current->index, current->express->index);
			break;
		}
		current = current->express;
	}
	if (current->express == NULL)
	{
		printf("Value found between indexes [%lu] and [%lu]\n",
			   current->index, lastIndex);
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
