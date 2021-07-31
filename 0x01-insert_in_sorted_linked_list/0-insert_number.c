#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
    listint_t *current;
    listint_t *next_node;
    listint_t *tmp;
    current = *head;

    if (*head == NULL)
        return NULL;
    new = malloc(sizeof(listint_t));
    new->n = number;

    next_node = current->next;

    /* number is the smallest in the linkedList*/
    if (current->n >= number)
    {
        new->next = current;
        *head = new;
        return new;
    }

    /* Linked List only contain one Node*/
    if (next_node == NULL)
    {
        if (number >= current->n)
        {
            current->next = new;
        }
        else
        {
            new->next = current;
            *head = new;
        }
        return new;
    }

    /* linkedList contain one or make nodes */
    while (current->next != NULL)
    {
        next_node = current->next;
        if (number > current->n && number <= next_node->n)
        {
            printf("current %d next %d\n", current->n, next_node->n);
            tmp = current->next;
            current->next = new;
            new->next = tmp;
            return new;
        }
        current = next_node;
    }
    current->next = new;
    return new;
}
