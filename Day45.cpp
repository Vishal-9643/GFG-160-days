// Day 45 : Print Anagrams Together.
// Given an array of strings, return all groups of strings that are anagrams. The strings in each group must be arranged in the order of their appearance in the original array. Refer to the sample case for clarification.

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> anagrams(vector<string> &arr)
{
    // code here
    unordered_map<string, vector<string>> mp;

    for (string s : arr)
    {
        string key = s;
        sort(key.begin(), key.end());
        mp[key].push_back(s);
    }

    vector<vector<string>> result;

    unordered_set<string> seen;

    for (string s : arr)
    {
        string key = s;
        sort(key.begin(), key.end());

        if (seen.find(key) == seen.end())
        {
            result.push_back(mp[key]);
            seen.insert(key);
        }
    }

    return result;
}

int main()
{
    vector<string> arr = {"act", "god", "cat", "dog", "tac"};

    vector<vector<string>> res = anagrams(arr);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }
}