#include "list.h"

List *create_node(char *str)
{
	List *new_node = NULL;

	new_node = malloc(sizeof(List));
	new_node->str = strdup(str);
	if (!new_node->str)
		return (NULL);
	return (new_node);
}

List *add_node_end(List **list, char *str)
{
	List *last, *new;

	if (!str)
		return (NULL);
	new = create_node(str);
	if (new == NULL)
		return (NULL);
	if (!list || !(*list))
	{
		*list = new;
		(*list)->prev = new;
		(*list)->next = new;
		return (new);
	}
	last = (*list)->prev;

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
	if (new == NULL)
		return (NULL);
	(*list) = new;
	return (new);
}
