// Day 70 : Solve the Sudoku.
// Given an incomplete Sudoku configuration in terms of a 9x9  2-D interger square matrix, mat[][], the task is to solve the Sudoku. It is guaranteed that the input Sudoku will have exactly one solution.

/* A sudoku solution must satisfy all of the following rules:

   Each of the digits 1-9 must occur exactly once in each row.
   Each of the digits 1-9 must occur exactly once in each column.
   Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

 Note: Zeros represent blanks to be filled with numbers 1-9, while non-zero cells are fixed and cannot be changed.*/

#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &mat, int i, int j, int k)
{
    for (int a = 0; a < 9; a++)
    {
        if (mat[a][j] == k) // checking in column.
            return false;
        if (mat[i][a] == k) // checking in row.
            return false;

        if (mat[3 * (i / 3) + a / 3][3 * (j / 3) + a % 3] == k) // checking in 3*3 box.
            return false;
    }
    return true;
}
bool solve(vector<vector<int>> &mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (mat[i][j] == 0)
            {
                for (int k = 1; k <= 9; k++)
                {
                    if (isSafe(mat, i, j, k))
                    {
                        mat[i][j] = k;
                        if (solve(mat))
                            return true;
                        mat[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>> &mat)
{
    solve(mat);
}

int main()
{
    vector<vector<int>> mat = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    solveSudoku(mat);

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat.size(); j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    return 0;
}