#ifndef BINARY_TREES_H
#define BINARY_TREES_H

/* INCLUDED LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* STRUCTS AND DEFINITIONS */
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
/* typedef for binary tree struct */
typedef struct binary_tree_s binary_tree_t;
/* typedef for AVL tree struct */
typedef struct binary_tree_s avl_t;

/* FUNCTION PROTOTYPES */
/* given function to print binary tree */
void binary_tree_print(const binary_tree_t *tree);
/* function that checks if binary tree is a valid AVL tree */
int binary_tree_is_avl(const binary_tree_t *tree);
/* function to check if tree is valid binary search tree at every level */
int is_bst_recursive(const binary_tree_t *tree, int min, int max);
/* function to check if each subtree is balanced using preorder traversal */
int is_balanced_preorder(const binary_tree_t *tree);
/* function to determine if the tree is balanced */
int is_balanced(const binary_tree_t *tree);
/* helper function to get height of subtrees, including root node */
size_t height_helper(const binary_tree_t *tree);

#endif
