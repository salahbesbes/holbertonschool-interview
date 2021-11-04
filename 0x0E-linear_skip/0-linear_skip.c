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
	int diff = 0;
	size_t express_distance = 0;

	if (list == NULL)
		return (NULL);
	if (list->express)
		express_distance = list->express->index - list->index;
	current = list;
	while (current)
	{
		printCheck(current);

		if (current->express)
			diff = current->express->n - current->n;
		if (value < current->n + diff || current->express == NULL)
		{
			if (current->express == NULL)
				express_distance--;
			printf("Value found between indexes [%lu] and [%lu]\n", current->index, current->index + express_distance);
			while (current)
			{
				printCheck(current);
				if (value == current->n)
				{
					return (current);
				}
				current = current->next;
			}
		}

		current = current->express;
	}

	return (NULL);
}
