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

TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q)
{
    if (!root) return nullptr;
    if (root->val == p || root->val == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}

int main()
{
    int n;
    if (!(cin >> n)) return 0;
    TreeNode* root = buildTree(n);
    int p, q;
    cin >> p >> q;
    TreeNode* ans = lowestCommonAncestor(root, p, q);
    if (ans)
    {
        cout << ans->val << "\n";
    }
    return 0;
}
