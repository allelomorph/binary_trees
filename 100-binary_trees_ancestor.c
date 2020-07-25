/* task 19. Lowest common ancestor */
#include "binary_trees.h"

/**
 * bt_find_lca - recurses downstream into a binary tree to find lowest common
 * ancestor (LCA)
 * @root: node to recursively check below
 * @first: first of two descendants, or nodes to backtrack from
 * @second: second descendant
 * Return: LCA if found, NULL if not or if `root` is NULL
 */
binary_tree_t *bt_find_lca(binary_tree_t *root, const binary_tree_t *first,
			   const binary_tree_t *second)
{
	binary_tree_t *left_search, *right_search;

	/* recursion reaches edge of leaf */
	if (!root)
		return (NULL);

	/* current node is one of our descendants */
	if (root == first || root == second)
		return (root);

	left_search = bt_find_lca(root->left, first, second);
	right_search = bt_find_lca(root->right, first, second);

	/* current node is a shared ancestor of pair */
	if (left_search && right_search)
		return (root);

	/**
	 * for subtrees deeper (and recursion frames higher) than LCA:
	 * -- pass descendants back down stack to the if(left && right) test.
	 *
	 * for root and subtrees shallower than LCA:
	 * -- once found, pass the LCA back down the stack
	 */
	if (left_search != NULL)
		return (left_search);
	else
		return (right_search);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: first of two descendants, or nodes to backtrack from
 * @second: second descendant
 * Return: pointer to node that is lowest common ancestor, or NULL if none
 * is found or either `first` or `second` is NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *root = (binary_tree_t *)first;

	while (root->parent)
		root = root->parent;

	return (bt_find_lca(root, first, second));
}
