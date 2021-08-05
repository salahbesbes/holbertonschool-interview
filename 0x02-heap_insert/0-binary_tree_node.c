#include "binary_trees.h"
#include "stdlib.h"

/**
 * binary_tree_node - allocate new node using value
 * @parent: parent node on the new node
 * @value: value to save
 * Return: new Node allocated
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->parent = parent;
	new->n = value;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
