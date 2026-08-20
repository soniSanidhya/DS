#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* bstFromPreorder(const vector<int>& preorder, int& idx, int bound)
{
    if (idx >= (int)preorder.size() || preorder[idx] > bound)
    {
        return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[idx++]);
    root->left = bstFromPreorder(preorder, idx, root->val);
    root->right = bstFromPreorder(preorder, idx, bound);
    return root;
}

void printTree(TreeNode* root)
{
    if (!root)
    {
        cout << "[]\n";
        return;
    }
    vector<string> nodes;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode* curr = q.front();
        q.pop();
        if (curr)
        {
            nodes.push_back(to_string(curr->val));
            q.push(curr->left);
            q.push(curr->right);
        }
        else
        {
            nodes.push_back("null");
        }
    }
    while (!nodes.empty() && nodes.back() == "null")
    {
        nodes.pop_back();
    }
    cout << "[";
    for (int i = 0; i < (int)nodes.size(); i++)
    {
        cout << nodes[i] << (i + 1 == (int)nodes.size() ? "" : ",");
    }
    cout << "]\n";
}

int main()
{
    int n;
    if (!(cin >> n)) return 0;
    vector<int> preorder(n);
    for (int i = 0; i < n; i++)
    {
        cin >> preorder[i];
    }
    int idx = 0;
    TreeNode* root = bstFromPreorder(preorder, idx, INT_MAX);
    printTree(root);
    return 0;
}
