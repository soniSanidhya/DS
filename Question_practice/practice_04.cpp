#include <bits/stdc++.h>
using namespace std;

int priority(char ch)
{
    // cout << "came for priority: " << ch << endl;
    switch (ch)
    {
    case '-':
    case '+':
        return 1;
    case '*':
    case '/':
        return 2;
    }
    return 0;
}

int get_res(char ch, int x, int y)
{
    // cout << y << ch << x << endl;
    switch (ch)
    {
    case '+':
        return x + y;
    case '-':
        return y - x;
    case '*':
        return x * y;
    case '/':
        return y / x;
    }
    return 0;
}

int calculate(string str)
{
    stack<int> opr;
    stack<char> opt;
    int n = str.length();
    int i = 0;
    string num = "";
    for (int i = 0; i < n; i++)
    {
        while (i < n && str[i] <= '9' && str[i] >= '0')
        {
            num = num + str[i];
            i++;
        }
        if (num != "")
        {
            // cout << "num: " << num << endl;
            opr.push(atoi(num.c_str()));
            // cout << "at top: " << opr.top() << endl;
            num = "";
        }
        if (i >= n)
            break;
        if (str[i] == '(')
        {
            opt.push('(');
        }
        else if (str[i] == ')')
        {
            while (!opt.empty() && opt.top() != '(')
            {
                // cout << "first one\n";
                int x = opr.top();
                opr.pop();
                // cout << x << "2 one\n";
                int y = opr.top();
                // cout << y << endl;
                opr.pop();
                // cout << "3 one\n";
                int temp = get_res(opt.top(), x, y);
                opt.pop();

                opr.push(temp);
                // cout << "4 one\n";
            }
            opt.pop();
            // cout<<i<<"dime\n";
        }
        else
        {
            while (!opt.empty() && priority(opt.top()) >= priority(str[i]))
            {
                int x = opr.top();
                opr.pop();
                int y = opr.top();
                opr.pop();
                int temp = get_res(opt.top(), x, y);
                opt.pop();
                opr.push(temp);
            }
            // cout << "pushing" << i << str[i] << "int opt\n";
            opt.push(str[i]);
        }
    }
    
    while (!opt.empty())
    {
        // cout << "first one\n";
        int x = opr.top();
        opr.pop();
        // cout << x << "2 one\n";
        int y = opr.top();
        // cout << y << endl;
        opr.pop();
        // cout << "3 one\n";
        int temp = get_res(opt.top(), x, y);
        opt.pop();
        // cout << "4 one\n";

        opr.push(temp);
    }
    return opr.top();
}

int main()
{
    string str;
    cin >> str;
    cout << calculate(str);
}