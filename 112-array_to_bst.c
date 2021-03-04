/* 26. BST - Array to BST  */
#include "binary_trees.h"


/**
 * array_to_bst - builds a Binary Search Tree from an array
 *
 * @array: array of integers, may be unsorted and have repeating values
 * @size: amount of array members
 * Return: pointer to head of new BST constructed from array
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i, j;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		/* check if NULL return is for repeat value */
		if (bst_insert(&tree, array[i]) == NULL)
		{
			for (j = 0; j < size && array[j] != array[i]; j++)
			{}

			/* not a repeating value, bst_insert failure */
			if (j == i)
				return (NULL);
		}
	}

	return (tree);
}
