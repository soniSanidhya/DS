// CS69021 Computing Lab-1 | Test-6
// Q1: The Jarl's Beacons

#include "../header/Tree.h"

// root:        root of the binary tree
// k:           the exact distance to search for
// target:      the node to measure distance from
// returnSize:  set this to the number of values you return
int *distanceK(TreeNode *root, TreeNode *target, int k, int *returnSize) {
    // Your code here
}

// !-----------------------------------------
// ! Don't change this portion of the code  |
// !-----------------------------------------
int main()
{
    int n;
    scanf("%d", &n);
    int *vals = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &vals[i]);

    int targetVal, k;
    scanf("%d %d", &targetVal, &k);

    TreeNode *root = buildTree(vals, n);
    TreeNode *target = findNode(root, targetVal);

    int returnSize;
    int *result = distanceK(root, target, k, &returnSize);

    if (result != NULL && returnSize > 0)
    {
        qsort(result, returnSize, sizeof(int), cmpInt);
        for (int i = 0; i < returnSize; i++)
            printf("%d%c", result[i], (i + 1 < returnSize) ? ' ' : '\n');
    }
    else
        printf("\n");

    free(vals);
    return 0;
}
// !-----------------------------------------
// ! Don't change this portion of the code  |
// !-----------------------------------------