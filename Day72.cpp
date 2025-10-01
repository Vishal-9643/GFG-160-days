// Day 72 : Find Only Repetitive Element from 1 to n-1.
// Given an array arr[] of size n, filled with numbers from 1 to n-1 in random order. The array has only one repetitive element. Your task is to find the repetitive element.

// Note: It is guaranteed that there is a repeating element present in the array.

#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr)
{
    int n = arr.size();
    int XOR = 0;
    for (int i = 0; i < n; i++)
    {
        XOR = XOR ^ i ^ arr[i]; // same number XOR (^) gives zero so index and number give zero and one repeated number reamin. 
    }

    return XOR;
}

int main()
{
    vector<int> arr = {1, 3, 2, 3, 4};
    cout << findDuplicate(arr);
}