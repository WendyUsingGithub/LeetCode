#include <vector>
#include "cout.h"

void rotate(vector<vector<int>>& matrix);

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    coutVectorVector(matrix);
    rotate(matrix);
    coutVectorVector(matrix);
    return 0;
}

void rotate(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    int tmp = 0;

    /* transpose */
    for(int  i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }

    /* mirror */
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n / 2; j++)
        {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = tmp;
        }
    }
    return;
}