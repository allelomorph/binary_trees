#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

/**
 * struct avl_data_s - combined recrusive height and AVL balance
 *
 * @height: height of a subtree
 * @is_AVL: 0 if balance factor of subtree is < -1 or > 1; 1 otherwise
 */
typedef struct avl_data_s
{
	int height;
	int is_AVL;
} avl_data_t;

/* mandatory tasks 0-18 + advanced tasks 19-24, 30, 36 */
typedef struct binary_tree_s binary_tree_t;

/* advanced tasks 25-28 */
typedef struct binary_tree_s bst_t;

/* advanced tasks 31-34 */
typedef struct binary_tree_s avl_t;

/* advanced tasks 37-40 */
typedef struct binary_tree_s heap_t;

/* for output formatted to match project examples */
void binary_tree_print(const binary_tree_t *);

/* mandatory tasks 0-9 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);

/* helper to task 9 */
size_t max_size_t(size_t a, size_t b);

/* mandatory tasks 10-18 */
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);

/* helpers to task 14 */
int max_int(int a, int b);
int binary_tree_balance_height(const binary_tree_t *tree);

/* advanced tasks 19-23 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
int binary_tree_is_complete(const binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

/* helper to task 19 */
binary_tree_t *bt_find_lca(binary_tree_t *root, const binary_tree_t *first,
			   const binary_tree_t *second);
/* helper to task 20 */
void operate_on_level(const binary_tree_t *tree, size_t lvl,
		      void (*func)(int));

/* helper to task 21 */
int check_bt_complete(const binary_tree_t *tree, size_t i, size_t size);

/* advanced tasks 24-28: binary search trees */
int binary_tree_is_bst(const binary_tree_t *tree);
bst_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *bst_remove(bst_t *root, int value);

/* helper to task 25 */
bst_t *bst_insert_recursion(bst_t *tree, int value);

/* advanced tasks 30-34: AVL trees */
int binary_tree_is_avl(const binary_tree_t *tree);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);
avl_t *avl_remove(avl_t *root, int value);
avl_t *sorted_array_to_avl(int *array, size_t size);

/* helpers to task 30 */
avl_data_t BST_is_AVL_balanced(const binary_tree_t *tree);
int tree_is_BST(const binary_tree_t *tree, int *prev);

/* advanced tasks 36-40: Max Binary Heap */
int binary_tree_is_heap(const binary_tree_t *tree);
heap_t *heap_insert(heap_t **root, int value);
heap_t *array_to_heap(int *array, size_t size);
int heap_extract(heap_t **root);
int *heap_to_sorted_array(heap_t *heap, size_t *size);

#endif /* BINARY_TREES_H */
