#include "binary_trees.h"
#include <stdlib.h>
#include <limits.h>

/**
 * max - returns maximum of two integers
 * @a: first integer
 * @b: second integer
 * Return: maximum integer
 */
int max(int a, int b)
{
	return ((a >= b) ? a : b);
}

/**
 * height - returns the height of binary tree
 * @node: node of binary tree
 * Return: height of binary tree
 */
int height(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	return (1 + max(height(node->left), height(node->right)));
}

/**
 * BST - checks if BST and compares values with minimum
 * and maximum tree values
 * @tree: binary tree
 * @min: minimum value
 * @max: maximum value
 * Return: 1 if ture, 0 otherwise
 */
int BST(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (BST(tree->left, min, tree->n - 1) &&
		BST(tree->right, tree->n + 1, max));
}

/**
 * tree_isBST - checks if a binary tree is a binary search tree
 * @tree: node from the binary tree
 * Return: 1 if ture, 0 otherwise
 */
int tree_isBST(const binary_tree_t *tree)
{
	return (BST(tree, INT_MIN, INT_MAX));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: binary tree
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_height;
	int right_height;

	if (tree == NULL)
		return (1);

	if (tree_isBST(tree))
	{
		left_height = height(tree->left);
		right_height = height(tree->right);

		if (abs(left_height - right_height) <= 1 && binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right))
			return (1);
	}

	return (0);
}
