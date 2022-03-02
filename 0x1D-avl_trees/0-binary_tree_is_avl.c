#include "binary_trees.h"
#include <limits.h>
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
 * isBST - check if the tree is bst
 *
 * @tree: root
 * @min: min val
 * @max: max val
 * Return: 1 if true else 0
 */
int isBST(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (isBST(tree->left, min, tree->n - 1) &&
		isBST(tree->right, tree->n + 1, max));
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

	if (tree == NULL)
		return (1);
	if (!(tree->left) && !(tree->right))
		return (1);
	if (isBST(tree, INT_MIN, INT_MAX))
	{
		left = height(tree->left);
		right = height(tree->right);
		if (abs(right - left) <= 1)
		{
			if (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right))
			{
				return (1);
			}
		}
	}
	return (0);
}
