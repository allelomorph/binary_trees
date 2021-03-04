/* 28. BST - Remove  */
#include "binary_trees.h"

/* free */
#include <stdlib.h>

#include <stdio.h>

/**
 * bst_find_min - find minimum value in a Binary Search Tree
 *
 * @tree: BST root or subtree
 * Return: node of the tree containing minimum value, or NULL if tree is NULL
 */
static bst_t *bst_find_min(bst_t *tree)
{
	bst_t *temp = NULL;

	temp = tree;
	while (temp && temp->left)
		temp = temp->left;

	return (temp);
}


/**
 * bst_remove - removes a node from a Binary Search Tree
 * notes:
 * - when a node with two children is removed, it will always be replaced
 * with its first in-order successor (not predecessor) (first in-order
 * successor is the right subtree's left-most child)
 * - this could potentially lead to an unbalanced tree, and some
 * implementations selectively alternate between in-order successor and
 * predecessor
 *
 * @root: pointer to the root node of tree which will have a node removed
 * @value: value to remove from tree
 * Return: new root node of the tree after removing the desired value,
 * or NULL on failure
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp = NULL;

	if (!root)
		return (NULL);
	if (value < root->n)
	{ /* recurse to left subtree */
		root->left = bst_remove(root->left, value);
		if (root->left)
			root->left->parent = root;
	}
	else if (value > root->n)
	{ /* recurse to right subtree */
		root->right = bst_remove(root->right, value);
		if (root->right)
			root->right->parent = root;
	}
	else
	{ /* value match, deleting this node */
		if (root->left == NULL)
		{ /* right child only, or no children */

			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{ /* left child only */
			temp = root->left;
			free(root);
			return (temp);
		}
		/* node with two children: get the in-order successor */
		temp = bst_find_min(root->right);
		root->n = temp->n; /* copy the in-order successor's content */
		/* delete the in-order successor */
		root->right = bst_remove(root->right, temp->n);
		if (root->right)
			root->right->parent = root;
	}
	return (root);
}
