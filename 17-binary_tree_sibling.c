#include "binary_trees.h"

/**
 * binary_tree_sibling - finds 'sibling' to a node, sharing the same parent
 * @node: node to check
 * Return: pointer to node sharing same parent as `node`, or NULL if none found
 * or `node` is NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node)
		return (NULL);

	if (node->parent)
	{
		if (node->parent->left == node)
			return (node->parent->right);
		if (node->parent->right == node)
			return (node->parent->left);
	}
	return (NULL);
}
