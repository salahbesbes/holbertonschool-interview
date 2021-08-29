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
	listint_t *original_list, *rev_list, *copy_current_node;

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

	return (palind(*head, length_list));
}
/**
 * palind_recursive_way - check first node and last node recursively
 * @list: head single list
 * @length: length of list
 *
 * Return: 1 if plindromique else 0
 */
int palind_recursive_way(listint_t *list, int length)
{

	listint_t *newList, *last_node;
	int count = 1;

	if (length < 2)
		return (1);
	else if (length == 2)
		return (list->n == list->next->n);

	newList = list->next;
	last_node = newList;

	while (count < length - 2)
	{
		last_node = last_node->next;
		count++;
	}
	if (list->n == last_node->next->n)
	{
		last_node->next = NULL;
		return (palind(newList, length - 2));
	}
	return (0);
}
