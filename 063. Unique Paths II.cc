/*
 * 如果只用單純的 recursive 會超時
 * 
 * 使用 DP + memo 可以避免重複計算
 * memo[x][y] 指的是從位置 (0, 0) 到位置 (x, y) 所需要花費的最少的錢
 * 你可能有多種不同路徑可以從 (m-1, n-1) 到達 (x, y)
 * 但只要第一次算出 memo[x][y]
 * 之後就知道，到這個位置之後有幾種方法可以到 (0, 0)
 * 
 * 假設有 a 種方法從 (m-1, n-1) 到達 (x, y)
 * 有 b 種方法可以從 (0, 0) 到 (x, y)
 * 總共有 a * b 種方法可以從 (0, 0) 到 (m-1, n-1)
 * 如果有用 memo 只要做 a + 1 個計算
 * 單純用 recursive 要做 a * b 個計算
 */

#include <vector>
#include "cout.h"
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);
int uniquePathsWithObstaclesDP(vector<vector<int>>& grid, vector<vector<int>>& memo, int m, int n, int x, int y);

int main()
{
    vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << uniquePathsWithObstacles(grid) << endl;
    return 0;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> memo(m, vector<int> (n, -1));

    if(obstacleGrid[0][0] == 1) return 0;
    return uniquePathsWithObstaclesDP(obstacleGrid, memo, m, n, m - 1, n - 1);
}

int uniquePathsWithObstaclesDP(vector<vector<int>>& grid, vector<vector<int>>& memo, int m, int n, int x, int y)
{
    if(x < 0 || x >= m) return 0;
    if(y < 0 || y >= n) return 0;
    if(grid[x][y] == 1) return 0;
    if(x == 0 && y == 0) return 1;

    if(memo[x][y] == -1)
    {
        memo[x][y] = uniquePathsWithObstaclesDP(grid, memo, m, n, x - 1, y) + uniquePathsWithObstaclesDP(grid, memo, m, n, x, y - 1);
    }
    return memo[x][y];
}