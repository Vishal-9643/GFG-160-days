// Day 27 : Sorted and Rotated Minimum.
// A sorted array of distinct elements arr[] is rotated at some unknown point, the task is to find the minimum element in it.

#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &arr)
{
    int Min = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        Min = min(Min, arr[i]);
    }
    return Min;
}

int main()
{
    vector<int> arr = {5, 6, 1, 2, 3, 4};
    int Minimum = findMin(arr);
    cout << Minimum;
}