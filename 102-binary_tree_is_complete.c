/* 21. Is complete  */
#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: root node from which to measure
 * Return: total of `tree` and all nodes below it, or 0 if `tree` is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	return (1 + binary_tree_size(tree->left) +
		binary_tree_size(tree->right));
}

/**
 * check_bt_complete - recursively checks if binary tree is complete (nodes
 * at each level except 2nd from last all have 2 children, level before last
 * can have less, but all leaves must be as far left as possible)
 * @tree: root node from which to measure
 * @i: iterator to mimic an array index while traversing tree
 * @size: total number of nodes in tree
 * Return: 1 if `tree` is complete, 0 if not or `tree` is NULL
 *
 * note: this scales `i` in a way that mimics the index values in an array
 * expression of the tree:
 *
 *         0
 *       /   \
 *      1     2
 *     / \   /
 *    3   4 5
 *
 * Since the indicies increment top to bottom, left to right, if there are any
 * in a position that is greater than or equal to (index starts at 0, size at
 * 1) the size, then we know they are not justified to the left.
 */
int check_bt_complete(const binary_tree_t *tree, size_t i, size_t size)
{
	if (!tree)
		return (1);

	if ((tree->left && (2 * i) + 1 >= size) ||
	    !check_bt_complete(tree->left, (2 * i) + 1, size))
		return (0);

	if ((tree->right && (2 * i) + 2 >= size) ||
	    !check_bt_complete(tree->right, (2 * i) + 2, size))
		return (0);

	return (1);
}

/**
 * binary_tree_is_complete - calls recursive helper to see if binary tree is
 * complete
 * @tree: root of tree or subtree
 * Return: 1 if `tree` is complete, 0 if not or `tree` is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (check_bt_complete(tree, 0, binary_tree_size(tree)));
}
