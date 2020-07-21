#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect, meaning all
 * nodes except for leaves have two children
 * @tree: root node below which to check
 * Return: 1 if `tree` and all nodes below it each have 2 children, 0 if not or
 * if `tree` is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (tree->right && tree->left)
	{
		if ((!tree->left->left && !tree->left->right) &&
		    (!tree->right->left && !tree->right->right))
			return (1);

		return (binary_tree_is_perfect(tree->left) &&
			binary_tree_is_perfect(tree->right));
	}
	else
		return (0);
}
