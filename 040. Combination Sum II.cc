/*
 * 題目要用某些數字組出一個目標數字
 * 看起來是 backtrack
 * 但是不能有組成相同的組合出現
 * 也不能使用重複的 element
 * 
 * = example 1 =
 * 
 * 首先要對陣列進行 sort
 * 這裡 sort 的目的不是排大小
 * 只是要讓相同的數字聚集在一起
 * 
 * candidates = {2, 3, 3, 6, 7}
 * 假如一個 result 在第一輪已經選了 2
 * 那在接下來這一輪
 * 他不能選擇 2
 * 因為 2 已經選過了
 * 不能使用重複的 element
 * 只能選擇 3 3 6 7
 * 
 * 如果這一輪他已經選過 3
 * 那這一輪 for 迴圈裡面的其他 backtrack 不能再選 3
 * 因為 3 已經被選過了
 * 如果再有人選 3
 * 即使他選的是第二個 3
 * 他現在和選了第一個 3 的人目前的組成是相同的
 * 會造成重複
 * 因此他只能選 6 7
 */

#include <vector>
#include <algorithm>
#include <climits>
#include "cout.h"

vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
void combinationSumBacktrack(vector<int>& candidates, int target, int currentIndex, vector<int> result, vector<vector<int>> &results);

int main()
{
    vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    coutVectorVector(combinationSum(nums, 8));
    return 0;
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    vector<vector<int>> results;
    vector<int> result;

    sort(candidates.begin(), candidates.end());
    combinationSumBacktrack(candidates, target, 0, result, results);
    return results;
}

void combinationSumBacktrack(vector<int>& candidates, int target, int currentIndex, vector<int> result, vector<vector<int>> &results)
{
    int decisionNum = candidates.size();
    int lastDecision = INT_MAX;

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
        if(candidates[i] != lastDecision)
        {
            result.push_back(candidates[i]);
            combinationSumBacktrack(candidates, target - candidates[i], i + 1, result, results);
            result.pop_back();
            lastDecision = candidates[i];
        }
    }
    return;
}