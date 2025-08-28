// Day 51 : Pair with given sum in a sorted array.
// You are given an integer target and an array arr[]. You have to find number of pairs in arr[] which sums up to target. It is given that the elements of the arr[] are in sorted order.
// Note: pairs should have elements of distinct indexes.

#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int> &arr, int target)
{

    int n = arr.size();
    int res = 0;
    int i = 0, j = n - 1;
    while (i < j)
    {
        int sum = arr[i] + arr[j];
        if (sum > target)
        {
            j--;
        }
        else if (sum < target)
        {
            i++;
        }
        else
        {
            int cnt1 = 0, cnt2 = 0;
            int ele1 = arr[i], ele2 = arr[j];

            while (i <= j && arr[i] == ele1)
            {
                i++;
                cnt1++;
            }
            while (i <= j && arr[j] == ele2)
            {
                j--;
                cnt2++;
            }

            if (ele1 == ele2)
            {
                res += (cnt1 * (cnt1 - 1)) / 2;
            }
            else
            {
                res += (cnt1 * cnt2);
            }
        }
    }
    return res;
}

int main()
{
    vector<int> arr = {-1, 1, 5, 5, 7};
    int target = 6;

    cout << countPairs(arr, target);
}