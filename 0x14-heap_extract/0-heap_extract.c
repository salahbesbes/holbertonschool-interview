#include <stdlib.h>
#include "binary_trees.h"


/**
 * depth - finds tree's depth
 * @root: root node of the tree
 * Return: depth of tree
 **/
int depth(heap_t *root)
{
	int right = 0;
	int left = 0;

	if (root == NULL)
		return (0);

	right = depth(root->right);
	left = depth(root->left);

	if (right > left)
		return (right + 1);
	else
		return (left + 1);
}

/**
 * node_search - Finds the first element after the root node
 * @root: root node of the tree.
 * Return: last element node before root.
 **/
heap_t *node_search(heap_t *root)
{
	if (root == NULL)
		return (NULL);

	if (!root->right && !root->left)
		return (root);

	if (depth(root->right) > depth(root->left))
		return (node_search(root->right));

	if (depth(root->left) > depth(root->right))
		return (node_search(root->left));

	return (node_search(root->right));
}


/**
 * siftDown - repairs the binary heap tree
 * @parent: parent node
 **/
void siftDown(heap_t **parent)
{
	heap_t *target = (*parent);
	int x;

	while ((target->left && target->n < target->left->n) ||
			(target->right && target->n < target->right->n))
	{
		if (target->right && target->left)
			target = target->left->n > target->right->n ? target->left : target->right;
		if (target->right && target->right->n > target->n)
			target = target->right;
		else if (target->left && target->left->n > target->n)
			target = target->left;

		x = target->parent->n;
		target->parent->n = target->n;
		target->n = x;

	}
}

/**
* heap_extract - extracts the root node of a Max Binary Heap
* @root: the root node of the binary root
* Return: the value stored in the root node, or 0 if the function
* fails
*/
int heap_extract(heap_t **root)
{
	int value;
	heap_t *tmp, *node;

	if (*root == NULL)
		return (0);
	value = (*root)->n;
	if (!(*root)->right && !(*root)->left)
	{
		free((*root));
		*root = NULL;
		return (value);
	}
	node = node_search((*root));

	if (node == NULL)
		return (0);
	tmp = (*root);
	if (tmp->left)
	{
		tmp->left->parent = node;
		node->left = tmp->left;
	}

	if (tmp->right)
	{
		tmp->right->parent = node;
		node->right = tmp->right;
	}

	if (node->parent->left && node->parent->left == node)
		node->parent->left = NULL;
	else if (node->parent->right && node->parent->right == node)
		node->parent->right = NULL;

	node->parent = tmp->parent;
	(*root) = node;
	free(tmp);
	siftDown(root);
	return (value);
}
