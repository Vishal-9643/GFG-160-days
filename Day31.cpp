// Day 30 : Aggressive Cows.

#include <bits/stdc++.h>
using namespace std;

bool CanWePlace(vector<int> &stalls, int dist, int cows)
{
    int Cntcow = 1, last = stalls[0];
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - last >= dist)
        {
            Cntcow++;
            last = stalls[i];
            if (Cntcow >= cows)
            {
                return true;
            }
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 0, high = stalls[n - 1] - stalls[0];
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (CanWePlace(stalls, mid, k) == true)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}

int main()
{
    vector<int> stall = {2, 12, 11, 3, 26, 7};
    int cows = 5;
    int ans = aggressiveCows(stall, cows);
    cout << ans;
}