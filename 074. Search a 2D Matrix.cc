/*
 * 先用 binarysearch 找出 target 屬於哪一行
 * 再用 binarysearch 找出 target 屬於哪一列
 */

#include <vector>
#include "cout.h"

bool searchMatrix(vector<vector<int>>& matrix, int target);
int findRow(vector<vector<int>>& matrix, int target);
bool findCol(vector<vector<int>>& matrix, int row, int target);

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    cout << searchMatrix(matrix, 2) << endl;
    return 0;
}

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int row = 0;
    int col = 0;
    
    row = findRow(matrix, target);
    if(row == -1) return false;
    return findCol(matrix, row, target);
}

int findRow(vector<vector<int>>& matrix, int target)
{
    int left = 0;
    int right = matrix.size() - 1;
    int middle = 0;

    while(left <= right)
    {
        middle = (left + right) / 2;
        if(matrix[middle][0] == target) return middle;
        else if(matrix[middle][0] < target) left = middle + 1;
        else if(target < matrix[middle][0]) right = middle - 1;
    }
    return right;
}

bool findCol(vector<vector<int>>& matrix, int row, int target)
{
    int left = 0;
    int right = matrix[0].size() - 1;
    int middle = 0;

    while(left <= right)
    {
        middle = (left + right) / 2;
        if(matrix[row][middle] == target) return true;
        else if(matrix[row][middle] < target) left = middle + 1;
        else if(target < matrix[row][middle]) right = middle - 1;
    }
    return false;
}