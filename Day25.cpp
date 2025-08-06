// Day 25 : Merge Without Extra Space.
// Given two sorted arrays a[] and b[] of size n and m respectively, the task is to merge them in sorted order without using any extra space. Modify a[] so that it contains the first n elements and modify b[] so that it contains the last m elements.

#include <bits/stdc++.h>
using namespace std;

void mergeArrays(vector<int> &a, vector<int> &b)
{

    int n = a.size();
    int m = b.size();

    int p1 = n - 1;
    int p2 = 0;

    while (p1 >= 0 && p2 < m && a[p1] > b[p2])
    {
        swap(a[p1], b[p2]);
        p1--;
        p2++;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

int main()
{
    vector<int> A = {1, 5, 9, 10, 15, 20};
    vector<int> B = {2, 3, 8, 13};
    mergeArrays(A, B);
    for (int i : A)
    {
        cout << i << " ";
    }
    for (int i : B)
    {
        cout << i << " ";
    }
}