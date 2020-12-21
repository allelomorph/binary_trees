/* 20. Level-order traversal  */
#include "binary_trees.h"

/**
 * max_size_t - finds larger of two size_t values
 * @a: first value to compare
 * @b: second value to compare
 * Return: larger size_t value, or value of both if equal
 */
size_t max_size_t(size_t a, size_t b)
{
	return ((a > b) ? a : b);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: root node from which to measure, starting at 0
 * Return: levels from root, or 0 if `tree` is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (0);

	return (1 + max_size_t(binary_tree_height(tree->left),
			       binary_tree_height(tree->right)));
}

/**
 * operate_on_level - recurses to a given level (depth) of a binary tree to
 * apply `func` to each node's value
 * @tree: root of tree or subtree
 * @lvl: depth in tree to recurse to, starting at 0 for `root`
 * @func: pointer to function to apply to all nodes at level `lvl`
 */
void operate_on_level(const binary_tree_t *tree, size_t lvl, void (*func)(int))
{
	if (!tree || !func)
		return;

	if (lvl == 0)
		func(tree->n);
	else
	{
		operate_on_level(tree->left, lvl - 1, func);
		operate_on_level(tree->right, lvl - 1, func);
	}
}

/**
 * binary_tree_levelorder - applies function to each node in a binary tree
 * using level-order traversal, making iterative calls to a helper
 * @tree: root of tree or subtree
 * @func: pointer to function to be applied
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t tree_h, i;

	if (!tree || !func)
		return;

	tree_h = binary_tree_height(tree);

	for (i = 0; i <= tree_h; i++)
		operate_on_level(tree, i, func);
}
