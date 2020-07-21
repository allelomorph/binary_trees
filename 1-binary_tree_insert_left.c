#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_left - inserts a `binary_tree_t` node as the left-child
 * of another node, or if `parent` "A" already has a left-child "B", then new
 * node "C" takes its place, and the old left-child becomes left-child of new
 * node  ( B <-C <-A )
 * @parent: pointer of node into which left-child is inserted
 * @value: integer stored in new node
 * Return: pointer to new node, or NULL on failure or if `parent` is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	if (parent->left)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	else
		new_node->left = NULL;
	new_node->right = NULL;
	parent->left = new_node;

	return (new_node);
}
