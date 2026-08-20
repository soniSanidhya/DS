#include <iostream>
#include <vector>
using namespace std;

int subsequenceSum(int k, int i, int curr, vector<int> v)
{

	if (curr > k || i >= v.size())
		return 0;
	if (curr == k)
	{
		return 1;
	}
	int count = 0;
	count += subsequenceSum(k, i++, curr + v[i], v);
	count += subsequenceSum(k, i++, curr, v);
	return count;
}

bool subsequenceExist(int k, int i, int curr, vector<int> v)
{
	if (i == v.size())
	{
		return (k == curr);
	}
	return (subsequenceExist(k, i + 1, curr + v[i], v) || subsequenceExist(k, i + 1, curr, v));
}

void combinationSum(int k, vector<int> v, vector<vector<int>> &result, vector<int> &temp, int i)
{
	if (i == v.size())
	{
		if (k == 0)
		{
			result.push_back(temp);
			return;
		}
	}
	if (k >= v[i])
	{
		temp.push_back(v[i]);
		combinationSum(k - v[i], v, result, temp, i);
		temp.pop_back();
	}
	combinationSum(k, v, result, temp, i + 1);
}

void subsetSum(vector<int> v, int i, int sum)
{
	if (i == v.size())
	{
		cout << sum << "\t";
		return;
	}
	subsetSum(v, i + 1, sum);
	subsetSum(v, i + 1, sum + v[i]);
	return;
}

void helper(vector<vector<int>> &res, vector<int> v, vector<int> &temp, int i)
{
	if (i == v.size())
	{
		res.push_back(temp);
		return;
	}
	temp.push_back(v[i]);
	helper(res, v, temp, i + 1);
	temp.pop_back();
	while (i < v.size() && v[i] == v[i + 1])
		i++;
	helper(res, v, temp, i + 1);
	return;
}

void combinationSum2(int l, int target, int t, vector<vector<int>> &res, vector<int> &temp)
{
	if (target < 0)
		return;
	if (t == temp.size() && target != 0)
		return;
	if (t == temp.size() && target == 0)
	{
		res.push_back(temp);
	}
	for (int i = l + 1; i < 10; i++)
	{
		temp.push_back(i);
		combinationSum2(i, target - i, t, res, temp);
		temp.pop_back();
		//		combinationSum2(i , target  , t , res, temp);
	}
	return;
}

vector<string> helper2(char c)
{
	switch (c)
	{
	case '2':
		return {"a", "b", "c"};
	case '3':
		return {"d", "e", "f"};
	case '4':
		return {"g", "h", "i"};
	case '5':
		return {"j", "k", "l"};
	case '6':
		return {"m", "n", "o"};
	case '7':
		return {"p", "q", "r", "s"};
	case '8':
		return {"t", "u", "v"};
	case '9':
		return {"w", "x", "y", "z"};
	default:
		return {};
	}
}
void phoneNumber(string s, string curr, vector<string>& v, int ind)
{
	if (ind == s.length())
	{
		v.push_back(curr);
		return;
	}
	// cout << curr << endl;
	vector<string> temp = helper2(s[ind]);
	// cout<<curr<<"\t"<<temp.size()<<endl;
	for (int i = 0; i < temp.size(); i++)
	{
		phoneNumber(s, curr + temp[i], v, ind + 1);
	}
	return;
}

int main()
{
	//	cout<<"hi";
	vector<int> v = {5, 2, 1, 3};
	;

	vector<vector<int>> res;

	vector<string> temp;

	string s ;
	cin>>s;

	// combinationSum2(0, 9, 3 , res, temp);
	phoneNumber(s, "", temp, 0);

	for (int i = 0; i < temp.size(); i++)
	{
		cout << temp[i] << " ";
	}
	

	// for (int i = 0; i < res.size(); i++)
	// {
	// 	for (int j = 0; j < res[i].size(); j++)
	// 	{
	// 		cout << res[i][j] << "\t";
	// 	}
	// 	cout << endl;
	// }

	return 0;
}
