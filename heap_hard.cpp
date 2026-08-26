#include <bits/stdc++.h>
using namespace std;

class Twitter
{
private:
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, set<int>> follow_list;
    int time;

public:
    Twitter()
    {
        time = 0;
    }

    void postTweet(int userId, int tweetId)
    {
        tweets[userId].push_back({tweetId, time++});
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> following(follow_list[userId].begin(),
                              follow_list[userId].end());
        following.push_back(userId);
        // cout<<"user: ";
        // for(auto a : following) cout<<a<<"\t";
        vector<vector<pair<int, int>>> all_tweets;

        for (auto followee : following)
        {
            vector<pair<int, int>> tw(tweets[followee].end() -
                                          min<size_t>(10, tweets[followee].size()),
                                      tweets[followee].end());
            reverse(tw.begin(), tw.end());
            all_tweets.push_back(tw);
        }
        // cout<<"\nall tweets : ";
        // for(auto a : all_tweets)
        // for(auto b : a) cout<<b<<"\t";
        vector<int> feed;
        priority_queue<vector<int>> pq;
        for (int i = 0; i < all_tweets.size(); i++)
        {
            if (all_tweets[i].size())
                pq.push({all_tweets[i][0].second, all_tweets[i][0].first, i, 0});
        }
        while (feed.size() != 10 && !pq.empty())
        {
            vector<int> inst = pq.top();
            feed.push_back(inst[1]);
            pq.pop();
            if (inst[3] + 1 < all_tweets[inst[2]].size())
                pq.push(
                    {all_tweets[inst[2]][inst[3] + 1].second, all_tweets[inst[2]][inst[3] + 1].first, inst[2], inst[3] + 1});
        }
        return feed;
    }

    void follow(int followerId, int followeeId)
    {
        follow_list[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        follow_list[followerId].erase(followeeId);
    }
};

int cutRod(vector<int> &price)
{
    int n = price.size() + 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 1; i < n; i++)
    {
        // cout<<"\n"<<i<<" :"<<endl;
        for (int j = 1; j < n; j++)
        {
            // cout<<j<<" ";
            int r = j - i;
            if (r >= 0)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][r] + price[i - 1]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n - 1][n - 1];
}

class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

    KthLargest(int k, vector<int> nums)
    {
        this->k = k;
        for (auto a : nums)
        {
            pq.push(a);
        }

        cout << pq.size() << " " << k << endl;
        while (k < pq.size())
            pq.pop();
    }

    int add(int val)
    {
        pq.push(val);
        while (k < pq.size())
        {
            pq.pop();
        }
        return pq.top();
    }
};

vector<int> topKSumPairs(vector<int> a, vector<int> b, int k)
{
    // code here
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    vector<int> res;
    priority_queue<vector<int>> pq;
    set<pair<int, int>> s;
    pq.push({a[0] + b[0], 0, 0});
    s.insert({0, 0});
    while (res.size() != k)
    {
        int n = pq.top()[2];
        int m = pq.top()[1];
        res.push_back(pq.top()[0]);
        pq.pop();
        // cout<<"values: "<<m<<" "<<n<<endl;
        if (!s.contains({m, n + 1}))
        {
            // cout<<"does not have 1: "<<m<<" "<<n+1<<endl;
            s.insert({m, n + 1});
            pq.push({a[m] + b[n + 1], m, n + 1});
        }
        if (!s.contains({m + 1, n}))
        {
            // cout<<"does not have 2: "<<m+1<<" "<<n<<endl;
            s.insert({m + 1, n});
            pq.push({a[m + 1] + b[n], m + 1, n});
        }
    }
    return res;
}

class MedianFinder
{
public:
    int n;
    priority_queue<int> first;
    priority_queue<int, vector<int>, greater<int>> second;

    MedianFinder()
    {
        n = 0;
    }

    void addNum(int num)
    {
        if (!first.empty() && num < first.top())
            first.push(num);
        else
        {
            second.push(num);
        }
        //    cout<<"second: "<<second.top()<<endl;
        while (second.size() != first.size() + 1 && second.size() != first.size())
        {
            if (first.size() > second.size())
            {
                second.push(first.top());
                first.pop();
            }
            else
            {
                if (!second.empty())
                {
                    first.push(second.top());
                    second.pop();
                }
            } // cout<<"first: "<<first.top()<<endl;
        }
        n++;
    }

    double findMedian()
    {
        if (n % 2 != 0)
        {
            // cout << "odd: ";
            return second.top();
        }
        else
        {
            // cout << "even: " << first.top() << " " << second.top() << " : ";

            return (first.top() + second.top()) / (double)2;
        }
    }
};

vector<int> topKFrequent(vector<int> &nums, int k)
{

    unordered_map<int, int> m;
    for (auto a : nums)
        m[a]++;
    vector<pair<int,int>> vec;
    for(auto a : m){
        vec.push_back({a.second , a.first});
    }
    priority_queue<pair<int, int>> pq(vec.begin() , vec.end());
    vector<int> res;
    while(k--){
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}

int main()
{
    MedianFinder mf;
    mf.addNum(-1);
    cout << mf.findMedian() << endl;
    mf.addNum(-2);
    cout << mf.findMedian() << endl;
    mf.addNum(-3);
    cout << mf.findMedian() << endl;
    mf.addNum(-4);
    cout << mf.findMedian() << endl;
    mf.addNum(-5);
    cout << mf.findMedian() << endl;

    // vector<int> res = topKSumPairs({10, 9, 5, 3, 7}, {6, 6, 3, 2, 2}, 5);
    // for (auto a : res)
    // cout << a << " ";
    // vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    // cout << cutRod(price);
    // KthLargest k(3, {5, 4, 8, 2});
    // cout << k.add(3);
    return 0;
}