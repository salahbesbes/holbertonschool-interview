#include "lists.h"

/**
 * get_node_number - get the value of the node at some position
 * @head: header node
 * @node_Number: position where to stop
 *
 * Return: value of some node at some position
 */
int get_node_number(listint_t **head, int node_Number)
{
	int counter = 1;
	listint_t *current;

	current = *head;
	while (counter != node_Number)
	{
		current = current->next;
		counter++;
	}

	return (current->n);
}

/**
 * get_list_length - get the length of the linked list
 * @head: header node
 *
 * Return: the length of linked list
 */
int get_list_length(listint_t **head)
{
	int length = 1;
	listint_t *current;

	current = *head;
	while (current->next)
	{
		current = current->next;
		length++;
	}

	return (length);
}

/**
 * is_palindrome - check if the linked list is palindromique
 * @head: header node
 *
 * Return: 1 if palindromique else 0
 */
int is_palindrome(listint_t **head)
{
	int mid_length, list_length, counter, odd_length, n_value;
	listint_t *current;

	if (head == NULL)
		return (1);

	if (*head == NULL)
		return (1);
	list_length = get_list_length(head);
	if (list_length == 1)
		return (1);
	odd_length = list_length % 2 == 0 ? 0 : 1;
	mid_length = list_length / 2;
	counter = 1;
	current = *head;

	while (counter != mid_length)
	{
		current = current->next;
		counter++;
	}

	if (odd_length)
		counter--;
	current = current->next;

	while (current)
	{

		n_value = get_node_number(head, counter);

		if (n_value == current->n)
		{
			current = current->next;
			counter--;
		}
		else
			return (0);
	}
	return (1);
}
