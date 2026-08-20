#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

// This is a general template you are free to change it as per the questions.
// Change function definition where required.

int* solve(TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    return NULL;
}

int main()
{
    int n;
    scanf("%d", &n);

    Tree* tree = createTree(n);

    buildTree(tree);

    TreeNode* root = tree->root;

    int ansSize;
    int* ans = solve(root, &ansSize);

    for (int i = 0; i < ansSize; i++)
    {
        printf("%d ", ans[i]);
    }

    printf("\n");

    free(ans);
    freeTree(tree);

    return 0;
}