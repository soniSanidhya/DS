#include <bits/stdc++.h>
using namespace std;

vector<int> next_greater_element(vector<int> vec)
{
    vector<int> nge(vec.size());
    stack<int> st;

    for (int i = (int)vec.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= vec[i])
        {
            st.pop();
        }
        nge[i] = st.empty() ? -1 : st.top();
        st.push(vec[i]);
    }

    return nge;
}
vector<int> next_smaller_element(vector<int> vec)
{
    vector<int> nse(vec.size());
    stack<int> st;

    for (int i = (int)vec.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() >= vec[i])
        {
            st.pop();
        }
        nse[i] = st.empty() ? -1 : st.top();
        st.push(vec[i]);
    }

    return nse;
}

int trap_water(vector<int> vec)
{
    if (vec.size() < 3)
        return 0;
    vector<int> nge(vec.size());
    int max = 0;

    for (int i = (int)vec.size() - 1; i >= 0; i--)
    {
        if (vec[i] <= max)
        {
            nge[i] = max;
        }
        else
        {
            max = vec[i];
            nge[i] = 0;
        }
    }
    max = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] <= max)
        {
            nge[i] = nge[i] < max ? nge[i] : max;
        }
        else
        {
            max = vec[i];
            nge[i] = 0;
        }
    }
    max = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        int temp = nge[i] - vec[i];
        max += temp > 0 ? temp : 0;
    }

    for (int a : vec)
    {
        cout << a << "\t";
    }
    cout << endl;
    for (int a : nge)
    {
        cout << a << "\t";
    }
    return max;
}

vector<int> next_smaller_element_index(vector<int> vec)
{
    vector<int> nse(vec.size());
    stack<int> st;
    for (int i = ((int)vec.size() - 1); i >= 0; i--)
    {
        while (!st.empty() && vec[st.top()] > vec[i])
        {
            st.pop();
        }
        nse[i] = st.empty() ? vec.size() : st.top();
        st.push(i);
    }
    return nse;
}
vector<int> previous_smaller_equal_element_index(vector<int> vec)
{
    vector<int> psee(vec.size());
    stack<int> st;
    int i = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        while (!st.empty() && vec[st.top()] >= vec[i])
        {
            st.pop();
        }
        psee[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return psee;
}

int min_subarray_sum(vector<int> vec)
{
    long long sum = 0;

    vector<int> nse = next_smaller_element_index(vec);

    vector<int> psee = previous_smaller_equal_element_index(vec);
    for (int i = 0; i < vec.size(); i++)
    {
        int l = i - psee[i];
        int r = nse[i] - i;
        sum += (l * r) * vec[i];
    }
    return sum % 1000000007;
}

vector<int> asteroidCollision1(vector<int> &asteroids)
{
    vector<int> st;
    for (int i = 0; i < asteroids.size(); i++)
    {
        if (asteroids[i] > 0)
        {
            st.push_back(asteroids[i]);
        }
        else
        {
            while (!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i]))
            {
                st.pop_back();
            }
            if (!st.empty() && st.back() == abs(asteroids[i]))
            {
                st.pop_back();
            }
            else if (st.empty() || st.back() < 0)
            {
                st.push_back(asteroids[i]);
            }
        }
    }

    return st;
}

long long subArrayRanges(vector<int> nums)
{
    long long sum = 0;
    int n = (int)nums.size();
    vector<int> nge(n), pge(n), nse(n), pse(n);
    stack<int> st1, st2, st3, st4;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st1.empty() && nums[st1.top()] <= nums[i])
        {
            st1.pop();
        }
        nge[i] = st1.empty() ? n : st1.top();
        st1.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        while (!st3.empty() && nums[st3.top()] < nums[i])
            st3.pop();
        pge[i] = st3.empty() ? -1 : st3.top();
        st3.push(i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st2.empty() && nums[st2.top()] >= nums[i])
            st2.pop();
        nse[i] = st2.empty() ? n : st2.top();
        st2.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        while (!st4.empty() && nums[st4.top()] > nums[i])
            st4.pop();
        pse[i] = st4.empty() ? -1 : st4.top();
        st4.push(i);
    }
    // cout<<"nums: ";
    // for(int a : nums) cout<<a<<"\t";
    // cout<<endl;
    // cout<<"nge: ";

    // for(int a : nge) cout<<a<<"\t";
    // cout<<endl;
    // cout<<"pge: ";

    // for(int a : pge) cout<<a<<"\t";
    // cout<<endl;
    // cout<<"nse: ";

    // for(int a : nse) cout<<a<<"\t";
    // cout<<endl;
    // cout<<"pse: ";

    // for(int a : pse) cout<<a<<"\t";
    // cout<<endl;

    for (int i = 0; i < n; i++)
    {
        nge[i] = ((nge[i] - i) * (i - pge[i])) - 1;

        nse[i] = ((nse[i] - i) * (i - pse[i])) - 1;
        // cout<<nge[i]<<"\t"<<nse[i]<<endl;
        sum = sum + nums[i] * nge[i];
        sum = sum - nums[i] * nse[i];
    }
    return sum;
}

string removeKdigits(string num, int k)
{
    vector<char> st;
    for (int i = 0; i < num.size(); i++)
    {
        while (!st.empty() && st.back() > num[i] && k > 0)
        {
            st.pop_back();
            k--;
        }
        st.push_back(num[i]);
    }
    while (k > 0)
    {
        st.pop_back();
        k--;
    }
    int j = 0;
    while (j < st.size() && st[j] == '0')
    {
        j++;
    }
    string str = "";
    while (j < st.size())
        str += st[j++];

    return str.size() ? str : "0";
}

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> maxnum(n - k + 1);
    deque<int> q;

    for (int i = n - 1; i >= 0; i--)
    {
        if (!q.empty() && i + k <= q.front())
        {
            q.pop_front();
        }
        while (!q.empty() && nums[q.back()] < nums[i])
        {
            q.pop_back();
        }
        q.push_back(i);
        if (i <= (n - k))
        {
            maxnum[i] = nums[q.front()];
        }
    }
    return maxnum;
}

int celebrity(int n, vector<vector<int>> arr)
{
    int celeb = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[celeb][i] == 1)
        {
            celeb = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i != celeb && (arr[celeb][i] != 0 || arr[i][celeb] != 1))
        {
            celeb = -1;
            break;
        }
    }
    return celeb;
}
int main()
{
    // {{0, 1, 1, 0}, {0, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 0}};
    int n = 4;
    vector<vector<int>> arr = {{0,1},{1,0}};
    cout << celebrity(arr.size(), arr);

    // vector<int> vec = {1, 3, -1, -3, 5, 3, 6, 7};
    // vector<int> res = maxSlidingWindow(vec, 1);
    // for (int a : res)
    // {
    //     cout << a << "\t";
    // }
    // string str = "123";
    // cout << removeKdigits(str, 3);
    // vector<int> vec = {4,-2,-3,4,1};
    // cout << subArrayRanges(vec);

    // vector<int> vec = next_smaller_element({1, 3, 4, 2});
    // for (int a : vec)
    // {
    //     cout << a << "\t";
    // }
    // vector<int> vec = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // cout<<trap_water(vec);
    // cout << "hello";

    //  -2, 2, -1, -2

    // vector<int> arr = {-2, -2, -2, -2};
    // // cout << min_subarray_sum(arr);
    // vector<int> res = asteroidCollision1(arr);
    // for (auto a : res)
    // {
    //     cout << a << "\t";
    // }
    return 0;
}
