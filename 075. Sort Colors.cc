/*
 * 不要被題目裡面的 sort 迷惑
 * 已經知道只有 0 1 2 三種球
 * traverse 陣列一次
 * 把三種球各自的數目找出來
 * 就可以快速把每個顏色放到各自的位置了
 */

#include <vector>
#include "cout.h"

void sortColors(vector<int>& nums) ;

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    
    sortColors(nums);
    coutVector(nums);
    return 0;
}

void sortColors(vector<int>& nums) 
{
    int zero = 0;
    int one = 0;
    int two = 0;
    int index = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 0) zero++;
        else if(nums[i] == 1) one++;
        else if(nums[i] == 2) two++;
    }

    for( ; index < zero; index++)
    {
        nums[index] = 0;
    }
    for( ; index < zero + one; index++)
    {
        nums[index] = 1;
    }
    for( ; index < nums.size(); index++)
    {
        nums[index] = 2;
    }
    return;
}