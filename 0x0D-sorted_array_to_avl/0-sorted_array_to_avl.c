#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: a pointer to the parent node
 * @value: the value in the node
 *
 * Return: a pointer to the new node, otherwise null
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
	{
		return (NULL);
	}
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->n = value;
	return (new_node);
}

/**
 * insert_node - inserts node recursively
 * @array: a pointer to the first elemetn
 * @parent: a pointer to the root of tree
 * @start: the start index
 * @end: the end index
 *
 * Return: a pointer to the new node
 */
avl_t *insert_node(int *array, avl_t *parent, int start, int end)
{
	int middle;
	avl_t *new;

	if (start > end)
		return (NULL);
	middle = (start + end) / 2;
	new = binary_tree_node(parent, array[middle]);
	new->left = insert_node(array, new, start, middle - 1);
	new->right = insert_node(array, new, middle + 1, end);

	return (new);
}

/**
 * sorted_array_to_avl - builds an AVL tree from sorted array
 * @array: Is a pointer to the first element of the array
 * @size: Is the number of element in the array
 *
 * Return: a pointer to the root node of the created AVL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	int start = 0;
	int end = size - 1;
	int middle = (end + start) / 2;

	if (!array)
		return (NULL);
	root = binary_tree_node(NULL, array[middle]);
	root->left = insert_node(array, root, start, middle - 1);
	root->right = insert_node(array, root, middle + 1, end);
	return (root);
}
