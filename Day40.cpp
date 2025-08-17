// Day 40 : Two Sum - Pair with Given Sum.
// Given an array arr[] of integers and another integer target. Determine if there exist two distinct indices such that the sum of their elements is equal to the target.

#include <bits/stdc++.h>
using namespace std;

bool twoSum(vector<int> &arr, int target)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] > target)
        {
            j--;
        }
        else if (arr[i] + arr[j] < target)
        {
            i++;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {0, -1, 2, -3, 1};
    int target = -2;

    if (twoSum(arr, target))
        cout << "true";
    else
        cout << "false";
}