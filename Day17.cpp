// Day 17 : Non Repeating Chracter(Given a string s consisting of lowercase English Letters. return the first non-repeating character in s. If there is no non-repeating character, return '$'.).

#include <bits/stdc++.h>
using namespace std;

char nonRepeatingChar(string &s)
{

    vector<int> freq(26, 0); // vector for counting frequency of each charcater from a-z.
    for (char c : s)
    {
        freq[c - 'a']++;
    }

    for (char c : s)
    {
        if (freq[c - 'a'] == 1)
            return c;
    }
    return '$';
}

int main()
{
    string str = "racecar";
    cout << nonRepeatingChar(str);
}