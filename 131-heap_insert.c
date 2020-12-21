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

	return (1 + max_size_t(binary_tree_height(tree->left),
			       binary_tree_height(tree->right)));
}

/**
 * binary_tree_nodes - counts the total nodes in a binary tree
 * @tree: root node from which to measure
 * Return: total non-leaf nodes at or below `tree`, or 0 if `tree` is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_nodes(tree->left) +
		binary_tree_nodes(tree->right));
}

/**
  * binary_tree_is_perfect - checks if a binary tree is perfect, meaning all
  * nodes except for leaves have two children, and all leaves at same level
  * @tree: root node below which to check
  * Return: 1 if `tree` and all nodes below it each have 2 children, 0 if not
  * or if `tree` is NULL
  */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height, i, pow2 = 1;
	size_t total_nodes;

	if (!tree)
		return (0);

	height = binary_tree_height(tree);
	total_nodes = binary_tree_nodes(tree);

	for (i = 0; i < height; i++)
		pow2 *= 2;

	return (pow2 - 1 == (int)total_nodes);
}

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
		if (!binary_tree_is_perfect(tree) &&
		    binary_tree_is_perfect(tree->left))
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
