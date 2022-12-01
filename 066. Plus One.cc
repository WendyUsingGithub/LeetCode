/*
 * plus One 不需要和大數加法一樣 traverse 整個數字
 * 因為其實只要從尾端開始找到一個不是 9 的數字
 * 並且把他往上加一就可以了
 * 如果找到了 9
 * 把 9 改成 0
 * 繼續往前尋找一個不是 9 的數字
 * 
 * = example 1 =
 * 
 * step 0:
 * 1 2 3 9 9
 * 
 * step 1:
 * 1 2 3 9 0
 * 
 * step 2:
 * 1 2 3 0 0
 * 
 * step 3:
 * 1 2 4 0 0
 */

#include <vector>
#include "cout.h"

vector<int> plusOne(vector<int>& digits);

int main()
{
    vector<int> digits = {9, 9, 9};
    coutVector(plusOne(digits));
    return 0;
}

vector<int> plusOne(vector<int>& digits)
{
    int carryIn = 1;
    int digit = 0;

    for(int i = digits.size() - 1; i >=0; i--)
    {
        if(digits[i] < 9)
        {
            digits[i]++;
            break;
        }
        else
        {
            digits[i] = 0;
        }
    }

    if(digits[0] == 0)
    {
        digits.insert(digits.begin(), 1);
    }
    return digits;
}