/*
 * subset 是製造 combinations 過程中的副產品
 * 製造 combinations 過程中所有長度未達標的 result 就是 subset
 */

#include <vector>
#include "cout.h"

vector<vector<int>> subsets(vector<int>& nums);
void subsetsBacktrack(vector<int>& nums, vector<vector<int>>& results, vector<int>& result, int start);

int main()
{
    vector<int> nums = {1, 2, 3};
    coutVectorVector(subsets(nums));
    return 0;
}

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> results;
    vector<int> result;
    subsetsBacktrack(nums, results, result, 0);
    return results;    
}

void subsetsBacktrack(vector<int>& nums, vector<vector<int>>& results, vector<int>& result, int start)
{
    results.push_back(result);

    for(int i = start; i < nums.size(); i++)
    {
        result.push_back(nums[i]);
        subsetsBacktrack(nums, results, result, i + 1);
        result.pop_back();
    }
    return;
}
