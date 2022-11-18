#include <climits>
#include <cmath>
#include "cout.h"

int divide(int dividend, int divisor);

int main()
{
    cout << divide(10, 3) << endl;
    return 0;
}

int divide(int dividend, int divisor)
{
    long long divisorL;
    int quotient = 0;
    int sign = 1;
    int bitwise = 0;

    if(dividend == INT_MIN && divisor == -1) return INT_MAX;
    if(divisor == 1) return dividend;

    if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) sign = -1;
    dividend = abs(dividend);
    divisor = abs(divisor);
    divisorL = divisor;

    while(1)
    {
        if((divisorL << 1) <= dividend)
        {
            divisorL =  divisorL << 1;
            bitwise++;
        }
        else break;
    }

    while(divisorL >= divisor)
    {
        dividend = dividend - divisorL;
        
        if(dividend >= 0) quotient = quotient + pow(2, bitwise);
        else dividend = dividend + divisorL;

        divisorL = divisorL >> 1;
        bitwise--;
    }
    return quotient * sign;
}