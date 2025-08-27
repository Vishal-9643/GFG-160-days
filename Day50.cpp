// Day 50 : Sum Pair closest to target.
// Given an array arr[] and a number target, find a pair of elements (a, b) in arr[], where a ≤ b whose sum is closest to target.
// Note: Return the pair in sorted order and if there are multiple such pairs return the pair with maximum absolute difference. If no such pair exists return an empty array.

#include <bits/stdc++.h>
using namespace std;

vector<int> sumClosest(vector<int> &arr, int target)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<int> res;
    int minDiff = INT_MAX;
    int left = 0, right = n - 1;

    while (left < right)
    {
        int Currsum = arr[left] + arr[right];

        if (abs(Currsum - target) < minDiff)
        {
            minDiff = abs(Currsum - target);
            res = {arr[left], arr[right]};
        }

        else if (Currsum > target)
        {
            right--;
        }
        else if (Currsum < target)
        {
            left++;
        }
        else
        {
            return res;
        }
    }

    return res;
}

int main()
{
    vector<int> arr = {5, 2, 7, 1, 4};
    int target = 10;

    vector<int> res = sumClosest(arr, target);
    if (res.size() > 0)
        cout << res[0] << " " << res[1];
}