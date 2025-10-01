// Day 74 : Unique Number I.
// Given a unsorted array arr[] of positive integers having all the numbers occurring exactly twice, except for one number which will occur only once. Find the number occurring only once.

#include <bits/stdc++.h>
using namespace std;

int findUnique(vector<int> &arr)
{
    int unique = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        unique = unique ^ arr[i];
    }

    return unique;
}

int main()
{
    vector<int> arr = {2, 3, 5, 4, 5, 3, 4};
    cout << findUnique(arr) << endl;
}