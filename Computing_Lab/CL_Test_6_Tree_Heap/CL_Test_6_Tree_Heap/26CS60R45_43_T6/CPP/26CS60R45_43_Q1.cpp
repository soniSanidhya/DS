// CS69021 Computing Lab-1 | Test-6
// Q1: The Jarl's Beacons

#include "../header/Tree.hpp"
// #include<fstream>
class Solution {
public:
    // root:   root of the binary tree
    // k:      the exact distance to search for
    // target: the node to measure distance from

     vector<TreeNode*> find_path(TreeNode *root, TreeNode *target){
        if(root == nullptr) return {};
        if(root == target){       
            return {root};
        }
        vector<TreeNode*> t1 = find_path(root->left, target );
        if(!t1.empty()){
            t1.push_back(root);
            return t1;
        }
        vector<TreeNode*> t2 = find_path(root->right , target );
        if(!t2.empty()){
            t2.push_back(root);
            return t2;
        }
        return {};
    }

    vector<int> all_at_k(TreeNode *root , int k , vector<int> &hash){
        if(root == nullptr) return {};
        if(hash[root->val]){
            return{};
            };
        if(k == 0){
            return {root->val};
        }
        
        if(k < 0) return {};
        hash[root->val] = 1;
        vector<int> vec1 = all_at_k(root->left , k-1 , hash);
        vector<int> vec2 = all_at_k(root->right , k-1 , hash);
        for(int a : vec2){
            vec1.push_back(a);
        }

        return vec1;
    }
// int i = path.size() -1 ; i >= 0 ; i--
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        // Your code here

        vector<TreeNode*> path = find_path(root , target );
        vector<int> hash(500 , 0);
        set<int> s;
        for(int i = 0 ; i < path.size() ; i++){
            vector<int> vec = all_at_k(path[i] , k-i , hash);
            for(auto a : vec){
                if(a != target->val)
                s.insert(a);
            }
        }
        vector<int> res(s.begin() , s.end());
        return res;
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

    int targetVal, k;
    cin >> targetVal >> k;

    TreeNode *root = buildTree(vals);
    TreeNode *target = findNode(root, targetVal);

    Solution sol;
    vector<int> result = sol.distanceK(root, target, k);
    sort(result.begin(), result.end());

    for (size_t i = 0; i < result.size(); i++)
        cout << result[i] << (i + 1 < result.size() ? ' ' : '\n');

    if (result.empty())
        cout << "\n";

    return 0;
}
// !-----------------------------------------
// ! Don't change this portion of the code  |
// !-----------------------------------------