// CS69021 Computing Lab-1 | Test-6
// Q3: The Viking Scouts

#include "../header/Tree.h"

// root: root of the binary tree
int minCameraCover(TreeNode *root) {
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

    TreeNode *root = buildTree(vals, n);
    printf("%d\n", minCameraCover(root));

    free(vals);
    return 0;
}
// !-----------------------------------------
// ! Don't change this portion of the code  |
// !-----------------------------------------