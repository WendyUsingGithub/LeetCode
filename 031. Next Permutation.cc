/*
 * 從 nums 的尾巴開始 pop
 * 被 pop 出來就加入 decisionList
 * decisionList 就是 backtracking 中的選擇
 * 直到我們找到 nums 裡的一個數字
 * 我們可以在 decisionList 裡找到一個比他大的數字
 * 用這個數字取代他
 * 但是不是比他大就好
 * 因為比他大的可能不只一個
 * 要選擇比他大的數字中最小的
 * 餘下的數字就由小到大排列加入 nums
 * 
 * = example 1 =
 * 
 * step 0
 * nums = {1, 3, 2}
 * decisionList = {}
 * 
 * step 1
 * nums[i] = 2
 * nums = {1, 3}
 * decisionList = {2}
 * 
 * step 2
 * nums[i] = 3
 * nums = {1}
 * decisionList = {2, 3}
 * 
 * step 3
 * nums[i] = 1 -> 2 和 3 都大於 1，要選 2，因為是字典排序的下一個
 * nums = {}
 * decisionList = {2, 3, 1}
 * 
 * step 4
 * nums = {2}
 * decisionList = {3, 1}
 * 
 * step 5
 * nums = {2, 1, 3}
 */

#include <vector>
#include <algorithm>
#include "cout.h"

void nextPermutation(vector<int>& nums);
bool ifDescending(vector<int> nums);
int findSmallestBigger(vector<int> nums, int a, int b);

int main()
{
    vector<int> nums = {2, 1, 2, 2, 2, 2, 2, 1};

    nextPermutation(nums);
    coutVector(nums);
    return 0;
}

void nextPermutation(vector<int>& nums)
{
    vector<int> decisionList;
    int len = nums.size();
    int max = INT_MIN;

    if(ifDescending(nums))
    {
        sort(nums.begin(), nums.end());
        return;
    }

    for(int i = len - 1; i >= 0; i--)
    {
        if(max > nums[i])
        /* start re-construct result*/
        {
            decisionList.push_back(nums[i]);
            nums[i] = findSmallestBigger(decisionList, nums[i], max);
            decisionList.erase(find(decisionList.begin(), decisionList.end(), nums[i]));
            break;
        }
        else
        /* add posible decisions into decisionList*/
        {
            decisionList.push_back(nums[i]);
            if(nums[i] > max) max = nums[i];
            nums.pop_back();
        }
    }
    sort(decisionList.begin(), decisionList.end());
    nums.insert(nums.end(), decisionList.begin(), decisionList.end());
    return;
}

bool ifDescending(vector<int> nums)
{
    int len = nums.size();

    for(int i = 1; i < len; i++)
    {
        if(nums[i] > nums[i - 1]) return false;
    }
    return true;
}

int findSmallestBigger(vector<int> nums, int a, int b)
{
    int len = nums.size();
    int min = b;

    for(int i = 0; i < len; i++)
    {
        if(nums[i] > a && nums[i] < b)
        {
            if(nums[i] < min) min = nums[i];
        }
    }
    return min;
}