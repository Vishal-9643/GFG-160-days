// Day 16 : Anagram (Two strings are considered anagrams if they contain the same characters with exactly the same frequencies, regardless of their order.).

#include <bits/stdc++.h>
using namespace std;

bool areAnagrams(string &s1, string &s2)
{
    int n1 = s1.size();
    int n2 = s2.size();
    string str1 = s1; // Copying string.
    string str2 = s2;
    sort(str1.begin(), str1.end()); // sorting the copied string.
    sort(str2.begin(), str2.end());
    if (n1 != n2)
    {
        return false; // if size not equal then not anagram.
    }
    else
    {
        for (int i = 0; i < n1; i++)
        {
            if (str1[i] != str2[i])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    string s1 = "listen";
    string s2 = "lists";
    string s3 = "geeks";
    string s4 = "skeeg";
    cout << areAnagrams(s1, s2) << endl;
    cout << areAnagrams(s3, s4);
}