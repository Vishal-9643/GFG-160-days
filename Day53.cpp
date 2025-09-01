// Day 53 : Indexes of Subarray Sum.
// Given an array arr[] containing only non-negative integers, your task is to find a continuous subarray (a contiguous sequence of elements) whose sum equals a specified value target. You need to return the 1-based indices of the leftmost and rightmost elements of this subarray. You need to find the first subarray whose sum is equal to the target.

// Note: If no such array is possible then, return [-1].

#include <bits/stdc++.h>
using namespace std;

vector<int> subarraySum(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<int> res;
    int st = 0, end = 0;

    int currsum = 0;

    for (int i = 0; i < n; i++)
    {
        currsum += arr[i];

        if (currsum >= target)
        {
            end = i;

            while (currsum > target && st < end)
            {
                currsum -= arr[st];
                st++;
            }

            if (currsum == target)
            {
                res.push_back(st + 1);
                res.push_back(end + 1);
                return res;
            }
        }
    }

    return {-1};
}

int main()
{
    vector<int> arr = {15, 2, 4, 8, 9, 5, 10, 23};
    int target = 23;
    vector<int> res = subarraySum(arr, target);

    for (int ele : res)
        cout << ele << " ";
}