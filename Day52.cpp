// Day 52 : Count the number of possible triangles.
// Given an integer array arr[]. Find the number of triangles that can be formed with three different array elements as lengths of three sides of the triangle. A triangle with three given sides is only possible if sum of any two sides is always greater than the third side.

#include <bits/stdc++.h>
using namespace std;

int countTriangles(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int res = 0;
    for (int i = n - 1; i >= 2; i--)
    {
        int j = 0, k = i - 1;
        while (j < k)
        {
            if (arr[j] + arr[k] > arr[i])
            {
                res += k - j;
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return res;
}

int main()
{
    vector<int> arr = {4, 6, 3, 7};
    cout << countTriangles(arr);
}