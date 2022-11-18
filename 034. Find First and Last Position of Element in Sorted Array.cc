/*
 * 當使用 searchLeft 
 * mid = (left + right) / 2
 * 當使用 searchRight 
 * mid = (left + right + 1) / 2
 * 
 * 因為當搜索範圍已經縮小到兩個相鄰的成員
 * 當使用 searchLeft 
 * 我們取 mid 需要是相鄰成員靠左邊的那個
 * 如此 right 邊界才能繼續向左靠攏
 * 
 * 當使用 searchRight 
 * 我們取 mid 需要是相鄰成員右邊的那個
 * mid = (left + right + 1) / 2
 * 如此 left 邊界才能繼續向右靠攏
 */

#include <vector>
#include "cout.h"

vector<int> searchRange(vector<int>& nums, int target);
int searchFirst(vector<int> v, int target);
int searchLast(vector<int> v, int target);

int main()
{
    vector<int> nums = {2, 2};
    coutVector(searchRange(nums, 3));
    return 0;
}

vector<int> searchRange(vector<int>& nums, int target)
{
    vector<int> result;

    if(nums.size() == 0)
    {
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }

    result.push_back(searchFirst(nums, target));
    result.push_back(searchLast(nums, target));
    return result;
}

int searchFirst(vector<int> v, int target)
{
    int middle = 0;
    int left = 0;
    int right = v.size() - 1;

    while(left < right)
    {
        middle = (left + right) / 2;
        if(target < v[middle]) right = middle - 1;
        if(v[middle] < target) left = middle + 1;
        if(v[middle] == target) right = middle;
    }

    if(right < 0) return -1;
    if(v[right] == target) return right;
    return -1;
}

int searchLast(vector<int> v, int target)
{
    int middle = 0;
    int left = 0;
    int right = v.size() - 1;

    while(left < right)
    {
        middle = (left  + right + 1) / 2;
        if(target < v[middle]) right = middle - 1;
        else if(v[middle] < target) left = middle + 1;
        else if(v[middle] == target) left = middle;
    }

    if(left >= v.size()) return -1;
    if(v[left] == target) return left;
    return -1;
}
