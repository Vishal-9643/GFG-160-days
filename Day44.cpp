// Day 44 : Longest Consecutive Subsequence.
// Given an array arr[] of non-negative integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &arr)
{
    int n = arr.size();
    int MaxEle = *max_element(arr.begin(), arr.end());
    vector<int> hash(MaxEle + 1, 0);

    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    int cnt = 0;
    int res = 0;
    for (int i = 0; i <= MaxEle; i++)
    {
        if (hash[i] == 0)
        {
            cnt = 0;
        }
        else
        {
            cnt++;
            res = max(res, cnt);
        }
    }
    return res;
}

int main()
{
    vector<int> arr = {2, 6, 1, 9, 4, 5, 3};
    cout << longestConsecutive(arr);
}