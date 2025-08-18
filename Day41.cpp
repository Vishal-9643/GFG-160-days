// Day 41 : Count pairs with given sum.
// You are given an array arr[] and an integer target. You have to count all pairs in the array such that their sum is equal to the given target.

#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int> &arr, int target)
{
    int n = arr.size();
    unordered_map<int, int> freq;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (freq.find(target - arr[i]) != freq.end())
        {
            cnt += freq[target - arr[i]];
        }
        freq[arr[i]]++;
    }
    return cnt;
}

int main()
{
    vector<int> arr = {1, 5, 7, -1, 5};
    int target = 6;
    cout << countPairs(arr, target) << endl;
}