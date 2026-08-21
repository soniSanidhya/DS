#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int val;
    node *next;
    node(int x)
    {
        val = x;
        next = nullptr;
    }
};

vector<int> merge_k_sorted(vector<vector<int>> arrs)
{
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<int> res;
    for (int i = 0; i < arrs.size(); i++)
    {
        pq.push({arrs[i][0], i, 0});
    }

    while (!pq.empty())
    {
        int t = pq.top()[1];
        int i = pq.top()[2];
        res.push_back(pq.top()[0]);
        pq.pop();
        if (i < arrs[t].size() - 1)
        {
            pq.push({arrs[t][i + 1], t, i + 1});
        }
    }
    return res;
}

node *merge_k_list(vector<node *> heads)
{
    auto llcmp = [](node *a, node *b)
    {
        return a->val > b->val;
    };
    priority_queue<node *, vector<node *>, decltype(llcmp)> pq(llcmp);
    node *head = new node(0);
    node *temp = head;
    for (auto a : heads)
    {
        pq.push(a);
    }
    while (!pq.empty())
    {
        temp->next = pq.top();
        temp = temp->next;
        pq.pop();
        if (temp && temp->next)
        {
            pq.push(temp->next);
        }
    }
    return head->next;
}

int leastInterval(vector<char> &tasks, int n)
{
    int maxfreq = 0;
    unordered_map<char, int> hash;

    for (auto a : tasks)
    {

        hash[a]++;
        maxfreq = (maxfreq, hash[a]);
    }
    int maxfreqcount = 0;
    for (auto a : hash)
    {
        if (maxfreq == a.second)
            maxfreqcount++;
    }
    return max((int)tasks.size(), (maxfreq - 1) * (n + 1) + maxfreqcount);
}

bool isNStraightHand(vector<int> &hand, int groupSize)
{
    map<int, int> hash;
    for (int a : hand)
        hash[a]++;
    // for (auto b : hash)
    // {
    //     cout << b.first << " : " << b.second << endl;
    // }
    while (!hash.empty())
    {

        int k = 0;
        int last = 0;
        for (auto p : hash)
        {
            if (k == groupSize)
                break;
           if (k > 0 && last + 1 != p.first)
                return false;
            last = p.first;
            // cout<<"current last: " <<last<<endl;
            // cout<<hash[p.first]<<endl;
            hash[p.first]--;
            // cout<<hash[p.first]<<endl;
            if (hash[p.first] == 0)
            {
                hash.erase(p.first);
            }
            k++;
        }

        // cout << "after it : \n";
        // for (auto b : hash)
        // {
        //     cout << b.first << " : " << b.second << endl;
        // }
        if (k != groupSize)
            return false;
    }
    return true;
}

int main()
{

    vector<int> v = {1,2,3,4};
    cout << isNStraightHand(v, 4);

    // vector<char> vec = {'A', 'A', 'A', 'B', 'B', 'B'};
    // cout << leastInterval(vec, 2);

    // vector<vector<int>> res = {{1, 5, 6, 9}, {2, 3, 4, 5, 8}, {7, 8, 9, 11, 15, 20}};
    // vector<int> res = merge_k_sorted({{1,5,6,9},{2,3,4,5,8},{7,8,9,11,15,20}});
    // for(int a : res) cout<<a<<"\t";
    // vector<node *> lists;
    // for (auto a : res)
    // {
    //     node *head = new node(-1);
    //     node *temp = head;
    //     for (int i : a)
    //     {
    //         temp->next = new node(i);
    //         temp = temp->next;
    //     }
    //     lists.push_back(head->next);
    // }
    // for (auto as : lists)
    // {
    //     // cout << as->val << "\t";
    // }
    // node *h = merge_k_list(lists);
    // while (h)
    // {
    //     cout << h->val << "\t";
    //     h = h->next;
    // }
}