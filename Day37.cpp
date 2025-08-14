// Day 37 : Search in a row-wise sorted matrix.
// Given a row-wise sorted 2D matrix mat[][] of size n x m and an integer x, find whether element x is present in the matrix.
// Note: In a row-wise sorted matrix, each row is sorted in itself, i.e. for any i, j within bounds, mat[i][j] <= mat[i][j+1].

#include <bits/stdc++.h>
using namespace std;

// Function to search a given number in row-column sorted matrix.
bool RowSearch(vector<int> &arr, int x)
{
    int low = 0;
    int high = arr.size() - 1;
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
bool searchRowMatrix(vector<vector<int>> &mat, int x)
{
    int n = mat.size();
    for (int i = 0; i < n; i++)
    {
        if (RowSearch(mat[i], x))
            return true;
    }

    return false;
}

int main() {
    vector<vector<int>> mat = {{3, 4, 9},
                               {2, 5, 6},
                               {9, 25, 27}};
    int x = 9;
    if(searchRowMatrix(mat, x)) 
        cout << "true";
    else 
        cout << "false";
}