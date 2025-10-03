// Day 75 : Unique Number II.
// Given an array arr[] containing 2*n + 2 positive numbers, out of which 2*n numbers exist in pairs whereas only two number occur exactly once and are distinct. Find the other two numbers. Return the answer in increasing order.

#include <bits/stdc++.h>
using namespace std;

vector<int> singleNum(vector<int> &arr)
{

    vector<int> res;
    int XOR = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        XOR ^= arr[i];
    }
    int set_bit = XOR & -XOR;
    int G0 = 0, G1 = 0;
    for (int i : arr)
    {
        if (i & set_bit)
            G1 ^= i;
        else
            G0 ^= i;
    }

    if (G1 > G0)
    {
        res.push_back(G0);
        res.push_back(G1);
    }
    else
    {
        res.push_back(G1);
        res.push_back(G0);
    }

    return res;
}

int main()
{
    vector<int> arr = {1, 2, 3, 2, 1, 4};
    vector<int> ans = singleNum(arr);
    for (auto it : ans)
        cout << it << " ";
}