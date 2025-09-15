// Day 67 : Permutations of a String.
// Given a string s, which may contain duplicate characters, your task is to generate and return an array of all unique permutations of the string. You can return your answer in any order.

#include <bits/stdc++.h>
using namespace std;

void generate(string &s, int idx, set<string> &unique)
{
    if (idx == s.length())
    {
        unique.insert(s); // using set to avoid duplicate permutation.
        return;
    }
    for (int i = idx; i < s.length(); i++)
    {
        swap(s[idx], s[i]);
        generate(s, idx + 1, unique);
        swap(s[idx], s[i]);
    }
}
vector<string> findPermutation(string &s)
{
    set<string> unique;
    generate(s, 0, unique);

    return vector<string>(unique.begin(), unique.end());
}

int main()
{
    string s = "ABC";
    vector<string> res = findPermutation(s);

    // Print the permutations.
    for (string perm : res)
        cout << perm << " ";
}