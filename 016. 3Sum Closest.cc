#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include "cout.h"
using namespace std;

int twoSum(vector<int>& numbers, int target, int thirdIndex);
int threeSumClosest(vector<int>& nums, int target);

int main()
{
    vector<int> nums = {0, 1, 2};
    cout << threeSumClosest(nums, 3) << endl;
    return 0;
}

int threeSumClosest(vector<int>& nums, int target)
{
    int twoSumResult = 0;
    int minDiff = INT_MAX;
    int thirdIndex = nums.size() - 1;
    int lastNum = 0;

    sort(nums.begin(), nums.end());

    while(1)
    {
        twoSumResult = twoSum(nums, target - nums[thirdIndex], thirdIndex);
        if(abs(twoSumResult) < abs(minDiff)) minDiff = twoSumResult;
        if(minDiff == 0) return target;
        lastNum = nums[thirdIndex];

        while(nums[thirdIndex] == lastNum)
        {
            thirdIndex--;
            if(thirdIndex <= 0) break;
        }
        if(thirdIndex <= 0) break;
    }
    return target + minDiff;
}

int twoSum(vector<int>& numbers, int target, int thirdIndex)
{
    int left = 0;
    int right = thirdIndex - 1;
    int sum = 0;
    int lastLeft = 0;
    int lastRight = 0;
    int minDiff = INT_MAX;
    
    while(1)
    {
        if(left >= right) break;
        sum = numbers[left] + numbers[right];
        if(abs(sum - target) < abs(minDiff)) minDiff = sum - target;
        if(minDiff == 0) return 0;

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
    return minDiff;
}