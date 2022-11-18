/*
 * Backtrack
 * 
 * def backtrack(route, decisions)
 *     if terminal condition satisfied
 *         result.add(route)
 *         return
 * 
 *     for decision in disision list
 *         make decision
 *         backtrack(route, decision lists)
 *         withdraw decision
 */

#include <vector>
#include <climits>
#include <algorithm>
#include "cout.h"

vector<vector<int>> permute(vector<int>& nums);
vector<vector<int>> permuteBacktrack(vector<int>& nums, vector<int> used,  vector<int> result, vector<vector<int>> &results);

int main()
{
    vector<int> v = {1, 2, 3};
    coutVectorVector(permute(v));
    return 0;
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>> results;
    vector<int> result;
    vector<int> used;
    int len = nums.size();

    used.assign(len, 0);
    results = permuteBacktrack(nums, used, result, results);
    return results;
}

vector<vector<int>> permuteBacktrack(vector<int>& nums, vector<int> used,  vector<int> result, vector<vector<int>> &results)
{
    int len = nums.size();

    if(result.size() == nums.size()) results.push_back(result);

    for(int i = 0; i < len; i++)
    {
        if(used[i] == 0)
        {
            used[i] = 1;
            result.push_back(nums[i]);
            permuteBacktrack(nums, used, result, results);
            used[i] = 0;
            result.pop_back();
        }   
    }
    
    return results;
}