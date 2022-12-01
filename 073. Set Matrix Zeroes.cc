/*
 * 先用 binarysearch 找出 target 屬於哪一行
 * 再用 binarysearch 找出 target 屬於哪一列
 */

#include <vector>
#include "cout.h"

void setZeroes(vector<vector<int>>& matrix);

int main()
{
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    
    setZeroes(matrix);
    coutVectorVector(matrix);
    return 0;
}

void setZeroes(vector<vector<int>>& matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> rows(m, 0);  
    vector<int> cols(n, 0); 

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(matrix[i][j] == 0)
            {
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    } 

    for(int i = 0; i < m; i++)
    {
        if(rows[i] == 1)
        {
            for(int j = 0; j < n; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(cols[i] == 1)
        {
            for(int j = 0; j < m; j++)
            {
                matrix[j][i] = 0;
            }
        }
    }
    return;
}