// Day 80 : Next Greater Element.
/*
You are given an array arr[] of integers, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> nextLargerElement(vector<int> &arr)
{

    int n = arr.size();
    vector<int> NGE(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            NGE[i] = -1;
        }
        else
        {
            NGE[i] = st.top();
        }
        st.push(arr[i]);
    }

    return NGE;
}

int main()
{

    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> res = nextLargerElement(arr);
    for (int x : res)
    {
        cout << x << " ";
    }

    return 0;
}