/*
 * 資料結構經典題目
 * 需要注意的是
 * 因為 INT_MIN 在轉為正數時會超過 INT_MAX
 * 所以要特別用一個 if 處理
 */

#include <iostream>
#include <climits>
using namespace std;

double myPow(double x, int n);
double myPowRecursive(double x, int n);

int main()
{
    cout << myPow(2.1, 3) << endl;
    return 0;
}

double myPow(double x, int n)
{
    if(x == 1) return 1;
    if(n == 0) return 1;
    if(n == INT_MIN) return (double)1 / myPowRecursive(x, INT_MAX) / x;
    if(n > 0) return myPowRecursive(x, n);
    if(n < 0) return (double)1 / myPowRecursive(x, -n);
    return 0;
}

double myPowRecursive(double x, int n)
{
    double p = 0;

    if(n == 1) return x;
    if(n == 0) return 1;

    if(n % 2 == 0)
    {
        p = myPow(x, n / 2);
        return p * p;
    }
    else
    {
        p = myPow(x, n / 2);
        return p * p * x;
    }
}