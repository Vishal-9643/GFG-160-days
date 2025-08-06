// Day 24 : Non-overlapping Intervals.
// Given a 2D array intervals[][], where intervals[i] = [starti, endi]. Return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

#include <bits/stdc++.h>
using namespace std;

int minRemoval(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    int cnt = 0;
    int end = intervals[0][1];
    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] < end)
        {
            cnt++;
            end = min(end, intervals[i][1]);
        }
        else
            end = intervals[i][1];
    }
    return cnt;
}

int main()
{
    vector<vector<int>> interval = {{1, 2}, {5, 10}, {18, 35}, {40, 45}};
    int ans = minRemoval(interval);
    cout << ans;
}