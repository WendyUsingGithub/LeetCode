/*
 * 因為 input 的範圍是正負十的九次方
 * 所以在計算的過程中可能會超過 int 的極限值
 * 要使用 long long
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include "cout.h"
using namespace std;

vector<vector<int>> twoSum(vector<int>& numbers, int target, int thirdIndex);
vector<vector<int>> threeSum(vector<int>& nums, long long target, int fourthIndex);
vector<vector<int>> fourSum(vector<int>& nums, int target);

int main()
{
    vector<int> nums = {0, 0, 0, 0 };
    coutVectorVector(fourSum(nums, 0));
    return 0;
}

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    vector<vector<int>> result;
    vector<vector<int>> threeSumResult;
    int fourthIndex = nums.size() - 1;
    int lastNum = 0;

    if(nums.size() < 4) return result;
    sort(nums.begin(), nums.end());

    while(1)
    {
        threeSumResult = threeSum(nums, (long long)target - nums[fourthIndex], fourthIndex);

        for(int i = 0; i < threeSumResult.size(); i++)
        {
            threeSumResult[i].push_back(nums[fourthIndex]);
            result.push_back(threeSumResult[i]);
        }

        lastNum = nums[fourthIndex];
        while(nums[fourthIndex] == lastNum)
        {
            fourthIndex--;
            if(fourthIndex <= 0) break;
        }
        if(fourthIndex <= 0) break;
    }
    return result;
}

vector<vector<int>> threeSum(vector<int>& nums, long long target, int fourthIndex)
{
    vector<vector<int>> result;
    vector<vector<int>> twoSumResult;
    int thirdIndex = fourthIndex - 1;
    int lastNum = 0;

    while(1)
    {
        if(target - nums[thirdIndex] > INT_MAX || target - nums[thirdIndex] < INT_MIN)
        {         
            lastNum = nums[thirdIndex];
            while(nums[thirdIndex] == lastNum)
            {
                thirdIndex--;
                if(thirdIndex <= 0) break;
            }
            if(thirdIndex <= 0) break;    
        }
        twoSumResult = twoSum(nums, target - nums[thirdIndex], thirdIndex);

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
    int lastLeft = INT_MAX;
    int lastRight = INT_MAX;

    if(target > INT_MAX || target < INT_MIN) return result;

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
                if(right < 0) break;
            }
            if(right < 0) break;
        }
        else if(sum < target)
        {
            lastLeft = numbers[left];
            while(lastLeft == numbers[left])
            {
                left++;
                if(left >= thirdIndex) break;
            }
            if(left >= thirdIndex) break;
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