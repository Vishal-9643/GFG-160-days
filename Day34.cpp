// Day 34 : Spirally traversing a matrix.
// You are given a rectangular matrix mat[][] of size n x m, and your task is to return an array while traversing the matrix in spiral form.

#include <bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;
    vector<int> result;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            result.push_back(mat[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            result.push_back(mat[i][right]);
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                result.push_back(mat[bottom][i]);
            }
        }
        bottom--;
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                result.push_back(mat[i][left]);
            }
        }
        left++;
    }

    return result;
}
int main()
{

    vector<vector<int>> mat = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16}};

    vector<int> res = spirallyTraverse(mat);
    for (int ele : res)
        cout << ele << " ";
}