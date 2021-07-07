#include "binary_trees.h"


#ifndef MAX_INT
#define MAX_INT

/**
 * max_int - finds larger of two int values
 * @a: first value to compare
 * @b: second value to compare
 * Return: larger int value, or value of both if equal
 */
inline int max_int(int a, int b)
{
	return ((a > b) ? a : b);
}

#endif


/**
 * binary_tree_balance_height - measures the height of a binary tree
 * @tree: root node from which to measure, starting at 1
 * Return: count of root and levels below, or 0 if `tree` is NULL
 */
int binary_tree_balance_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	return (1 + max_int(binary_tree_balance_height(tree->left),
			    binary_tree_balance_height(tree->right)));
}


/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: root node from which to measure
 * Return: height of `tree` left subtree minus height of right subtree,
 * or 0 if `tree` is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_h, right_h;

	if (!tree)
		return (0);

	left_h = binary_tree_balance_height(tree->left);
	right_h = binary_tree_balance_height(tree->right);

	return (left_h - right_h);
}
