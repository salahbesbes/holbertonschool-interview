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

	skiplist_t *current, *old_express;
	size_t diff = 0;

	if (list == NULL)
		return (NULL);
	current = list;
	old_express = list;
	if (current->express)
		diff = current->express->index - current->index;
	while (current)
	{

		if (value < current->n)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
				   old_express->index, current->index);
			while (old_express)
			{
				printCheck(old_express);
				if (value == old_express->n)
				{
					return (old_express);
				}
				old_express = old_express->next;
				if (old_express == NULL)
					return (NULL);
			}
		}
		old_express = current;
		current = current->express;
		if (current == NULL)
		{
			if (diff < 3)
				printf("Value found between indexes [%ld] and [%lu]\n",
					   old_express->index - diff, old_express->index);
			else
				printf("Value found between indexes [%lu] and [%lu]\n",
					   old_express->index, old_express->index + diff - 1);

			while (old_express)
			{
				printCheck(old_express);
				if (value == old_express->n)
				{
					return (old_express);
				}
				old_express = old_express->next;
				if (old_express == NULL)
					return (NULL);
			}
		}
		else
			printCheck(current);
	}

	return (NULL);
}
