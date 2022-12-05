#include <vector>
#include "cout.h"

int removeDuplicates(vector<int>& nums);

int main()
{
    vector<int> nums = {1, 1, 1, 2 ,2, 3, 3};
    cout << removeDuplicates(nums) << endl;
    coutVector(nums);
    return 0;
}

int removeDuplicates(vector<int>& nums)
{
    int fillin = 2;

    for(int i = 2; i < nums.size(); i++)
    {
        if(nums[i] != nums[fillin - 1] || (nums[i] == nums[fillin - 1] && nums[fillin - 1] != nums[fillin - 2]))
        {
            nums[fillin] = nums[i];
            fillin++;
        }
    }
    return nums.size() >= 2 ? fillin : nums.size();
}