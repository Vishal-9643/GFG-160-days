// Day 79 : Longest valid Parentheses.

/*
Given a string s consisting of opening and closing parenthesis '(' and ')'. Find the length of the longest valid parenthesis substring.

A parenthesis string is valid if:

For every opening parenthesis, there is a closing parenthesis.
The closing parenthesis must be after its opening parenthesis.
*/

#include <bits/stdc++.h>
using namespace std;

int maxLength(string &s)
{
    // code here
    stack<int> st;
    int maxlen = 0;
    st.push(-1);

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            st.push(i);
        else
        {
            st.pop();

            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                maxlen = max(maxlen, i - st.top());
            }
        }
    }
    return maxlen;
}

int main()
{
    string s = "(()())";
    cout << maxLength(s) << endl;
    return 0;
}