#include "lists.h"

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
 * inverse_list - inverse a linked list
 * @head: header node
 *
 * Return: reversed linked list
 */
listint_t *inverse_list(listint_t *head)
{
	listint_t *original_list, *rev_list, *copy_current_node, *next_rev_node;

	original_list = head;
	original_list = original_list->next;

	rev_list = head;
	rev_list->next = NULL;

	while (original_list)
	{
		copy_current_node = original_list;
		original_list = original_list->next;
		copy_current_node->next = rev_list;
		rev_list = copy_current_node;
	}
	return (rev_list);
}
/**
 * is_palindrome - check if the linked list is palindromique
 * @head: header node
 *
 * Return: 1 if palindromique else 0
 */
int is_palindrome(listint_t **head)
{
	listint_t *original_list, *rev_list;
	int mid_length, length_list, count, odd_length;
	/* linked list empty or contain single node return 1 */
	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return (1);
	length_list = get_list_length(head);
	mid_length = length_list / 2;
	odd_length = length_list % 2 == 0 ? 0 : 1;
	original_list = *head;
	count = 0;
	while (count != mid_length - 1)
	{
		original_list = original_list->next;
		count++;
	}
	if (odd_length == 0)
	{
		if (original_list->n != original_list->next->n)
			return (0);
	}

	rev_list = inverse_list(*head);
	original_list = *head;

	while (original_list)
	{
		if (rev_list->n != original_list->n)
			return (0);
		rev_list = rev_list->next;
		original_list = original_list->next;
	}

	return (1);
}
