#include "tree.hpp"

// This is an general template you are free to change it as per the questions .
// Change function defination where required

using namespace std;

vector<int>solve (TreeNode * root)
{
}

int main()
{
    int n;
    cin >> n;
    Tree tree(n);
    TreeNode * root=tree.buildTree();
    vector<int>ans=solve(root);
    for(auto it:ans)
    {
        cout<<it<<' ';
    }
    return 0;
}

