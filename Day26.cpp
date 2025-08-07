// Day 26 : Number of occurrence.
// Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[].

#include <bits/stdc++.h>
using namespace std;

int countFreq(vector<int> &arr, int target)
{
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
            cnt++;
    }
    return cnt;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 2, 2, 3};
    int Target = 3;
    int Cnt = countFreq(arr, Target);
    cout << Cnt;
}