// Day 57 :  Container With Most Water.
// Given an array arr[] of non-negative integers, where each element arr[i] represents the height of the vertical lines, find the maximum amount of water that can be contained between any two lines, together with the x-axis.

// Note: In the case of a single vertical line it will not be able to hold water.

#include <bits/stdc++.h>
using namespace std;

int maxwater(vector<int> &arr)
{
    int n = arr.size();
    int left = 0, right = n - 1;
    int ans = 0;
    while (left < right)
    {
        int water = min(arr[left], arr[right]) * (right - left);
        ans = max(ans, water);
        if (arr[left] < arr[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 5, 4, 3};
    int ans = maxwater(arr);
    cout << ans;
}