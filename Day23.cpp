// // Day 23 : Insert Interval
// // Geek has an array of non-overlapping intervals intervals[][] where intervals[i] = [starti , endi] represent the start and the end of the ith event and intervals is sorted in ascending order by starti . He wants to add a new interval newInterval[] = [newStart, newEnd] where newStart and newEnd represent the start and end of this interval.
// Help Geek to insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();

    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || intervals[i][0] > ans.back()[1])
        {
            ans.push_back(intervals[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {2, 4}, {6, 8}, {9, 10}};
    vector<int> newInterval = {4, 6};
    vector<vector<int>> ans = insertInterval(arr, newInterval);
    for (const auto &interval : ans)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "]" << endl;
    }
}