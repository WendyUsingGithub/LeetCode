/*
 * dict<int, int> = {(valueInNums, indexOfValue)}
 */

#include <vector>
#include <unordered_map>
#include "cout.h"
using namespace std;

vector<int> twoSum(vector<int>& nums, int target);

int main()
{
    vector<int> nums = {3, 3, 11, 15};
    int target = 6;
    coutVector(twoSum(nums, target));
    return 0;
}

vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int, int> dict;
    vector<int> sol;
    int len = nums.size();
    int index1 = -1;
    int index2 = -1;

    for(int i = 0; i < len; i++)
    {
        dict[nums[i]] = i;
    }

    for(int i = 0; i < len; i++)
    {
        if(dict.count(target - nums[i]))
        {
            index2 = dict[target - nums[i]];
            if(i != index2)
            {
                index1 = i;
                break;
            }
        }
    }

    if(index1 == -1) return sol;
    sol.push_back(index1);
    sol.push_back(index2);
    return sol;
}