#include "list.h"

List *create_node(char *str)
{
	List *new_node = NULL;

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);
	new_node->str = strdup(str);
	return (new_node);
}

List *add_node_end(List **list, char *str)
{
	List *head, *last, *new;

	head = *list;

	new = create_node(str);
	if ((*list) == NULL)
	{
		*list = new;
		printf((*list)->str);
		(*list)->prev = NULL;
		(*list)->next = NULL;
		return (new);
	}
	last = (*list)->prev;

	if (last == NULL)
		last = (*list);
	new->next = *list;
	(*list)->prev = new;
	last->next = new;
	new->prev = last;

	return (new);
}
List *add_node_begin(List **list, char *str)
{
	List *new;

	new = add_node_end(list, str);
	(*list) = new;
	return (new);
}
