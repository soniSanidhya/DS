// CS69021 Computing Lab-1 | Test-6
// Q3: The Viking Scouts

#include "../header/Tree.hpp"

class Solution {
public:
    
// root: root of the binary tree

    int sol(TreeNode *root , int k){
        if (root == nullptr) return 0;
        if(k%2 == 0) return sol(root->left , k+1) + sol(root->right , k+1) + 1;
        return sol(root->left , k+1) + sol(root->right , k+1);
    }

    int minCameraCover(TreeNode *root) {
        return min(sol(root , 1) , sol(root , 0));
    }
};

// !-----------------------------------------
// ! Don't change this portion of the code  |
// !-----------------------------------------
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; i++)
        cin >> vals[i];

    TreeNode *root = buildTree(vals);

    Solution sol;
    cout << sol.minCameraCover(root) << "\n";

    return 0;
}
// !-----------------------------------------
// ! Don't change this portion of the code  |
// !-----------------------------------------