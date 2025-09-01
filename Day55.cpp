// Day 55 : Longest substring with distinct characters.
// You are given a string s. You have to find the length of the longest substring with all distinct characters.

#include <bits/stdc++.h>
using namespace std;

int longestUniqueSubstr(string &s)
{
    if (s.length() == 0 || s.length() == 1)
    {
        return s.length();
    }

    int res = 0;
    vector<bool> visited(26, 0);

    int left = 0, right = 0;
    while (right < s.length())
    {

        while (visited[s[right] - 'a'] == true)
        {
            visited[s[left] - 'a'] = false;
            left++;
        }
        visited[s[right] - 'a'] = true;

        res = max(res, (right - left) + 1);
        right++;
    }
    return res;
}

int main()
{
    string s = "vishalprajapati";
    cout << longestUniqueSubstr(s);
}
