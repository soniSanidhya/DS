#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

#define NULLR -1001

// This is a TreeNode represtation of tree
// NOTE : Adjacency List can also used for tree representation

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct Tree
{
    int *arr;
    int n;
    TreeNode *root;
} Tree;

Tree* createTree(int n);
void buildTree(Tree* tree);
void freeTree(Tree* tree);
TreeNode *findNode(Tree *tree, int value);
#endif