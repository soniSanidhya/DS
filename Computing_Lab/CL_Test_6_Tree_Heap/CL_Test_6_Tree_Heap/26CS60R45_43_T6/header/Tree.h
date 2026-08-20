// !-----------------------------------------
// ! Don't change this portion of the code  |
// !-----------------------------------------

#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
} TreeNode;

static TreeNode *newNode(int val)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;

    return node;
}

static TreeNode *buildTree(int *vals, int n)
{
    if (n == 0 || vals[0] == -1)
        return NULL;

    TreeNode *root = newNode(vals[0]);
    TreeNode **q = (TreeNode **)malloc(sizeof(TreeNode *) * n);

    int i = 1;
    int qh = 0, qt = 0;
    q[qt++] = root;
    while (qh < qt && i < n)
    {
        TreeNode *cur = q[qh++];
        if (i < n)
        {
            if (vals[i] != -1)
            {
                cur->left = newNode(vals[i]);
                q[qt++] = cur->left;
            }

            i++;
        }
        if (i < n)
        {
            if (vals[i] != -1)
            {
                cur->right = newNode(vals[i]);
                q[qt++] = cur->right;
            }

            i++;
        }
    }

    free(q);
    return root;
}

static TreeNode *findNode(TreeNode *root, int val)
{
    if (!root)
        return NULL;
    if (root->val == val)
        return root;

    TreeNode *l = findNode(root->left, val);
    if (l)
        return l;

    return findNode(root->right, val);
}

static int cmpInt(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

#endif

// !-----------------------------------------
// ! Don't change this portion of the code  |
// !-----------------------------------------