// Day 78 : Postfix Evaluation.
/*
You are given an array of strings arr[] that represents a valid arithmetic expression written in Reverse Polish Notation (Postfix Notation). Your task is to evaluate the expression and return an integer representing its value.

Note: A postfix expression is of the form operand1 operand2 operator (e.g., "a b +").
And the division operation between two integers always computes the floor value, i.e floor(5 / 3) = 1 and floor(-5 / 3) = -2.
It is guaranteed that the result of the expression and all intermediate calculations will fit in a 32-bit signed integer
*/

#include <bits/stdc++.h>
using namespace std;

int floorDivision(int a, int b)
{
    if (a * b < 0 && a % b != 0)
    {
        return (a / b) - 1;
    }
    return a / b;
}
int evaluatePostfix(vector<string> &arr)
{
    stack<int> st;

    for (string s : arr)
    {
        if (isdigit(s[0]) || (s.size() > 1 && s[0] == '-')) // if it is oprand push into stack.
        {
            st.push(stoi(s));
        }
        else
        {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();

            if (s == "+")
                st.push(val2 + val1);
            else if (s == "-")
                st.push(val2 - val1);
            else if (s == "*")
                st.push(val2 * val1);
            else if (s == "/")
                st.push(floorDivision(val2, val1));
            else if (s == "^")
                st.push((int)pow(val2, val1));
        }
    }

    return st.top();
}

int main()
{
    vector<string> arr = {"2", "3", "1", "*", "+", "9", "-"};
    cout << evaluatePostfix(arr) << endl;
    return 0;
}