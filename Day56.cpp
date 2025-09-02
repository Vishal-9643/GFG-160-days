// Day 56 : Trapping Rain Water.
// Given an array arr[] with non-negative integers representing the height of blocks. If the width of each block is 1, compute how much water can be trapped between the blocks during the rainy season.

#include <bits/stdc++.h>
using namespace std;

int maxWater(vector<int> &arr)
{
    int n = arr.size();
    int left = 1;
    int right = n - 2;
    int lmax = arr[left - 1];
    int rmax = arr[right + 1];
    int res = 0;
    while (left <= right)
    {
        if (lmax >= rmax)
        {
            res += max(0, rmax - arr[right]);

            rmax = max(rmax, arr[right]);
            right--;
        }
        else
        {
            res += max(0, lmax - arr[left]);
            lmax = max(lmax, arr[left]);
            left++;
        }
    }

    return res;
}

int main()
{
    vector<int> arr = {2, 1, 5, 3, 1, 0, 4};
    cout << maxWater(arr);
}