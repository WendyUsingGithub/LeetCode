/*
 * 除了 0 和 1 之外
 * 其他正數除以二都大於等於開根號取 floor
 * 所以一開始設定 right = x / 2
 * 因為 x 開根號一定 <= x / 2
 * 
 * 其餘都和 binary search 非常相似
 */

#include <vector>
#include "cout.h"

int mySqrt(int x);

int main()
{
    cout << mySqrt(1000) << endl;
    return 0;
}

int mySqrt(int x)
{
    int sqrt = x;
    int left = 0;
    int right = x / 2;
    long long middle = 0;

    if(x == 0) return 0;
    if(x == 1) return 1;

    while(left <= right)
    {
        middle = (left + right) / 2;
        if(middle * middle == x) return middle;
        if(middle * middle < x) left = middle + 1;
        if(x < middle * middle) right = middle - 1;
    }
    return right;
}