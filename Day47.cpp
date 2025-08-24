// Day 47 : Count Subarrays with given XOR.
// Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k.

#include <bits/stdc++.h>
using namespace std;

long subarrayXor(vector<int> &arr, int k)
{
    unordered_map<int, int> mp;

    int res = 0;
    int XOR = 0;

    for (int val : arr)
    {
        XOR = XOR ^ val;

        res = res + mp[XOR ^ k];

        if (XOR == k)
            res++;

        mp[XOR]++;
    }

    return res;
}

int main()
{
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;

    cout << subarrayXor(arr, k);
    return 0;
}