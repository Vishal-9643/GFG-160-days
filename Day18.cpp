// Day 18 : Search Pattern (KMP-Algorithm).

#include <bits/stdc++.h>
using namespace std;

void constructLPS(string &pat, vector<int> &lps)
{
    // Function to build the LPS (Longest Prefix Suffix) array.
    int n = pat.size();
    lps[0] = 0;  // lps[0] is always 0.
    int len = 0; // length of the previous longest prefix suffix.
    int i = 1;
    while (i < n)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> search(string &pat, string &txt)
{
    int n = txt.size();
    int m = pat.size();

    vector<int> LPS(m);
    vector<int> result;

    constructLPS(pat, LPS);

    int i = 0, j = 0;
    while (i < n)
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;

            if (j == m)
            {
                result.push_back(i - j);

                j = LPS[j - 1];
            }
        }
        else
        {
            if (j != 0)
            {
                j = LPS[j - 1];
            }
            else
                i++;
        }
    }
    return result;
}

int main()
{
    string text = "aabaacaadaabaaba";
    string pattern = "aaba";
    vector<int> Ans = search(pattern, text);
    for (int i : Ans)
    {
        cout << i << " ";
    }
}