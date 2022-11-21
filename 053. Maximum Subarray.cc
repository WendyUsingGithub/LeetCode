/*
 * 陣列 maxValue 代表的是
 * 如果 subarray 在結束在某個 index
 * 那獲得的最大 value 數值
 * 
 * 每一個 index 可能從兩個方向取得最大數值
 * 如果 maxValue[index - 1] 是一個負數
 * 那和他串連起來沒有任何幫助
 * 我們自己一個人就好
 * 
 * 如果 maxValue[index - 1] 是一個正數
 * 和他串聯在一起就能增加 maxValue[index] 的數值
 */

#include <vector>
#include "cout.h"

int maxSubArray(vector<int>& nums);

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums) << endl;
    return 0;
}

int maxSubArray(vector<int>& nums)
{
    vector<int> maxValue = {nums[0]};
    int len = nums.size();
    int max = INT_MIN;

    for(int i = 1; i < len; i++)
    {
        if(maxValue[i - 1] <= 0)
        {
            maxValue.push_back(nums[i]);
        }
        else
        {
            maxValue.push_back(maxValue[i - 1] + nums[i]);
        }
    }

    for(int i = 0; i < len; i++)
    {
        if(maxValue[i] > max) max = maxValue[i];
    }
    return max;
}