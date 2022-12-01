/*
 * 假裝成猴子爬樹問題的斐波那契問題
 */

#include "cout.h"

int climbStairs(int n);

int main()
{
    cout << climbStairs(3) << endl;
    return 0;
}

int climbStairs(int n)
{
    int last = 1; /* stairWays[0] */
    int current = 1; /* stairWays[1] */
    int tmp = 0;

    for(int i = 2; i <=n ; i++)
    {
        tmp = current;
        current = current + last;
        last = tmp;
    }
    return current;
}