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