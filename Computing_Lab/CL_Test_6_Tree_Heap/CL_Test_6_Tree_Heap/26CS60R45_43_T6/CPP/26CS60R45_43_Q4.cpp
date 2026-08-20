// CS69021 Computing Lab-1 | Test-6
// Q4: The Division of Kattegat

#include "../header/Tree.hpp"

class Solution
{
public:
    // n:     number of settlements
    // k:     number of paths to destroy
    
    // edges: list of edges given as pairs of vertices (1-indexed)

    int solve(int n , int k , int i vector<pair<int,int>> &edges ){
        if(i == edges.size()) return n;
        if(k == 0) return n;
        int min_ = n;
        while(k >= 0 && i < edges.size()){
            min_ = min(solve(int n , k-1 , i+1,edges ) , solve(int n , k , i+1 , edges));
        }
        
    }

    int maxMinComponentSize(int n, int k, vector<pair<int, int>> &edges) {
        // Your code here
    }
};

// !-----------------------------------------
// ! Don't change this portion of the code  |
// !-----------------------------------------
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> edges(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> edges[i].first >> edges[i].second;

    Solution sol;
    cout << sol.maxMinComponentSize(n, k, edges) << "\n";

    return 0;
}
// !-----------------------------------------
// ! Don't change this portion of the code  |
// !-----------------------------------------