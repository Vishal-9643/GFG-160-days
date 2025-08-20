// Day 43 : Union of Arrays with Duplicates.

// You are given two arrays a[] and b[], return the Union of both the arrays in any order.

// The Union of two arrays is a collection of all distinct elements present in either of the arrays. If an element appears more than once in one or both arrays, it should be included only once in the result.

// Note: Elements of a[] and b[] are not necessarily distinct.
// Note that, You can return the Union in any order but the driver code will print the result in sorted order only.

#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();
    vector<int> res;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            if (res.empty() || res.back() != a[i])
            {
                res.push_back(a[i]);
            }
            i++;
        }
        else if (a[i] > b[j])
        {
            if (res.empty() || res.back() != b[j])
            {
                res.push_back(b[j]);
            }
            j++;
        }
        else
        {
            if (res.empty() || res.back() != a[i])
            {
                res.push_back(a[i]);
            }
            i++;
            j++;
        }
    }
    // Loop for remaning element in arr a.
    while (i < n)
    {
        if (res.empty() || res.back() != a[i])
        {
            res.push_back(a[i]);
        }
        i++;
    }
    // Loop for remaning element is arr b.
    while (j < m)
    {
        if (res.empty() || res.back() != b[j])
        {
            res.push_back(b[j]);
        }
        j++;
    }

    return res;
}

int main()
{
    vector<int> a = {1, 2, 3, 2, 1};
    vector<int> b = {3, 2, 2, 3, 3, 2};

    vector<int> res = findUnion(a, b);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}