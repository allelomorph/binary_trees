/* 30. Is AVL */
#include "binary_trees.h"
#include <limits.h>


#ifndef MAX_INT
#define MAX_INT

/**
 * max_int - finds larger of two int values
 * @a: first value to compare
 * @b: second value to compare
 * Return: larger int value, or value of both if equal
 */
inline int max_int(int a, int b)
{
	return ((a > b) ? a : b);
}

#endif


/**
 * BST_is_AVL_balanced - measures the balance factor of a binary tree
 *
 * @tree: root node from which to measure
 * Return: height of `tree` left subtree minus height of right subtree,
 * or 0 if `tree` is NULL
 */
avl_data_t BST_is_AVL_balanced(const binary_tree_t *tree)
{
	avl_data_t left, right, node;
	int bal_factor;

	if (!tree)
	{
		node.height = -1;
		node.is_AVL = 1;
		return (node);
	}

	left = BST_is_AVL_balanced(tree->left);
	right = BST_is_AVL_balanced(tree->right);

	node.height = 1 + max_int(left.height, right.height);

	bal_factor = right.height - left.height;
	if (bal_factor < -1 || bal_factor > 1)
		node.is_AVL = 0;
	else
		node.is_AVL = left.is_AVL && right.is_AVL;

	return (node);
}


/**
 * tree_is_BST - recursive helper to binary_tree_is_bst
 * @tree: tree to check for BST
 * @prev: pointer to int, passed "by reference" to update during recursion
 * Return: 1 valid if `tree` is valid BST, or 0 if not or `tree` is NULL
 */
int tree_is_BST(const binary_tree_t *tree, int *prev)
{
	if (tree)
	{
		/*
		 * in-order traversal: recurse left, test, recurse right
		 * branching left tests against prev inherited from parent
		 * while branching right tests against prev = parent->n
		 */
		if (!tree_is_BST(tree->left, prev))
			return (0);

		/*
		 * checks both for repeat values and for left_child < parent
		 * and right_child > parent
		 */
		if (tree->n <= *prev)
			return (0);

		/* prev updates to current */
		*prev = tree->n;

		return (tree_is_BST(tree->right, prev));
	}
	/* recursion has reached an edge of the tree */
	return (1);
}


/**
 * binary_tree_is_avl - uses recursive helper to test first if binary tree
 * is a Binary Search tree:
 * - left subtree of each node only has values less than node
 * - right subtree of each node only has values greater than node
 * - tree is a BST at each node
 * - no repeat values in this implementation
 * then if tree is an AVL tree:
 * - balance factor is between -1 and 1 at every node (no more than 1 level
 * height difference between n->left and n->right)
 *
 * @tree: tree to check for AVL
 * Return: 1 valid if `tree` is valid AVL, or 0 if not or `tree` is NULL
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int prev = INT_MIN;

	if (!tree)
		return (0);

	if (!tree_is_BST(tree, &prev))
		return (0);

	return (BST_is_AVL_balanced(tree).is_AVL);
}
