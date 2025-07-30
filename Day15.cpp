// Day 15 : Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.

#include <bits/stdc++.h>
using namespace std;

string addBinary(string &s1, string &s2)
{
    string result = "";
    int i = s1.size() - 1;
    int j = s2.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;

        if (i >= 0)
        {
            sum += s1[i--] - '0'; // converting char to int.
        }
        if (j >= 0)
        {
            sum += s2[j--] - '0';
        }

        result.push_back((sum % 2) + '0'); // appending result bit.
        carry = sum / 2;                   // updating Carry.
    }
    // Our result is in reverse order so reverse the string result.
    reverse(result.begin(), result.end());
    // Removing Leading zero.
    size_t pos = result.find_first_not_of('0');
    if (pos != string::npos)
    {
        return result.substr(pos); // return the string without leading zero.
    };

    return "0"; // if result store only zeros.
}

int main()
{
    string s1 = "00100";
    string s2 = "010";
    string result = addBinary(s1, s2);
    cout << result;
}