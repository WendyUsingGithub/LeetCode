/*
 * 題目要用某些數字組出一個目標數字
 * 看起來是 backtrack
 * 但是他要求不能有組成相同的組合出現
 * 
 * = example 1 =
 * 
 * candidates = {2, 3, 6, 7}
 * 假如一個 result 在第一輪已經選了 3
 * 那在接下來這一輪
 * 他不能選擇 2
 * 只能選擇 3 6 7
 * 因為他如果這時候選擇了 2
 * 他目前的組成就會和第一輪選擇 2 但是第二輪選擇 3 的人相同
 * 重複就會發生
 * 也就是每一次做 backtrack 的時候
 * 你不能向前選擇已經錯過的選項
 */

#include <vector>
#include <algorithm>
#include "cout.h"

vector<vector<int>> combinationSum(vector<int>& candidates, int target);
void combinationSumBacktrack(vector<int>& candidates, int target, int currentIndex, vector<int> result, vector<vector<int>> &results);

int main()
{
    vector<int> nums = {2, 3, 6, 7};
    coutVectorVector(combinationSum(nums, 7));
    return 0;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> results;
    vector<int> result;

    combinationSumBacktrack(candidates, target, 0, result, results);
    return results;
}

void combinationSumBacktrack(vector<int>& candidates, int target, int currentIndex, vector<int> result, vector<vector<int>> &results)
{
    int decisionNum = candidates.size();

    if(target == 0)
    {
        results.push_back(result);
        return;
    }
    if(target < 0)
    {
        return;
    }

    for(int i = currentIndex; i < decisionNum; i++)
    {
        result.push_back(candidates[i]);
        combinationSumBacktrack(candidates, target - candidates[i], i, result, results);
        result.pop_back();
    }
    return;
}