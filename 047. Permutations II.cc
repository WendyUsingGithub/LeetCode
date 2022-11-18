/*
 * 不能有重複的組合出現
 * 所以在一開始先對陣列做排序
 * 讓陣列由小到大
 * 讓相同的數字聚集在一起
 * 
 * 相同的數字聚集在一起之後
 * 每一輪 (每一次進行 backtrack)
 * 只能選一次這個數字
 * 因為同一輪選出來的數字會在相同的位置
 * 如果有兩個相同的數字被選上
 * 就一定會有重複的組合
 * 
 * Backtrack
 * 
 * def backtrack(route, decisions)
 *     if terminal condition satisfied
 *         result.add(route)
 *         return
 * 
 *     for decision in disision list
 *         make decision <- 這裡不能做出重複的 decision
 *         backtrack(route, decision lists)
 *         withdraw decision
 */

#include <vector>
#include <climits>
#include <algorithm>
#include "cout.h"

vector<vector<int>> permuteUnique(vector<int>& nums);
vector<vector<int>> permuteBacktrack(vector<int>& nums, vector<int> used,  vector<int> result, vector<vector<int>> &results);

int main()
{
    vector<int> v = {1, 1, 2};
    coutVectorVector(permute(v));
    return 0;
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
    vector<vector<int>> results;
    vector<int> result;
    vector<int> used;
    int len = nums.size();

    sort(nums.begin(), nums.end());
    used.assign(len, 0);
    results = permuteBacktrack(nums, used, result, results);
    return results;
}

vector<vector<int>> permuteBacktrack(vector<int>& nums, vector<int> used,  vector<int> result, vector<vector<int>> &results)
{
    int len = nums.size();
    int lastNum = INT_MAX;

    if(result.size() == nums.size()) results.push_back(result);

    for(int i = 0; i < len; i++)
    {
        if(used[i] == 0 && lastNum != nums[i])
        {
            used[i] = 1;
            result.push_back(nums[i]);
            permuteBacktrack(nums, used, result, results);
            used[i] = 0;
            result.pop_back();
            lastNum = nums[i];
        }   
    }
    
    return results;
}