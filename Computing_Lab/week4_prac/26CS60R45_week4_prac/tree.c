#include "tree.h"

Tree *createTree(int n)
{
    Tree *tree = (Tree *)malloc(sizeof(Tree));

    tree->n = n;
    tree->arr = (int *)malloc(n * sizeof(int));
    tree->root = NULL;

    for (int i = 0; i < n; i++)
        scanf("%d", &tree->arr[i]);

    return tree;
}

void buildTree(Tree *tree)
{
    if (tree->n == 0 || tree->arr[0] == NULLR)
    {
        tree->root = NULL;
        return;
    }

    tree->root = (TreeNode *)malloc(sizeof(TreeNode));

    tree->root->val = tree->arr[0];
    tree->root->left = NULL;
    tree->root->right = NULL;

    TreeNode **q = (TreeNode **)malloc(tree->n * sizeof(TreeNode *));

    int front = 0;
    int rear = 0;
    int i = 1;

    q[rear++] = tree->root;

    while (front < rear && i < tree->n)
    {
        TreeNode *curr = q[front++];

        if (i < tree->n && tree->arr[i] != NULLR)
        {
            curr->left = (TreeNode *)malloc(sizeof(TreeNode));

            curr->left->val = tree->arr[i];
            curr->left->left = NULL;
            curr->left->right = NULL;

            q[rear++] = curr->left;
        }

        i++;

        if (i < tree->n && tree->arr[i] != NULLR)
        {
            curr->right = (TreeNode *)malloc(sizeof(TreeNode));

            curr->right->val = tree->arr[i];
            curr->right->left = NULL;
            curr->right->right = NULL;

            q[rear++] = curr->right;
        }

        i++;
    }

    free(q);
}

TreeNode *findNode(Tree *tree, int value)
{
    if (tree == NULL || tree->root == NULL)
        return NULL;

    TreeNode **queue = malloc(tree->n * sizeof(TreeNode *));

    int front = 0;
    int rear = 0;

    queue[rear++] = tree->root;

    while (front < rear)
    {
        TreeNode *curr = queue[front++];

        if (curr->val == value)
        {
            free(queue);
            return curr;
        }

        if (curr->left != NULL)
            queue[rear++] = curr->left;

        if (curr->right != NULL)
            queue[rear++] = curr->right;
    }

    free(queue);
    return NULL;
}

void freeTree(Tree *tree)
{
    if (tree == NULL)
        return;

    if (tree->root != NULL)
    {
        TreeNode **q = (TreeNode **)malloc(tree->n * sizeof(TreeNode *));

        int front = 0;
        int rear = 0;

        q[rear++] = tree->root;

        while (front < rear)
        {
            TreeNode *curr = q[front++];

            if (curr->left != NULL)
                q[rear++] = curr->left;

            if (curr->right != NULL)
                q[rear++] = curr->right;

            free(curr);
        }

        free(q);
    }

    free(tree->arr);
    free(tree);
}