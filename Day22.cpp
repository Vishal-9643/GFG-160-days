// Day 22 : Merger Overlaping Interval.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlap(vector<vector<int>> &arr)
{
    // Sort the intervals based on the starting point
    // This ensures that overlapping intervals are adjacent
    sort(arr.begin(), arr.end());

    int n = arr.size();      // Total number of intervals
    vector<vector<int>> ans; // This will store the final merged intervals

    for (int i = 0; i < n; i++)
    {
        // If ans is empty, or current interval does not overlap with the last interval in ans
        // (i.e., current interval starts after the last interval ends)
        if (ans.empty() || arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]); // Add current interval to ans as it doesn't overlap
        }
        else
        {
            // There is an overlap with the last interval in ans
            // Merge the intervals by updating the end of the last interval
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans; // Return the merged list of intervals
}
int main()
{
    vector<vector<int>> arr = {{1, 3}, {2, 4}, {6, 8}, {9, 10}};
    vector<vector<int>> ans = mergeOverlap(arr);
    for (const auto &interval : ans)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "]" << endl;
    }
}