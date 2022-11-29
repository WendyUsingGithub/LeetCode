/*
 * 在寫給 sort 使用的函數 comp 的時候，如果是兩個相同的物件，必須回傳 false
 * 原因不明，是 stl 的某種隱晦規定
 * 
 * = example 1 =
 * 
 * step 1 :
 * currentInterval = 0
 * mergeLeft = 1
 * mergeRight = 3
 * 
 * index  0      1      2       3 
 *        {1,3}, {2,6}, {8,10}, {15,18}
 * 
 * 
 * step 2 :
 * currentInterval = 1
 * 2 < 3 -> interval 0 和 interval 1 相交成為新的 interval
 * mergeLeft = 1
 * mergeRight = 6
 * 
 * index  0      1      2       3 
 *        {1,3}, {2,6}, {8,10}, {15,18}
 *        ------------
 * 
 * step 3 :
 * currentInterval = 2
 * 8 > 6 -> interval 0 + 1 和 interval 2 沒有相交
 * mergeLeft = 8
 * mergeRight = 10
 * result = {1, 6}
 * 
 * index  0      1      2       3 
 *        {1,3}, {2,6}, {8,10}, {15,18}
 *        ------------  ------                    
 * 
 * step 4 :
 * currentInterval = 3
 * 15 > 10 -> interval 2 和 interval 3 沒有相交
 * mergeLeft = 15
 * mergeRight = 18
 * result = {1, 6} {8, 10}
 * 
 * index  0      1      2       3 
 *        {1,3}, {2,6}, {8,10}, {15,18}
 *        ------------  ------   
 * 
 * step 5 :
 * 已經 traverse 所有 interval
 * 把目前手上正在處理的 interval 推進 result 
 * result = {1, 6} {8, 10} {15, 18}
 * 
 * index  0      1      2       3 
 *        {1,3}, {2,6}, {8,10}, {15,18}
 *        ------------  ------  -------
 */

#include <algorithm>
#include "cout.h"

vector<vector<int>> merge(vector<vector<int>>& intervals);
static bool comp(const vector<int>& vec1, const vector<int>& vec2);

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15,18}};
    coutVectorVector(merge(intervals));
    return 0;
}

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    vector<vector<int>> result;
    vector<int> v = {0, 0};
    int len = intervals.size();
    int mergeLeft = 0;
    int mergeRight = 0;
    int left = 0;
    int right = 0;
    int lastLeft = 0;

    sort(intervals.begin(), intervals.end(), comp);

    mergeLeft = intervals[0][0];
    mergeRight = intervals[0][1];

    for(int current = 1; current < len; current++)
    {
        left = intervals[current][0];
        right = intervals[current][1];
        if(left == lastLeft) continue;

        if(left <= mergeRight)
        {
            mergeRight = (mergeRight > right) ? mergeRight : right;
        }
        else
        {
            v[0] = mergeLeft;
            v[1] = mergeRight;
            result.push_back(v);
            mergeLeft = intervals[current][0];
            mergeRight = intervals[current][1];
        }
    }

    v[0] = mergeLeft;
    v[1] = mergeRight;
    result.push_back(v);
    return result;
}

static bool comp(const vector<int>& vec1, const vector<int>& vec2)
{
    if(vec1[0] != vec2[0]) return vec1[0] < vec2[0];
    if(vec1[0] == vec2[0])
    {
        if(vec1[1] != vec2[1]) return vec2[1] < vec1[1];
    }
    return false;
}
