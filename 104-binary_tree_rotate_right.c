/* 22. Rotate right */
#include "binary_trees.h"

/**
 * binary_tree_rotate_right - R child of root becomes new root, tree rotated
 * so it retains BST ordering of values (in-order traversal of leaves is same)
 * @tree: tree to right rotate
 * Return: pointer to new root node, or NULL if `root` is NULL
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (!tree)
		return (NULL);

	/* pivot will become new root */
	pivot = tree->left;

	/* migrate children to keep BST order */
	tree->left = pivot->right;
	if (pivot->right)
		pivot->right->parent = tree;

	/* handle upstream connections if `tree` is a subtree */
	pivot->parent = tree->parent;
	if (tree->parent)
	{
		if (tree == tree->parent->right)
			tree->parent->right = pivot;
		else
			tree->parent->left = pivot;
	}

	/* finally rotate pivot into root postion */
	pivot->right = tree;
	tree->parent = pivot;

	return (pivot);
}
