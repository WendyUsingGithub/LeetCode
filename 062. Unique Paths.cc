/*
 * 若長 3 寬 5
 * 目標是走到右下角
 * 代表要向下走 2 步
 * 向右走 4 步
 * 什麼時候向下或什麼時候向右不重要
 * 因為任何時候都可以自由選擇向下或向右
 * 因此 C 6 取 2 或說是 C 6 取 4 即是答案
 */

#include <iostream>
using namespace std;

int uniquePaths(int m, int n);

int main()
{
    cout << uniquePaths(5, 5) << endl;
    return 0;
}

int uniquePaths(int m, int n)
{
    int bigger = m > n ? m : n;
    int smaller = n < m ? n : m;
    int sum = 0;
    long long result = 1;

    bigger--;
    smaller--;
    sum = bigger + smaller;
    smaller = 1;

    while(sum > bigger)
    {
        result = result * sum;
        result = result / smaller;
        smaller++;
        sum--;
    }
    return result;
}