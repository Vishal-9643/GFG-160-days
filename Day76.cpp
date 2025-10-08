// Day 76 : Parenthesis Checker.
// Given a string s, composed of different combinations of '(' , ')', '{', '}', '[', ']'. Determine whether the Expression is balanced or not.
/*
An expression is balanced if:
1.Each opening bracket has a corresponding closing bracket of the same type.
2.Opening brackets must be closed in the correct order.
*/

#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string &s)
{
    stack<char> st;
    for (char it : s)
    {
        if (it == '(' || it == '{' || it == '[')
        {
            st.push(it); // pushing opening parenthesis.
        }
        else
        {
            if (st.empty())
                return false;
            char ch = st.top();
            st.pop();
            if ((it == ')' && ch == '(') || (it == '}' && ch == '{') || (it == ']' && ch == '['))
                continue; // checking closing parenthesis.
            else
                return false;
        }
    }

    return st.empty();
}

int main()
{
    string s = "[()()]{}";
    cout << (isBalanced(s) ? "true" : "false");
    return 0;
}