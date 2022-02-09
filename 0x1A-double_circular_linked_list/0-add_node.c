#include "list.h"

List *create_node(char *str)
{
	List *new_node = NULL;

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);
	new_node->str = strdup(str);
	new_node->next = NULL;
	new_node->prev = NULL;
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
	List *last, *new, *head;

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
	head = *list;
	last = (*list)->prev;

	new->next = *list;
	new->prev = last;
	last->next = new;
	head->prev = new;

	*list = new;

	return (new);
}
