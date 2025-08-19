// Day 42 : Intersection of Two arrays with Duplicate Elements.

// iven two integer arrays a[] and b[], you have to find the intersection of the two arrays. Intersection of two arrays is said to be elements that are common in both the arrays. The intersection should not have duplicate elements and the result should contain items in any order.

// Note: The driver code will sort the resulting array in increasing order before printing.

#include <bits/stdc++.h>
using namespace std;

vector<int> intersect(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();
    vector<int> res;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {
            if (res.size() == 0 || res.back() != a[i])
            {
                res.push_back(a[i]);
            }
            i++;
            j++;
        }
        else if (a[i] > b[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    return res;
}

int main()
{
    vector<int> a = {1, 2, 3, 2, 1};
    vector<int> b = {3, 2, 2, 3, 3, 2};

    vector<int> res = intersect(a, b);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}