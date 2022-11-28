/*
 * = exmaple 1 = 
 * 
 * matrix = 
 * {
 * 1,  2,  3,  4
 * 5,  6,  7,  8
 * 9, 10, 11, 12
 * }
 * 
 * 每一次 loop 就是走一圈
 * 也就是第一圈是
 * 1 2 3 4 5 12 11 10 9 5
 * 第二圈是
 * 6 7
 * 
 * 每一圈又分為四個步驟
 * 上 -> 右 -> 下 -> 左
 * 第一圈 :
 * 1 2 3 4 -> 8 12 -> 11 10 9 -> 5
 * 第二圈 :
 * 6 7 -> x -> x -> x
 * 
 * 可以注意到在後兩個 for 迴圈有一個 break 的條件
 * 如果 n == 0 或 m == 0 的話
 * 代表這一輪的一圈並不是一圈
 * 而只是一個直排
 * 或一個橫排
 * 或一個點
 * 因此只需要一個 for 迴圈有一個
 * 如果兩個 for 迴圈都用上
 * 假設這剩下的一行是 1 2 3 4
 * 那走兩次會是 1 2 3 4 3 2 1
 * 這並不正確 所以要 break
 */

#include <iostream>
#include "cout.h"

vector<int> spiralOrder(vector<vector<int>>& matrix);

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    coutVector(spiralOrder(matrix));
    return 0;
}

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    vector<int> result;
    int m = matrix.size();
    int n = matrix[0].size();
    int loop = 0;
    int left = 0;
    int right = 0;
    int top = 0;
    int bottom = 0;

    while(m > 0 && n > 0)
    {
        left = loop;
        top = loop;
        right = loop + n - 1;
        bottom = loop + m -1;

        for(int j = left; j <= right; j++)
        {
            result.push_back(matrix[top][j]);
        }

        for(int i = top + 1; i <= bottom; i++)
        {
            result.push_back(matrix[i][right]);
        }

        for(int j = right - 1; j >= left; j--)
        {
            if(m - 1 <= 0) break; /* no lines horizontal left to be processed */
            result.push_back(matrix[bottom][j]);
        }

        for(int i = bottom - 1; i > top; i--)
        {
            if(n - 1 <= 0) break; /* no vertical lines left to be processed */
            result.push_back(matrix[i][left]);
        }
        
        m = m - 2;
        n = n - 2;
        loop++;
    }    
    return result;
}