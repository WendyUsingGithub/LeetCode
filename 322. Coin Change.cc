#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int coinChange(vector<int>& coins, int amount);
int coinChangeDp(vector<int>& coins, vector<int>& memo, int amount);

int main()
{
    vector<int> v{2, 5};
    cout << coinChange(v, 11) << endl;
    return 0;
}

int coinChange(vector<int>& coins, int amount)
{
    vector<int> memo(amount + 1, INT_MAX);
    memo[0] = 0;
    return coinChangeDp(coins, memo, amount);
}

int coinChangeDp(vector<int>& coins, vector<int>& memo, int amount) 
{
    vector<int>::iterator it;
    int min = amount + 1;
    int coinNum = 0;

    if(amount < 0) return -1;
    if(amount == 0) return 0;
    if(memo[amount] != INT_MAX) return memo[amount];

    for (it = coins.begin() ; it != coins.end(); it++)
    {
        coinNum = coinChangeDp(coins, memo, amount - *it) + 1;
        if(coinNum == 0) continue;
        min = (min < coinNum ? min : coinNum);
    }

    if(min == amount + 1) memo[amount] = -1;
    else memo[amount] = min;
    return memo[amount];
}