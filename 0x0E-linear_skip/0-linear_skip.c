#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 *
 * @list: pointer to the head of the skip list to search in.
 * @value: value to search for.
 *
 * Return: node that contains the value, NULL if fails.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	size_t i, x, ex;
	int n;
	skiplist_t *current, *express;
	char *msg;

	msg = "Value found between indexes";
	if (!list)
		return (NULL);
	current = list;
	while (current)
	{
		if (current->express)
			express = current->express;
		else
		{
			express = current;
			while (express && express->next)
				express = express->next;
			i = current->index;
			x = express->index;
			printf("%s [%lu] and [%lu]\n", msg, i, x);
			return (search(current, value));
		}
		ex = express->index;
		n = express->n;
		printf("Value checked at index [%lu] = [%d]\n", ex, n);
		if (express->n >= value)
		{
			i = current->index;
			x = express->index;
			printf("%s [%lu] and [%lu]\n", msg, i, x);
			return (search(current, value));
		}
		if (current->express)
			current = current->express;
		else
			break;
	}
	return (NULL);
}
/**
 * search - searchs in the nodes between the current and express.
 *
 * @list: pointer to the head
 * @value: value to search for
 *
 * Return: node or Null
 */
skiplist_t *search(skiplist_t *list, int value)
{
	skiplist_t *c;

	for (c = list; c; c = c->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", c->index, c->n);
		if (c->n == value)
			return (c);
	}
	return (NULL);
}
