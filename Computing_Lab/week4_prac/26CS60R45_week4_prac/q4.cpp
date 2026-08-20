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

void inorder(TreeNode* root, vector<int>& res)
{
    if (!root) return;
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}

void preorder(TreeNode* root, vector<int>& res)
{
    if (!root) return;
    res.push_back(root->val);
    preorder(root->left, res);
    preorder(root->right, res);
}

void postorder(TreeNode* root, vector<int>& res)
{
    if (!root) return;
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->val);
}

void levelOrder(TreeNode* root, vector<int>& res)
{
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode* curr = q.front();
        q.pop();
        res.push_back(curr->val);
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

bool isLeaf(TreeNode* node)
{
    return node && !node->left && !node->right;
}

void addLeftBoundary(TreeNode* root, vector<int>& res)
{
    TreeNode* curr = root->left;
    while (curr)
    {
        if (!isLeaf(curr)) res.push_back(curr->val);
        if (curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

void addLeaves(TreeNode* root, vector<int>& res)
{
    if (!root) return;
    if (isLeaf(root))
    {
        res.push_back(root->val);
        return;
    }
    addLeaves(root->left, res);
    addLeaves(root->right, res);
}

void addRightBoundary(TreeNode* root, vector<int>& res)
{
    TreeNode* curr = root->right;
    vector<int> temp;
    while (curr)
    {
        if (!isLeaf(curr)) temp.push_back(curr->val);
        if (curr->right) curr = curr->right;
        else curr = curr->left;
    }
    for (int i = (int)temp.size() - 1; i >= 0; i--)
    {
        res.push_back(temp[i]);
    }
}

vector<int> boundaryTraversal(TreeNode* root)
{
    vector<int> res;
    if (!root) return res;
    if (!isLeaf(root)) res.push_back(root->val);
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    return res;
}

void printList(const string& label, const vector<int>& list)
{
    cout << label << ":";
    for (int v : list)
    {
        cout << " " << v;
    }
    cout << "\n";
}

int main()
{
    int n;
    if (!(cin >> n)) return 0;
    TreeNode* root = buildTree(n);
    vector<int> inList, preList, postList, lvlList;
    inorder(root, inList);
    preorder(root, preList);
    postorder(root, postList);
    levelOrder(root, lvlList);
    vector<int> bndList = boundaryTraversal(root);
    printList("Inorder", inList);
    printList("Preorder", preList);
    printList("Postorder", postList);
    printList("Level Order", lvlList);
    printList("Boundary", bndList);
    return 0;
}
