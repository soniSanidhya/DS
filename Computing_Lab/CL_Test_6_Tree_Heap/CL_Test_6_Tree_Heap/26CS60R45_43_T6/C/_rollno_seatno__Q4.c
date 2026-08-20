// CS69021 Computing Lab-1 | Test-6
// Q4: The Division of Kattegat

#include "../header/Tree.h"

// n:  number of settlements
// k:  number of paths to destroy
// eu: eu[i] is one endpoint of the i-th edge (1-indexed)
// ev: ev[i] is the other endpoint of the i-th edge (1-indexed)
int maxMinComponentSize(int n, int k, int *eu, int *ev) {
    // Your code here
}

// !-----------------------------------------
// ! Don't change this portion of the code  |
// !-----------------------------------------
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int *eu = (int *)malloc(sizeof(int) * (n - 1 > 0 ? n - 1 : 1));
    int *ev = (int *)malloc(sizeof(int) * (n - 1 > 0 ? n - 1 : 1));
    for (int i = 0; i < n - 1; i++)
        scanf("%d %d", &eu[i], &ev[i]);

    printf("%d\n", maxMinComponentSize(n, k, eu, ev));

    free(eu);
    free(ev);

    return 0;
}
// !-----------------------------------------
// ! Don't change this portion of the code  |
// !-----------------------------------------