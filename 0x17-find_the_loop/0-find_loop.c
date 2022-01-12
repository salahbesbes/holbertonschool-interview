
#include "lists.h"
#include <stdio.h>

/**
 * loopExistAndHeadExistInIt - loopExistAndHeadExistInIt
 * @head: head of list
 *
 * Return: Null if not loop found or the head where it is included in the loop
 */
listint_t *loopExistAndHeadExistInIt(listint_t *head)
{
	listint_t *turtle, *rabbit;

	turtle = head;
	rabbit = head->next;

	if (!head || !head->next)
		return (NULL);
	if (rabbit->next == head)
		return (head);
	while (rabbit && rabbit->next)
	{
		if (rabbit == turtle)
		{
			rabbit = rabbit->next;
			while (rabbit != turtle)
			{
				if (rabbit == head)
					return (head);
				rabbit = rabbit->next;
			}
			return (loopExistAndHeadExistInIt(head->next));
		}
		turtle = turtle->next;
		rabbit = rabbit->next->next;
	}

	return (NULL);
}
/**
 * find_listint_loop - find loop
 * @head: head list
 *
 * Return: Null or node
 */
listint_t *find_listint_loop(listint_t *head)
{

	return (loopExistAndHeadExistInIt(head));
}
