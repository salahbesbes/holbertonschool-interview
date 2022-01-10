
#include "lists.h"
#include <stdio.h>

/**
 * find_listint_loop - find loop
 * @head: head list
 *
 * Return: Null or node
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *turtle, *rabbit;

	turtle = head;
	rabbit = head->next->next;

	if (!head | !head->next)
		return (NULL);
	while (rabbit && rabbit->next)
	{
		if (turtle == rabbit || turtle == rabbit->next)
		{
			return (turtle);
		}
		else if (rabbit->next->next->n == turtle->n)
		{
			return (rabbit->next);
		}
		turtle = turtle->next;
		rabbit = rabbit->next->next;
	}

	return (NULL);
}
