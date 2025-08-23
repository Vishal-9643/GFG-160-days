// Day 46 : Subarrays with sum K.
// Given an unsorted array arr[] of integers, find the number of subarrays whose sum exactly equal to a given number k.

#include <bits/stdc++.h>
using namespace std;

int cntSubarrays(vector<int> &arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> mp;

    int res = 0;
    int currsum = 0;

    for (int i = 0; i < n; i++)
    {
        currsum += arr[i];

        if (currsum == k)
            res++;

        if (mp.find(currsum - k) != mp.end())
            res += mp[currsum - k];

        mp[currsum]++;
    }

    return res;
}

int main()
{
    vector<int> arr = {10, 2, -2, -20, 10};
    int k = -10;
    cout << cntSubarrays(arr, k);
}