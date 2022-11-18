/*
 * = example 1 =
 * 
 * 100 / 3 = 33
 * 
 * 先找出 3 * 2 ^ 5 = 96
 * bitwise 是 5
 * 表示 3 * 2 ^ 5 = 96
 * 是小於 100 的最大的 3 和 2 的指數的乘積
 * 使用 2 的指數是為了使用 bitwise operator
 * 
 * step 1 :
 * 100 - 96 = 4
 * quotient = 2 ^ 5 = 32
 * 
 * step 2 :
 * 4 - 3 = 1
 * quotient = 2 ^ 5 + 2 ^ 0 = 33
 * 
 * 需要注意的是
 * 如果使用
 * 3 + 3 = 6
 * 6 + 6 = 12
 * 12 + 12 = 24
 * 24 + 24 = 48
 * 48 + 48 = 96
 * 加法的方式來進行尋找 3 和 2 的指數的乘積
 * 並且用列儲存數值
 * 會導致得到 memory exceed limit
 * 所以必須使用 bitwise operator
 */

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