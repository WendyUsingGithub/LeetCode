#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target);

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    cout << searchInsert(nums, 2) << endl;
    return 0;
}

int searchInsert(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    int middle = 0;

    if(target < nums[0]) return 0;
    if(target > nums[nums.size() - 1]) return nums.size();

    while(left <= right)
    {
        middle = (left + right) / 2;
        if(nums[middle] == target) return middle;
        else if(nums[middle] < target) left = middle + 1;
        else if(target < nums[middle]) right = middle - 1;
    }
    return left;
}