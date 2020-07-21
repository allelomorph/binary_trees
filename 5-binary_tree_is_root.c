#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if binary tree node is a root, meaning it has
 * no parents
 * @node: node to evaluate
 * Return: 1 if `node` is root, 0 if not, or if `node` is NULL
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (node->parent)
		return (0);
	else
		return (1);
}
