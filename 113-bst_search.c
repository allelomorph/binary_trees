/* 27. BST - Search */
#include "binary_trees.h"


/**
 * bst_search - recursively searches for a value in a Binary Search Tree
 *
 * @tree: pointer to the root node of the BST to search
 * @value: integer to search for
 * Return: node containing value, or NULL if not found or root is NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	if (value == tree->n)
		return ((bst_t *)tree);

	/* value not matching and no children left: value not in ordered tree */
	if (tree->left == NULL && tree->right == NULL)
		return (NULL);

	if (value < tree->n)
		return (bst_search(tree->left, value));

	/* value > tree->n */
	return (bst_search(tree->right, value));
}
