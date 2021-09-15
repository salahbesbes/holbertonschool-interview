#include "lists.h"

/**
 * check_cycle - check if the single list is cycled
 * @list: head of list
 *
 * Return: 1 if cycled, 0 if it is normal list
 */
int check_cycle(listint_t *list)
{

	listint_t *hare, *turtle;

	if (list == NULL || list->next == NULL)
		return (0);
	turtle = list;
	hare = list->next->next;

	while (turtle != hare)
	{
		if (hare == NULL || hare->next == NULL)
			return (0);
		hare = hare->next->next;
		turtle = turtle->next;
	}

	return (1);
}
