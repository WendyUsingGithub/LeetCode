#include <iostream>
#include "cout.h"

vector<vector<int>> generateMatrix(int n);

int main()
{
    coutVectorVector(generateMatrix(4));
    return 0;
}

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> matrix;
    vector<int> v;
    int loop = 0;
    int left = 0;
    int right = 0;
    int top = 0;
    int bottom = 0;
    int index = 1;

    v.assign(n, 0);
    matrix.assign(n, v);

    while(n > 0)
    {
        left = loop;
        top = loop;
        right = loop + n - 1;
        bottom = loop + n -1;

        for(int j = left; j <= right; j++)
        {
            matrix[top][j] = index++;
        }

        for(int i = top + 1; i <= bottom; i++)
        {
            matrix[i][right] = index++;
        }

        for(int j = right - 1; j >= left; j--)
        {
            if(n - 1 <= 0) break; /* no lines horizontal left to be processed */
            matrix[bottom][j] = index++;
        }

        for(int i = bottom - 1; i > top; i--)
        {
            if(n - 1 <= 0) break; /* no vertical lines left to be processed */
            matrix[i][left] = index++;
        }
        
        n = n - 2;
        loop++;
    }    
    return matrix;
}