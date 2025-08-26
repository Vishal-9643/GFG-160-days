// Day 49 : Count Pairs whose sum is less than target.
// Given an array arr[] and an integer target. You have to find the number of pairs in the array whose sum is strictly less than the target.

#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int> &arr, int target)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int cnt = 0;
    int i = 0, j = n - 1;

    while (i < j)
    {
        int sum = arr[i] + arr[j];

        if (sum < target)
        {
            cnt += j - i;
            i++;
        }
        else
        {
            j--;
        }
    }

    return cnt;
}

int main()
{
    vector<int> arr = {2, 1, 8, 3, 4, 7, 6, 5};
    int target = 7;
    cout << countPairs(arr, target);
}