#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
#include <limits.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	listint_t *head;

	head = NULL;
	// add_nodeint_end(&head, -5);
	// // add_nodeint_end(&head, -5);
	// add_nodeint_end(&head, -3);
	// add_nodeint_end(&head, 3);
	// add_nodeint_end(&head, 4);
	// add_nodeint_end(&head, 98);
	// add_nodeint_end(&head, 402);
	// add_nodeint_end(&head, 1024);

	// insert_node(&head, -1024);
	// insert_node(&head, 999);
	// insert_node(&head, 957);
	// insert_node(&head, 1000);
	print_listint(head);

	printf("-----------------\n");

	insert_node(&head, INT_MAX);
	insert_node(&head, INT_MIN);
	insert_node(&head, INT_MIN);
	insert_node(&head, INT_MIN);
	insert_node(&head, INT_MAX);
	insert_node(&head, INT_MIN);

	print_listint(head);

	free_listint(head);

	return (0);
}
