/*
 * == example 1 ==
 *
 * 1 3 7 9 15 22 30
 * 
 * 從 1 + 20 開始
 * 如果 21 比我們的目標還要大
 * 那 20 肯定不是我們需要的數字
 * 因為即使加上最小的數字他也超過了
 * 如果 21 比我們的目標還要小
 * 那 1 肯定不是我們需要的數字
 * 因為即使加上最大的數字也還是不夠
 * 
 * 假設目標是 29
 * 那現在 1 已經出局
 * 只剩下
 * 3 7 9 15 22 30
 * 那同樣的方法再做一次
 * 3 + 30 現在比我們的目標還要大
 * 因此 30 出局了
 * 只剩下
 * 3 7 9 15 22 30
 * 重複以上步驟既能得到答案
 * 
 * step 0 - 1 3 7 9 15 22 30
 * step 1 - 1 3 7 9 15 22
 * step 2 - 3 7 9 15 22
 * step 3 - 7 9 15 22
 */

#include <iostream>
#include <vector>
#include "cout.h"
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target);

int main()
{
    vector<int> numbers = {2, 7, 11, 15};
    coutVector(twoSum(numbers, 9));
    return 0;
}

vector<int> twoSum(vector<int>& numbers, int target)
{
    vector<int> result;
    int len = numbers.size();
    int left = 0;
    int right = len - 1;
    int sum = 0;
    
    for(int i = 0; i < len; i++)
    {
        sum = numbers[left] + numbers[right];
        if(sum > target) right--;
        else if(sum < target) left++;
        else
        {
            result.push_back(left + 1);
            result.push_back(right + 1);
            return result;
        }
    }
    return result;
}