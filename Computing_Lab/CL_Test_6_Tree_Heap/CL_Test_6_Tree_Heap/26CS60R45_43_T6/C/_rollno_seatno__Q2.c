// CS69021 Computing Lab-1 | Test-6
// Q2: The K-th Nearest Enemy Longship

#include <stdio.h>
#include <stdlib.h>

// queriesSize:    number of queries
// returnSize:     set this to queriesSize
// k:              the k as described in the problem
// queriesColSize: queriesColSize[i] == 2 for each i (columns in queries[i])
// queries:        queries[i] = {x, y}, the coordinates of the i-th spotted longship
long long *kthNearest(int **queries, int queriesSize, int *queriesColSize, int k, int *returnSize) {
    // Your code here
}

// !-----------------------------------------
// ! Don't change this portion of the code  |
// !-----------------------------------------
int main()
{
    int k, q;
    scanf("%d %d", &k, &q);

    int **queries = (int **)malloc(sizeof(int *) * q);
    int *queriesColSize = (int *)malloc(sizeof(int) * q);
    for (int i = 0; i < q; i++) {
        queries[i] = (int *)malloc(sizeof(int) * 2);
        scanf("%d %d", &queries[i][0], &queries[i][1]);
        queriesColSize[i] = 2;
    }

    int returnSize;
    long long *result = kthNearest(queries, q, queriesColSize, k, &returnSize);

    for (int i = 0; i < returnSize; i++)
        printf("%lld%c", result[i], (i + 1 < returnSize) ? ' ' : '\n');

    return 0;
}
// !-----------------------------------------
// ! Don't change this portion of the code  |
// !-----------------------------------------