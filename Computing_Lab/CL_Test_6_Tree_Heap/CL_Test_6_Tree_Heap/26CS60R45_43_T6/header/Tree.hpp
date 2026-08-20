// !-----------------------------------------
// ! Don't change this portion of the code  |
// !-----------------------------------------

#pragma once
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

inline TreeNode *buildTree(vector<int> &vals)
{
    int n = (int)vals.size();
    if (n == 0 || vals[0] == -1)
        return nullptr;

    TreeNode *root = new TreeNode(vals[0]);
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < n)
    {
        TreeNode *cur = q.front();
        q.pop();
        if (i < n)
        {
            if (vals[i] != -1)
            {
                cur->left = new TreeNode(vals[i]);
                q.push(cur->left);
            }

            i++;
        }
        if (i < n)
        {
            if (vals[i] != -1)
            {
                cur->right = new TreeNode(vals[i]);
                q.push(cur->right);
            }

            i++;
        }
    }

    return root;
}

inline TreeNode *findNode(TreeNode *root, int val)
{
    if (!root)
        return nullptr;
    if (root->val == val)
        return root;

    TreeNode *l = findNode(root->left, val);
    if (l)
        return l;

    return findNode(root->right, val);
}

// !-----------------------------------------
// ! Don't change this portion of the code  |
// !-----------------------------------------