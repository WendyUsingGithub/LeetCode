#include <iostream>
#include <vector>
using namespace std;

int fib(int n);
int fibDp(vector<int>& memo, int n);

int main()
{
    cout << fib(30) << endl;
    return 0;
}

int fib(int n) 
{
    vector<int> memo(n + 1, 0);
    return fibDp(memo, n);
}

int fibDp(vector<int>& memo, int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(memo[n] != 0) return memo[n];

    memo[n] = fibDp(memo, n - 1) + fibDp(memo, n - 2);
    return memo[n];
}