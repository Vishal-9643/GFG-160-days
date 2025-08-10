// // Day 32 : Allocate Minimum Pages.
// // Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

// Each student receives atleast one book.
// Each student is assigned a contiguous sequence of books.
// No book is assigned to more than one student.
// The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

// Note: If it is not possible to allocate books to all students, return -1.

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &arr, int k, int pagelimit)
{
    int cnt = 1, pagesum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (pagesum + arr[i] > pagelimit)
        {
            cnt++;
            pagesum = arr[i];
        }
        else
        {
            pagesum += arr[i];
        }
    }
    if (cnt <= k)
        return true;
    else
        return false;
}
int findPages(vector<int> &arr, int k)
{

    int n = arr.size();

    if (k > n)
    {
        return -1;
    }

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (check(arr, k, mid) == true)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> book = {12, 34, 67, 90};
    int student = 2;
    int ans = findPages(book, student);
    cout << ans;
}