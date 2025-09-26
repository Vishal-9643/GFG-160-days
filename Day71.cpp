// Day 71 : Word Search.
// You are given a matrix mat[][] of size n*m containing english alphabets and a string word. Check if the word exists on the mat[][] or not. The word can be constructed by using letters from adjacent cells, either horizontally or vertically. The same cell cannot be used more than once.

#include <bits/stdc++.h>
using namespace std;

bool found(vector<vector<char>> &mat, int i, int j, string &word, int idx)
{
    if (idx == word.size())
        return true;
    if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size())
        return false;
    if (mat[i][j] != word[idx])
        return false;

    char temp = mat[i][j];
    mat[i][j] = '@';

    bool match = found(mat, i - 1, j, word, idx + 1) || // checking left
                 found(mat, i + 1, j, word, idx + 1) || // checking right
                 found(mat, i, j - 1, word, idx + 1) || // checking top
                 found(mat, i, j + 1, word, idx + 1);   // checking bottom

    mat[i][j] = temp;
    return match;
}
bool isWordExist(vector<vector<char>> &mat, string &word)
{
    int n = mat.size();
    int m = mat[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (found(mat, i, j, word, 0))
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> mat = {{'a', 'x', 'm', 'y'},
                                {'b', 'g', 'd', 'f'},
                                {'x', 'e', 'e', 't'},
                                {'r', 'a', 'k', 's'}};
    string word = "geeks";
    cout << (isWordExist(mat, word) ? "true" : "false");
}