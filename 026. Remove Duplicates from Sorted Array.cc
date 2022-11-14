#include <vector>
#include "cout.h"

int removeDuplicates(vector<int>& nums);

int main()
{
    vector<int> nums = {1, 1, 2};

    removeDuplicates(nums);
    coutVector(nums);
    return 0;
}

int removeDuplicates(vector<int>& nums) 
{
    int len = nums.size();
    int toFill = 0;
    int lastNum = INT_MAX;

    for(int i = 0; i < len; i++)
    {
        if(nums[i] == lastNum) continue;
        nums[toFill] = nums[i];
        lastNum = nums[i];
        toFill++;
    }
    return toFill;
}