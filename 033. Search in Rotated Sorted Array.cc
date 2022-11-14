/*
 * 觀察一個 nums 陣列 {4, 5, 6, 7, 0, 1, 2}
 * 我們可以知道被 rotate 之後的 nums 可以理解為兩個 ascending-order vector 組成
 * 要怎麼知道一個數字是屬於前面的陣列或是後面的陣列
 * 只要他比第一個 element 小
 * 就是第二個陣列
 * 比第一個 element 大
 * 就是第一個陣列
 * 透過這個判斷方法我們可以找出 pivot
 * pivot 是第二個陣列的第一個 element
 * 他的左側比他小右側比他大
 * 整個陣列只有 pivot 有這樣的特性
 * 
 * 找到 pivot 之後就可以判斷 target 是屬於第一個陣列或第二個陣列
 * 使用單純的 binary search 就可以得出答案
 */

#include <vector>
#include <iostream>
using namespace std;

int search(vector<int>& nums, int target);
bool isRotate(vector<int> nums);
int findPivot(vector<int> nums);
int binarySearch(vector<int>, int left, int right, int target);

int main()
{
    vector<int> nums = {3, 1};
    cout << search(nums, 0) << endl;
    return 0;
}

int search(vector<int>& nums, int target)
{
    int first = nums[0];
    int len = nums.size();
    int pivot = 0;

    if(isRotate(nums))
    {
        pivot = findPivot(nums);
        if(target == first) return 0;
        if(target > first) return binarySearch(nums, 0, pivot - 1, target);
        if (target < first) return binarySearch(nums, pivot, len - 1, target);
    }
    else
    {
        return binarySearch(nums, 0, len - 1, target);
    }
    return 0;
}

bool isRotate(vector<int> nums)
{
    if(*(nums.begin()) > *(nums.end() - 1)) return true;
    return false;
}

int findPivot(vector<int> nums)
{
    int len = nums.size();
    int left = 0;
    int right = len - 1;
    int middle = 0;
    int first = nums[0];

    while(1)
    {
        middle = (left + right) / 2;
        if(middle == 0) return 1;
        if(nums[middle - 1] > nums[middle]) return middle;
        else if(nums[middle] < first) right = middle - 1;
        else left = middle + 1;
    }

}

int binarySearch(vector<int> nums, int left, int right, int target)
{
    int middle = 0;

    while(left <= right)
    {
        middle = (left + right) / 2;
        if(nums[middle] == target) return middle;
        else if(target < nums[middle]) right = middle - 1;
        else left = middle + 1;
    }
    return -1;
}
