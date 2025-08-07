// Day 29 : Peak element.
// You are given an array arr[] where no two adjacent elements are same, find the index of a peak element. An element is considered to be a peak if it is greater than its adjacent elements (if they exist).
// Note: Consider the element before the first element and the element after the last element to be negative infinity.

#include <bits/stdc++.h>
using namespace std;

int peakElement(vector<int> &arr)
{
    int n = arr.size();
    // If arrray has only 1 elemnet then it is peak elemnet.
    if (n == 1)
    {
        return 0;
    }
    // checking for index 0 element as a peak element.
    if (arr[0] > arr[1])
    {
        return 0;
    }
    // checking for last elemnet as a peak element.
    if (arr[n - 1] > arr[n - 2])
    {
        return n - 1;
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
        {
            return i;
        }
    }

    return -1;
}

int main(){
    vector<int> arr = {1, 2, 4, 5, 7, 8, 3};
    int peak = peakElement(arr);
    cout << "Peak element is at index : " << peak;
}