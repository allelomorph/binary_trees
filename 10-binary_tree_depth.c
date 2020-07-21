#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: node from which to measure backwards, starting at 0
 * Return: levels from root, or 0 if `tree` is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (!tree)
		return (0);

	for (depth = 0; tree->parent; depth++)
		tree = tree->parent;

	return (depth);
}
