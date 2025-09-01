// Day 54 : Count distinct elements in every window.
// Given an integer array arr[] and a number k. Find the count of distinct elements in every window of size k in the array.

#include <bits/stdc++.h>
using namespace std;

vector<int> countDistinct(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> res;
    unordered_map<int, int> freq;

    for (int i = 0; i < k; i++)
    {
        freq[arr[i]]++;
    }

    res.push_back(freq.size());

    for (int i = k; i < n; i++)
    {
        freq[arr[i]]++;
        freq[arr[i - k]]--;

        if (freq[arr[i - k]] == 0)
        {
            freq.erase(arr[i - k]);
        }

        res.push_back(freq.size());
    }
    return res;
}
int main()
{
    vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;

    vector<int> res = countDistinct(arr, k);
    for (int ele : res)
        cout << ele << " ";
}