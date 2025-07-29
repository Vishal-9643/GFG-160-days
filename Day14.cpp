// Day 14 : Implement Atoi (means converting string number into int).

#include <bits/stdc++.h>
using namespace std;

int myAtoi(string &s)
{

    int idx = 0, result = 0, sign = 1;
    // Loop for moving index from intial whitspaces to character.
    while (s[idx] == ' ')
    {
        idx++;
    }
    // Checking 1st character for +ve or -ve sign.
    if (s[idx] == '-' || s[idx] == '+')
    {
        if (s[idx++] == '-')
            sign = -1;
    }

    while (s[idx] >= '0' && s[idx] <= '9')
    {
        // Checking Underflow or overflow condition
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && s[idx] - '0' > 7))
        {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        result = 10 * result + (s[idx++] - '0');
    }

    return result * sign;
}

int main(){
    string S = "  -123";
    int ans = myAtoi(S);
    cout << ans;
}