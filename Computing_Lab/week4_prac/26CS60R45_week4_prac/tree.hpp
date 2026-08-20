#ifndef TREE_HPP
#define TREE_HPP

#include <bits/stdc++.h>
using namespace std;
#define NULLR -1001

// This is a TreeNode represtation of tree
// NOTE : Adjacency List can also used for tree representation

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Tree
{
public:
    vector<int> arr;
    TreeNode *root;

    Tree(int n)
    {
        arr.resize(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        root = nullptr;
    }

    Tree(const vector<int> &v)
    {
        arr = v;
        root = nullptr;
    }

    TreeNode *buildTree()
    {
        buildTree(arr);
        return root;
    }

    void buildTree(const vector<int> &arr)
    {
        if (arr.empty() || arr[0] == NULLR)
        {
            root = nullptr;
            return;
        }

        root = new TreeNode(arr[0]);
        queue<TreeNode *> q;
        q.push(root);

        int i = 1;

        while (!q.empty() && i < arr.size())
        {
            TreeNode *curr = q.front();
            q.pop();

            if (i < arr.size() && arr[i] != NULLR)
            {
                curr->left = new TreeNode(arr[i]);
                q.push(curr->left);
            }
            i++;

            if (i < arr.size() && arr[i] != NULLR)
            {
                curr->right = new TreeNode(arr[i]);
                q.push(curr->right);
            }
            i++;
        }
    }
    TreeNode *findNode(int value)
    {
        if (root == nullptr)
            return nullptr;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr->val == value)
                return curr;

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }

        return nullptr;
    }
};

#endif
