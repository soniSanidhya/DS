#include <bits/stdc++.h>
using namespace std;

int priority(char c)
{
    switch (c)
    {
    case '(':
        return 1;
    case ')':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
    case '%':
        return 3;
    case '^':
        return 4;
    default:
        return 0;
    }
}

string inf_to_pos(string inf)
{
    string pos = "";
    stack<char> op;
    for (int i = 0; i < inf.length(); i++)
    {
        if (priority(inf[i]) == 0)
        {
            // cout<<inf[i]<<endl;
            pos = pos + inf[i];
        }
        else
        {
            if (op.empty() || priority(inf[i]) > priority(op.top()) || inf[i] == '(' || (inf[i] == '^' && op.top() == '^'))
            {
                op.push(inf[i]);
            }
            else
            {
                if (inf[i] == ')')
                {
                    while (op.top() != '(')
                    {
                        pos = pos + op.top();
                        op.pop();
                    }
                    op.pop();
                }
                else
                {
                    while (!op.empty() && priority(inf[i]) <= priority(op.top()))
                    {
                        pos = pos + op.top();
                        op.pop();
                    }
                    op.push(inf[i]);
                }
            }
        }
    }
    while (!op.empty())
    {
        pos = pos + op.top();
        op.pop();
    }

    return pos;
}

int main()
{
    vector<string> testCases = {
        "a+b",
        "a+b*c",
        "(a+b)*c",
        "a+b*c-d",
        "a*b+c*d",
        "a+b*(c-d)",
        "(a+b)*(c+d)",
        "a^b",
        "a^b^c",
        "a^(b^c)",
        "(a^b)^c",
        "a*b/c",
        "a/b*c",
        "a+b-c+d",
        "a*(b+c*d)",
        "((a+b))",
        "a+(b*(c+d))",
        "((a+b)*(c-d))/e",
        "a+(b*c-(d/e^f)*g)*h",
        "a+b*(c^d-e)^(f+g*h)-i",
        "a+(b)",
        "(a)",
        "((a))",
        "a^b^c^d",
        "a/(b/c)",
        "(a+b+c+d)",
        "a*(b+c)*(d+e)",
        "a+b*(c+d*(e+f))",
        "a+(b*c)",
        "(a+b)",
        "a+(b*c+d)",
        "a+b*c/d-e",
        "a^(b+c*d)",
        "a^b*c",
        "a*b^c",
        "(a+b)/(c+d)",
        "a-(b-(c-d))",
        "((a+b)*(c+d))^(e-f)",
        "a+b*c^d/e-f",
        "(a+b*c)-(d/e^f)+g",
        "a*(b+c*(d+e))",
        "((a+b)^c)*(d-e/f)",
        "a+b+c+d+e",
        "a*b*c*d*e",
        "a^b^c^d^e",
        "a/(b+c)*(d-e)",
        "(a+b)*(c-d)/(e+f)",
        "a+b*(c-(d/e)^f)+g",
        "((a+b)*(c+(d-e)))",
        "a*(b+(c*(d+(e*f))))",
        "(a+b)^(c+d)^(e+f)",
        "a+b*(c+d)-e/f^g*h+i",
        "((a+b)/(c-d))*((e+f)^g)",
        "a-(b+c*d/e^f)+g*h",
        "((a+b+c)*(d+e+f))",
        "(a^b)+(c^d)-(e^f)",
        "a*b+(c/d)-(e^f)+g",
        "((a+b)*(c-d)+(e/f))",
        "a+(b*(c+(d*(e+f))))",
        "(a+b+c+d+e)*(f+g+h+i)",
        "((a+b)^((c+d)*(e-f)))"};

    // for (const string &exp : testCases)
    // {
    //     cout << "Infix   : " << exp << '\n';
    //     cout << "Postfix : " << inf_to_pos(exp) << "\n\n";
    // }
    cout << "Postfix : " << inf_to_pos("a^b^c") << "\n\n";

    return 0;
}