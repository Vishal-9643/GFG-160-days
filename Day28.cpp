// Day 28 : Search in Rotated Sorted Array.
// Given a sorted and rotated array arr[] of distinct elements, the task is to find the index of a target key.  If the key is not present in the array, return -1.

#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &arr, int key)
{

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int key = 3;
    int idx = search(arr, key);
    cout << idx;
}