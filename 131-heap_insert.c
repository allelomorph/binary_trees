#include "binary_trees.h"

/**
 * binary_tree_complete_insert - recursively proceeds through a `heap_t`
 * binary tree to add a new leaf in level order, while keeping tree complete
 * @tree: root node of tree to traverse
 * @value: value to store in the new node
 * Return: pointer to the new node, or NULL on failure
 */
heap_t *binary_tree_complete_insert(heap_t *tree, int value)
{
	heap_t *new = NULL;

	if (tree->left && tree->right)
	{
		if (tree->left->right && !tree->right->right)
			new = binary_tree_complete_insert(tree->right, value);
		else
			new = binary_tree_complete_insert(tree->left, value);
	}
	else
	{
		new = binary_tree_node(tree, value);
		if (!new)
			return (NULL);

		if (!(tree->left))
			tree->left = new;
		else
			tree->right = new;
	}

	return (new);
}


/**
 * heap_insert - inserts a value into a max binary heap
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = NULL, *temp = NULL;
	int swap;

	/* no root, start new tree */
	if (!(*root))
	{
		new = binary_tree_node(NULL, value);
		if (!new)
			return (NULL);
		*root = new;
		return (new);
	}

	/* find next available leaf position in level order */
	new = binary_tree_complete_insert(*root, value);
	if (!new)
		return (NULL);

	/* now sort new value into position in heap by value of new->n */
	temp = new;
	while (temp && temp->parent && temp->n > temp->parent->n)
	{
		swap = temp->n;
		temp->n = temp->parent->n;
		temp->parent->n = swap;
		temp = temp->parent;
	}

	return (temp);
}
