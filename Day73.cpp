// Day 73 : Missing in Array.
// You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). This array represents a permutation of the integers from 1 to n with one element missing. Your task is to identify and return the missing element.

#include <bits/stdc++.h>
using namespace std;

int missingNum(vector<int> &arr)
{
    int n = arr.size();
    int XOR1 = 0, XOR2 = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        XOR1 ^= i;
    }
    for (int i = 0; i < n; i++)
    {
        XOR2 ^= arr[i];
    }

    return XOR1 ^ XOR2;
}

int main()
{
    vector<int> arr = {8, 2, 4, 5, 3, 7, 1};
    cout << missingNum(arr) << endl;
}