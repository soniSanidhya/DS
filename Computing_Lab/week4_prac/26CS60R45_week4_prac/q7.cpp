#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(int n)
{
    if (n <= 0) return nullptr;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (arr[0] == -1001) return nullptr;
    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < n)
    {
        TreeNode* curr = q.front();
        q.pop();
        if (i < n && arr[i] != -1001)
        {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;
        if (i < n && arr[i] != -1001)
        {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int height(TreeNode* root, int& diameter)
{
    if (!root) return 0;
    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}

int main()
{
    int n;
    if (!(cin >> n)) return 0;
    TreeNode* root = buildTree(n);
    int diameter = 0;
    height(root, diameter);
    cout << diameter << "\n";
    return 0;
}
