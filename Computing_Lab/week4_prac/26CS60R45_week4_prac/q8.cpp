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

TreeNode* deleteNode(TreeNode* root, int key)
{
    if (!root) return nullptr;
    if (key < root->val)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->val)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (!root->left)
        {
            TreeNode* rightChild = root->right;
            delete root;
            return rightChild;
        }
        else if (!root->right)
        {
            TreeNode* leftChild = root->left;
            delete root;
            return leftChild;
        }
        else
        {
            TreeNode* succ = root->right;
            while (succ->left)
            {
                succ = succ->left;
            }
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }
    }
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
    TreeNode* root = buildTree(n);
    int key;
    cin >> key;
    root = deleteNode(root, key);
    printTree(root);
    return 0;
}
