// Day 69 : N-Queen Problem.
// The n-queens puzzle is the problem of placing n queens on a (n × n) chessboard such that no two queens can attack each other. Note that two queens attack each other if they are placed on the same row, the same column, or the same diagonal.

#include <bits/stdc++.h>
using namespace std;
// function for checking Queen is present or not in row , col and diagonal direction.
bool isSafe(int row, int col, vector<int> &board)
{
    for (int i = 0; i < col; i++)
    {
        int prow = board[i];
        int pcol = i;

        if (prow == row) // checking
            return false;

        if (abs(prow - row) == abs(pcol - col)) // checking diagonals.
            return false;
    }
    return true;
}

void solve(int col, vector<vector<int>> &res, vector<int> &board, int n)
{
    if (col == n)
    {
        res.push_back(board);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (isSafe(i, col, board))
        {
            board.push_back(i);
            solve(col + 1, res, board, n);
            board.pop_back();
        }
    }
}
vector<vector<int>> nQueen(int n)
{
    vector<vector<int>> res;
    vector<int> board;
    solve(0, res, board, n);
    return res;
}

int main()
{
    int n = 4;
    vector<vector<int>> res = nQueen(n);

    for (int i = 0; i < res.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < n; ++j)
        {
            cout << res[i][j];
            if (j != n - 1)
                cout << " ";
        }
        cout << "]\n";
    }
    return 0;
}