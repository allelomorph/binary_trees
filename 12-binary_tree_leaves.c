#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves (terminal nodes) in a binary tree
 * @tree: root node from which to measure
 * Return: total leaves at or below `tree`, or 0 if `tree` is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	return (binary_tree_leaves(tree->left) +
		binary_tree_leaves(tree->right));
}
