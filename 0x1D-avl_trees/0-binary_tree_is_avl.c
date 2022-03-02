#include "binary_trees.h"

/**
 * max - get the max value
 *
 * @a: val
 * @b: val
 * Return: int
 */
int max(int a, int b)
{
	return ((a > b) ? a : b);
}

/**
 * height- get the height of root node
 *
 * @N: node
 * Return: int
 */
int height(const binary_tree_t *N)
{
	if (N == NULL)
		return (0);
	return (1 + max(height(N->left), height(N->right)));
}
/**
 * rightHeight - calculate the length of the right side of the root
 *
 * @N: root node
 * Return: int
 */
int rightHeight(const binary_tree_t *N)
{
	int right;

	if (N == NULL)
		return (0);
	right = height(N->right);
	return (1 + right);
}

/**
 * leftHeight - calculate length of the left side of the root node
 *
 * @N: root node
 * Return: int
 */
int leftHeight(const binary_tree_t *N)
{
	int left;

	if (N == NULL)
		return (0);
	left = 1 + height(N->left);
	return (left);
}

/**
 * binary_tree_is_avl - check if th etree is avl
 *
 * @tree: node
 * Return: int
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{

	int left, right;

	left = leftHeight(tree);
	right = rightHeight(tree);
	if (right - left != 0)
		return (0);
	return (1);
}
