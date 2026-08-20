#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k)
{
    int max = 0;
    int t = k;
    for (char curr = 'A'; curr <= 'Z'; curr++)
    {
        int i = 0, j = 0, k = t;
        while (i < s.length())
        {
            if (curr != s[i] && k > 0)
                k--;
            else if (curr != s[i])
            {
                while (curr == s[j])
                    j++;
                j++;
            }
            cout << curr << " " << k << " " << i << " " << j << endl;
            max = max > (i - j + 1) ? max : (i - j + 1);
            i++;
        }
    }
    return max;
}

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    if (goal < 0)
        return 0;
    int sum = 0, count = 0;
    int l = 0, r = 0;
    while (r < nums.size())
    {
        sum += nums[r];
        while (sum > goal)
        {
            sum -= nums[l];
            l++;
        }
        count += r - l + 1;
        r++;
    }
    return count;
}
// 1,0,1,0,0,1,1,1,0,1,0,1,1,0,1
// 0,0,0,0,0

int maxScore(vector<int> &cardPoints, int k)
{
    int n = cardPoints.size();
    int i = n - k;
    int j = i;
    int max = 0;
    for (; j < n; j++)
    {
        max += cardPoints[j];
    }
    j--;
    cout << "max: " << max << endl;
    if (k == n)
        return max;
    int temp = max;
    for (int m = 0; m < k; m++)
    {

        temp = temp - cardPoints[i];
        i = (i + 1) % n;
        cout << "i: " << i << endl;
        j = (j + 1) % n;
        cout << "j: " << j << endl;
        cout << cardPoints[i] << cardPoints[j] << endl;
        temp = temp + cardPoints[j];
        max = max > temp ? max : temp;
    }
    return max;
}
// 1,2,3,4,5,6,1 3
// 2,2,2 2

int k_distinct_helper(vector<int> arr, int k)
{
    unordered_map<int, int> map;
    int count = 0;

    for (int i = 0, j = 0; i < arr.size(); i++)
    {
        map[arr[i]]++;
        while (map.size() > k)
        {
            map[arr[j]]--;
            if (map[arr[j]] == 0)
                map.erase(arr[j]);
            j++;
        }

        count += i - j + 1;
    }
    return count;
}
// 2,1,1,1,3,4,3,

string minWindow_substr(string s, string t)
{
    vector<int> hash(256);
    int l = 0, r = 0, min_length = 10e5, s_ind = -1, count = 0;

    for (int i = 0; i < t.length(); i++)
    {
        hash[t[i]]++;
    }

    while (r < s.length())
    {
        if (hash[s[r]] > 0)
            count++;
        hash[s[r]]--;

        while (count == t.length())
        {
            if (min_length > r - l + 1)
            {
                s_ind = l;
                min_length = r - l + 1;
            }

            hash[s[l]]++;

            if (hash[s[l]] > 0)
                count--;

            l++;
        }

        r++;
    }

    return s_ind == -1 ? "" : s.substr(s_ind, min_length);
}

string minWindow_subsequence(string s1, string s2)
{
    int l = 0, r = 0, k = 0, st_i = -1, min_l = INT_MAX;

    while (r < s1.length())
    {
        if (s1[r] == s2[k])
        {
            k++;
        }
        if (k == s2.length())
        {
            k = 0;
            while (l < r)
            {
                if (s1[l] == s2[0])
                {
                    if (r - l + 1 < min_l)
                    {
                        st_i = l;
                        min_l = r - l + 1;
                    }
                }
                l++;
            }
        }
        r++;
    }
    return st_i != -1 ? s1.substr(st_i, min_l) : "";
}

int kDistinctChar(string &s, int k)
{
    int l = 0, r = 0, max_l = 0;
    unordered_map<char, int> map;
    while (r < s.length())
    {
        map[s[r]]++;
        while (map.size() > k)
        {
            map[s[l]]--;
            if (map[s[l]] == 0)
                map.erase(s[l]);
            l++;
        }
        max_l = max(max_l, r - l + 1);
        r++;
    }

    return max_l;
}

int main()
{
    // vector<int> vec = {1, 2, 1, 3, 4};
    string s = "abccab";
    int k = 4;
    cout << kDistinctChar(s, k);
    // cout << minWindow_subsequence("jmeqsiwvaovvnbstl", "u");
    // cout << numSubarraysWithSum(vec, 5) - numSubarraysWithSum(vec, 4);
    // cout << maxScore(vec, 1);
    // cout << k_distinct_helper(vec, k);
    // cout << k_distinct_helper(vec, k - 1);
    // cout << characterReplacement("ABBB", 1);
}