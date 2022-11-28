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
