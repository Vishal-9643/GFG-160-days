// Day 81 : Stock span problem.
/*
The stock span problem is a financial problem where we have a series of daily price quotes for a stock and we need to calculate the span of stock price for all days.
You are given an array arr[] representing daily stock prices, the stock span for the i-th day is the number of consecutive days up to day i (including day i itself) for which the price of the stock is less than or equal to the price on day i. Return the span of stock prices for each day in the given sequence.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> calculateSpan(vector<int> &arr)
{

    int n = arr.size();
    vector<int> span(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            span[i] = (i + 1);
        }
        else
        {
            span[i] = (i - st.top());
        }

        st.push(i);
    }

    return span;
}

int main()
{

    vector<int> arr = {10, 4, 5, 90, 120, 80};
    vector<int> span = calculateSpan(arr);
    for (int x : span)
    {
        cout << x << " ";
    }
    return 0;
}