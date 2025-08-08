// Day 30 : K-th element of two Arrays.
// Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the kth position of the combined sorted array.

#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int> &b, int k)
{
    vector<int> C;
    for (int i = 0; i < a.size(); i++)
    {
        C.push_back(a[i]);
    }
    for (int j = 0; j < b.size(); j++)
    {
        C.push_back(b[j]);
    }
    sort(C.begin(), C.end());
    return C[k - 1];
}

int main()
{
    vector<int> A = {2, 3, 6, 7, 9};
    vector<int> B = {1, 4, 8, 10};
    int k = 5;
    cout << kthElement(A, B, k);
}