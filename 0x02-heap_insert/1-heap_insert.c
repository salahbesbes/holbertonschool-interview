#include "binary_trees.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

/**
 * sibling - return node sibling
 * @node: Node
 * Return:  sibling node or null
 */
binary_tree_t *sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->right == node)
		return (node->parent->left);
	else
		return (node->parent->right);
}

/**
 * sort_node - sort all nodes from the parent level to the up to the root
 * @parent: parent Node
 * @new: new node to insert
 * @value: to inset
 * Return: new node
 */

heap_t *sort_node(heap_t *parent, heap_t *new, int value)
{
	if (parent->n < value)
	{
		new->n = parent->n;
		parent->n = value;
		if (parent->parent != NULL)
		{
			return (sort_node(parent->parent, parent, value));
		}
		return (parent);
	}
	return (new);
}

/**
 * insert_node - Insert the newNode as last leaf from left to right
 * @parent: parent node
 * @value: value to insert
 * Return: new node to insert
 */

heap_t *insert_node(heap_t *parent, int value)
{
	heap_t *new, *sibling_node;
	int nodes_empty = 0;

	if (parent->left == NULL)
	{
		new = binary_tree_node(parent, value);
		parent->left = new;
		return (sort_node(parent, new, value));
	}
	else if (parent->right == NULL)
	{
		new = binary_tree_node(parent, value);
		parent->right = new;
		return (sort_node(parent, new, value));
	}
	else
	{
		if (parent->parent == NULL)
		{
			return (insert_node(parent->left, value));
		}
		sibling_node = sibling(parent);
		if (sibling_node->left == NULL)
		{
			new = binary_tree_node(sibling_node, value);
			sibling_node->left = new;
			return (sort_node(sibling_node, new, value));
		}
		else if (sibling_node->right == NULL)
		{
			new = binary_tree_node(sibling_node, value);
			sibling_node->right = new;
			return (sort_node(sibling_node, new, value));
		}
		else
		{
			return (insert_node(parent->left, value));
		}
	}
}

/**
 * heap_insert - inset new node to the tree
 * @root: root Node
 * @value: value to insert
 * Return: new Node to insert
 */

heap_t *heap_insert(heap_t **root, int value)
{

	if (*root == NULL)
	{
		*root = binary_tree_node(*root, value);
		return (*root);
	}
	else
	{
		return (insert_node(*root, value));
	}
}
