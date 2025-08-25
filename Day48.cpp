// Day 48 : Count all triplets with given sum in sorted array.
// Given a sorted array arr[] and a target value, the task is to count triplets (i, j, k) of valid indices, such that arr[i] + arr[j] + arr[k] = target and i < j < k.

#include <bits/stdc++.h>
using namespace std;

int countTriplets(vector<int> &arr, int target)
{
    // Code Here
    int n = arr.size();
    int cnt = 0;

    for (int i = 0; i < n - 2; i++)
    {

        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum == target)
            {
                int ele1 = arr[j], ele2 = arr[k];
                int c1 = 0, c2 = 0;

                while (j <= k && arr[j] == ele1)
                {
                    j++;
                    c1++;
                }
                while (j <= k && arr[k] == ele2)
                {
                    k--;
                    c2++;
                }

                if (ele1 == ele2)
                {
                    cnt += (c1 * (c1 - 1)) / 2;
                }
                else
                {
                    cnt += (c1 * c2);
                }
            }
            else if (sum > target)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return cnt;
}

int main()
{
    vector<int> arr = {-3, -1, -1, 0, 1, 2};
    int target = -2;

    cout << countTriplets(arr, target) << endl;
}