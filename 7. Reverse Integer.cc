#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int reverse(int x);

int main()
{
    int x = 1534236469;
    cout << reverse(x) << endl;
    return 0;
}

int reverse(int x)
{
    int digit = 0;
    int sign = 0;
    long long num = 0;

    sign = (x < 0) ? -1 : 1;
    if(x == INT_MIN) return 0;
    x = sign * x;

    while(x != 0)
    {
        digit = x % 10;
        num = num * 10 + digit;
        x = x / 10;
    }

    num = sign * num;
    if(num > INT_MAX || num < INT_MIN) return 0;
    return (int)num;
}