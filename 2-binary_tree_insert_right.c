#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_right - inserts a `binary_tree_t` node as the right-child
 * of another node, or if `parent` "A" already has a right-child "B", then new
 * node "C" takes its place, and the old right-child becomes right-child of new
 * node  ( A-> C-> B )
 * @parent: pointer of node into which right-child is inserted
 * @value: integer stored in new node
 * Return: pointer to new node, or NULL on failure or if `parent` is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	if (parent->right)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}
	else
		new_node->right = NULL;
	new_node->left = NULL;
	parent->right = new_node;

	return (new_node);
}
