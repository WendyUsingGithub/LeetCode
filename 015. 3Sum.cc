/*
 * 找到三個數字之合為 0 且不能有重複的 triple
 * 
 * 為了不要找到重複的 triple
 * 第一步先做排序
 * 因為我們希望找到的 triple 能夠 triple[0] < triple[1] < triple[2]
 * 這使我們讓 triple 不發生重複
 * 
 * 我們先選定第三個數字
 * 剩下的就是已排序陣列的兩數之合 (LeetCode 167)
 * 但必須注意 為了不要讓 triple 發生重複
 * 我們必須跳過數值相同的 element
 * 
 * = example 1 =
 * 
 * -2 -2 -2  2  2  2
 * 我們先選定第一個數字是最右邊的 2
 * 接著我們在括起來的陣列裡面尋找加起來是 0 的兩個數字
 * [-2 -2 -2  2  2]  2
 *   |           |   |
 *  min      middle  max
 * 
 * 由於第一個和最後一個 element 加起來就是 0
 * 因此我們已經得到一組答案
 * 但我們會發現第二個和倒數第二個 element 都重複了
 * 我們必須跳過重複的 elemment
 * 因為我們已經算過有這個 element 在這個位置 (min / middle / max) 的所有可能性
 * 再算一次只是徒然增加重複的可能性
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include "cout.h"
using namespace std;

vector<vector<int>> twoSum(vector<int>& numbers, int target, int thirdIndex);
vector<vector<int>> threeSum(vector<int>& nums);

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    coutVectorVector(threeSum(nums));
    return 0;
}

vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> result;
    vector<vector<int>> twoSumResult;
    int thirdIndex = nums.size() - 1;
    int lastNum = 0;

    sort(nums.begin(), nums.end());

    while(1)
    {
        if(thirdIndex < 0) break;
        twoSumResult = twoSum(nums, -nums[thirdIndex], thirdIndex);

        for(int i = 0; i < twoSumResult.size(); i++)
        {
            twoSumResult[i].push_back(nums[thirdIndex]);
            result.push_back(twoSumResult[i]);
        }

        lastNum = nums[thirdIndex];
        while(nums[thirdIndex] == lastNum)
        {
            thirdIndex--;
            if(thirdIndex <= 0) break;
        }
        if(thirdIndex <= 0) break;
    }
    return result;
}

vector<vector<int>> twoSum(vector<int>& numbers, int target, int thirdIndex)
{
    vector<vector<int>> result;
    vector<int> oneResult;
    int left = 0;
    int right = thirdIndex - 1;
    int sum = 0;
    int lastLeft = 0;
    int lastRight = 0;
    
    while(1)
    {
        if(left >= right) break;
        sum = numbers[left] + numbers[right];

        if(sum > target)
        {
            lastRight = numbers[right];
            while(lastRight == numbers[right])
            {
                right--;
                if(left >= right) break;
            }
            if(left >= right) break;
        }
        else if(sum < target)
        {
            lastLeft = numbers[left];
            while(lastLeft == numbers[left])
            {
                left++;
                if(left >= right) break;
            }
            if(left >= right) break;
        }
        else
        {
            oneResult.push_back(numbers[left]);
            oneResult.push_back(numbers[right]);
            result.push_back(oneResult);
            oneResult.clear();

            lastRight = numbers[right];
            while(lastRight == numbers[right])
            {
                right--;
                if(left >= right) break;
            }
            if(left >= right) break;
            
            lastLeft = numbers[left];
            while(lastLeft == numbers[left])
            {
                left++;
                if(left >= right) break;
            }
            if(left >= right) break;
        }
    }
    return result;
}