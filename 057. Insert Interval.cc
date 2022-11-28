/*
 * = example 1 =
 * 
 * index  0      1      2       3       4
 *        {1,2}, {3,5}, {6,7}, {8,10}, {12,16}
 * 
 * step 1 :
 * currentInterval = 0
 * result : {1, 2}
 * 
 * index  0      1      2       3       4
 *        {1,2}, {3,5}, {6,7}, {8,10}, {12,16}
 *        result
 * 
 * step 2 :
 * currentInterval = 1
 * result : {1, 2}
 * newInterval[LEFT] = 4
 * 
 * index  0      1      2       3       4
 *        {1,2}, {3,5}, {6,7}, {8,10}, {12,16}
 *        result |----
 * 
 * step 3 :
 * currentInterval = 2
 * result : {1, 2}
 * newInterval[LEFT] = 3
 * 
 * index  0      1      2       3       4
 *        {1,2}, {3,5}, {6,7}, {8,10}, {12,16}
 *        result |-----------
 * 
 * step 4 :
 * currentInterval = 3
 * result : {1, 2}
 * newInterval[LEFT] = 3
 * 
 * index  0      1      2       3       4
 *        {1,2}, {3,5}, {6,7}, {8,10}, {12,16}
 *        result |-------------------
 * 
 * step 5 :
 * currentInterval = 4
 * result : {1, 2} {3, 10}
 * newInterval[LEFT] = 3
 * newInterval[RIGHT] = 10
 * 
 * index  0      1      2       3       4
 *        {1,2}, {3,5}, {6,7}, {8,10}, {12,16}
 *        result |-------------------|
 * 
 * step 5 :
 * currentInterval = 4
 * result : {1, 2} {3, 10} {12, 16}
 * newInterval[LEFT] = 3
 * newInterval[RIGHT] = 10
 * 
 * index  0      1      2       3       4
 *        {1,2}, {3,5}, {6,7}, {8,10}, {12,16}
 *        result |-------------------| result
 */

#include <vector>
#include "cout.h"

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval);
int binarySearch(vector<vector<int>> intervals, int target);

int main()
{
    vector<vector<int>> intervals = {{1,2}, {3,5}, {6,7}, {8,10}, {12,16}};
    vector<int> newInterval = {4, 8};

    coutVectorVector(insert(intervals, newInterval));
    return 0;
}

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
{
    vector<vector<int>> result;
    vector<int> newMergeInterval = {0, 0};
    int len = intervals.size();
    int currentInterval = 0;
    int mergeLeft = 0;
    int mergeRight = 0;

    for(currentInterval = 0; currentInterval < len; currentInterval++)
    {
        if(intervals[currentInterval][1] < newInterval[0])
        {
            result.push_back(intervals[currentInterval]);
        }
        else break;
    }

    mergeLeft = (currentInterval < len && intervals[currentInterval][0] < newInterval[0]) ? intervals[currentInterval][0] : newInterval[0];

    for( ; currentInterval < len; currentInterval++)
    {
        if(intervals[currentInterval][0] > newInterval[1]) break;
    }

    mergeRight = (currentInterval - 1 >= 0 && intervals[currentInterval - 1][1] > newInterval[1]) ? intervals[currentInterval - 1][1] : newInterval[1];

    newMergeInterval[0] = mergeLeft;
    newMergeInterval[1] = mergeRight;
    result.push_back(newMergeInterval);

    for( ; currentInterval < len; currentInterval++)
    {
        result.push_back(intervals[currentInterval]);
    }
    return result;
}