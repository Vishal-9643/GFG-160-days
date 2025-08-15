// Day 38 : Search in a sorted Matrix.
// Given a strictly sorted 2D matrix mat[][] of size n x m and a number x. Find whether the number x is present in the matrix or not.
// Note: In a strictly sorted matrix, each row is sorted in strictly increasing order, and the first element of the ith row (i!=0) is greater than the last element of the (i-1)th row.

#include <bits/stdc++.h>
using namespace std;

bool rowSearch(vector<int> &arr, int x)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            return true;
        }
        else if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return false;
}
bool searchMatrix(vector<vector<int>> &mat, int x)
{
    int n = mat.size();
    int m = mat[0].size();
    int j = m - 1;
    for (int i = 0; i < n; i++)
    {
        if (x >= mat[i][0] && mat[i][j] >= x)
        {
            if (rowSearch(mat[i], x))
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> mat = {{1, 5, 9}, {14, 20, 21}, {30, 34, 43}};
    int x = 14;

    if (searchMatrix(mat, x))
        cout << "true";
    else
        cout << "false";
}