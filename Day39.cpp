// Day 39 : Set Matrix Zeros.

#include <bits/stdc++.h>
using namespace std;

void setMatrixZeroes(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<int> r(n, 0);
    vector<int> c(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                r[i] = 1;
                c[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (r[i] == 1 || c[j] == 1)
            {
                mat[i][j] = 0;
            }
        }
    }
}

int main()
{
    vector<vector<int>> mat = {{0, 1, 2, 0},
                               {3, 4, 0, 2},
                               {1, 3, 1, 5}};

    setMatrixZeroes(mat);
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}