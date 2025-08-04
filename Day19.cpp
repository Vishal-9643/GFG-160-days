// // Day 19 : Sort 0s, 1s and 2s (Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order. Note: You need to solve this problem without utilizing the built-in sort function.).

#include <bits/stdc++.h>
using namespace std;
// Using Dutch National Flag Algorithm.
void sort012(vector<int> &arr)
{

    // initialize three pointers.
    // lo: boundary for 0s.
    // mid: current element being checked.
    // hi: boundary for 2s.
    int n = arr.size();
    int lo = 0, mid = 0, hi = n - 1;

    // process elements until mid crosses hi.
    while (mid <= hi)
    {
        // current is 0: swap with lo and move both.
        // pointers forward.
        if (arr[mid] == 0)
        {
            swap(arr[mid++], arr[lo++]);
        }
        else if (arr[mid] == 1)
        {
            // current is 1: it's already in correct position.
            mid++;
        }
        else
        {
            // current is 2: swap with hi and move hi backward.
            // do not increment mid, as swapped value needs.
            // to be re-checked.
            swap(arr[mid], arr[hi--]);
        }
    }
}

int main()
{
    vector<int> arr = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    sort012(arr);
    for (int i : arr)
    {
        cout << i << " ";
    }
}