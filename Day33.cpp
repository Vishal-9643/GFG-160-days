// Day 33 : Kth Missing Positive Number in a Sorted Array.
// Given a sorted array of distinct positive integers arr[], You need to find the kth positive number that is missing from the arr[].

#include <bits/stdc++.h>
using namespace std;

int kthMissing(vector<int> &arr, int k)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    // Handle those case where arr contain all number from 1 to n.
    int result = n + k;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > mid + k)
        {
            result = mid + k;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return result;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    int k = 2;
    cout << kthMissing(arr, k);
}