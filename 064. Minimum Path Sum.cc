/*
 * 使用 DP + memo 可以避免重複計算
 * memo[x][y] 指的是從位置 (0, 0) 到位置 (x, y) 所需要花費的最少的錢
 */

#include <vector>
#include <algorithm>
#include <climits>
#include "cout.h"

int minPathSum(vector<vector<int>>& grid);
int minPathSumDP(vector<vector<int>>& grid, vector<vector<int>>& memo, int m, int n, int x, int y);

int main()
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << minPathSum(grid) << endl;
    return 0;
}
int minPathSum(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> memo(m, vector<int> (n, -1));

    return minPathSumDP(grid, memo, m, n, m - 1, n - 1);
}

int minPathSumDP(vector<vector<int>>& grid, vector<vector<int>>& memo, int m, int n, int x, int y)
{
    if(x == 0 && y == 0) return grid[0][0];
    if(x == 0) return minPathSumDP(grid, memo, m, n, x, y - 1) + grid[x][y];
    if(y == 0) return minPathSumDP(grid, memo, m, n, x - 1, y) + grid[x][y];

    if(memo[x][y] == -1)
    {
        memo[x][y] = min(minPathSumDP(grid, memo, m, n, x - 1, y) + grid[x][y], minPathSumDP(grid, memo, m, n, x, y - 1) + grid[x][y]);
    }
    return memo[x][y];
}
