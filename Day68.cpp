// Day 68 : Implement Pow.
// Implement the function power(b, e), which calculates b raised to the power of e (i.e. be).

#include <bits/stdc++.h>
using namespace std;

double power(double b, int e)
{
    if (e == 0)
    {
        return 1.0;
    }
    if (e < 0)
    {
        return 1 / power(b, -e);
    }

    return b * power(b, e - 1);
}

int main()
{
    double b = 3.0;
    int e = 5;
    double res = power(b, e);
    cout << res;
}