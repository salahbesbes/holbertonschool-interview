#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "search.h"

/**
* printN - Initializes the express lane of the linked list
*
* @node: Pointer to the head node of the list
*
* Return: A pointer to the head of the created list (NULL on failure)
*/
int printN(skiplist_t *node)
{
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	return (node->n);
}

/**
* linear_skip - Initializes the express lane of the linked list
*
* @list: Pointer to the head node of the list
* @value: Number of nodes in the list
*
* Return: A pointer to the head of the created list (NULL on failure)
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *copy, *lastExp;
	int len;

	len = 0;
	copy = list;
	lastExp = list;
	node = list;
	while (node)
	{
		len++;
		node = node->next;
	}
	if (!list)
		return (NULL);
	while (copy->express)
	{
		copy = copy->express;
		if (value <= printN(copy))
		{
			printf("Value found between indexes [%ld] and [%ld]\n", lastExp->index, copy->index);
			while (lastExp->index <= copy->index)
			{
				if (value == printN(lastExp))
					return (lastExp);
				lastExp = lastExp->next;
			}
			return (NULL);
		}
		lastExp = copy;
	}
	printf("Value found between indexes [%ld] and [%d]\n", copy->index, len);
	while (copy)
	{
		if (value == printN(copy))
			return (copy);
		copy = copy->next;
	}
	return (NULL);
}
