#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/**
 * recursive_way - chech if node is at the position we search for
 * @head: pointer to list to be freed
 * @current: current node
 * @new: node to insert
 * @number: number to check for position
 * Return: new node inserted
 */
listint_t *recursive_way(listint_t **head, listint_t *current,
						 listint_t *new, int number)
{
	listint_t *tmp;

	if (number <= current->n)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	else if (current->next == NULL)
	{
		current->next = new;
		return (new);
	}
	else if (current->n <= number && current->next->n >= number)
	{
		tmp = current->next;
		current->next = new;
		new->next = tmp;
		return (new);
	}
	return (recursive_way(head, current->next, new, number));
}
/**
 * insert_node - recursive way
 * @head: pointer to list to be freed
 * @number: nuber to insert in the node
 * Return: new node inserted
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(listint_t));
	new->n = number;

	return (recursive_way(head, *head, new, number));
}

/*
	*listint_t *new, *current, *next_node, *tmp;

	current = *head;
	if (*head == NULL)
		return (NULL);
	new = malloc(sizeof(listint_t));
	new->n = number;
	next_node = current->next;
	if (current->n >= number)
	{
		new->next = current;
		*head = new;
		return (new);
	}
	if (next_node == NULL)
	{
		if (number >= current->n)
			current->next = new;
		else
		{
			new->next = current;
			*head = new;
		}
		return (new);
	}
	while (current->next != NULL)
	{
		next_node = current->next;
		if (number > current->n && number <= next_node->n)
		{
			printf("current %d next %d\n", current->n, next_node->n);
			tmp = current->next;
			current->next = new;
			new->next = tmp;
			return (new);
		}
		current = next_node;
	}
	current->next = new;
	return (new);
*/
