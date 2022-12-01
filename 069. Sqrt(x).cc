/*
 * 先找出 x 是在 2^a 和 2^b 之間
 * 如此可以知道 sqrt(x) 是在 2^((b+1)/2 - 1) 和 2^((b+1)/2) 之間
 * 接下來在 2^((b+1)/2 - 1) 和 2^((b+1)/2) 之間做 binary search
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
    vector<int> twoPower(32, 0);
    int left = 0;
    int right = 31;
    long long middle = 0;
    long long middle2;

    if(x == 0) return 0;
    if(x == 1) return 1;
    twoPower[0] = 1;
    twoPower[31] = INT_MAX;
    for(int i = 1; i < 31; i++)
    {
        twoPower[i] = twoPower[i - 1] << 1;
    }

    while(left <= right)
    {
        middle = (left + right) / 2;
        if(twoPower[middle] == x)
        {
            right = middle;
            break;
        }
        else if(x < twoPower[middle]) right = middle - 1;
        else if(x > twoPower[middle]) left = middle + 1;
    }
    
    right = right > left ? right : left;
    right = (right + 1) / 2;
    left = right - 1;
    
    left = twoPower[left];
    right = twoPower[right];

    while(left <= right)
    {
        middle = (left + right) / 2;
        middle2 = middle * middle;
        if(x == middle2) return middle;
        else if(x < middle2) right = middle - 1;
        else if(x > middle2) left = middle + 1;
    }
    return right;
}