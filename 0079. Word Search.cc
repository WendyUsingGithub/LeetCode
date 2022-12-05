/*
 * board 上的每一個位置都做一次起點
 * 看有沒有哪個位置可以走到終點
 * 
 * 一開始沒有使用 backtrack 只用單純的 dfs
 * 沒有使用 pass by reference 所以 time limit exceed
 * 並且我本來用了一個 used 陣列儲存該字元是否已經使用過
 * 但其實可以直接把使用過的字元在 board 上改成 #
 * 如此可以省下 pass 一個 used 陣列的時間
 */

#include <vector>
#include "cout.h"

bool exist(vector<vector<char>>& board, string word);
bool existXY(vector<vector<char>>& board, string word, int index, int x, int y);

int main()
{
    vector<vector<char>> board = {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    coutVectorVector(board);
    cout << exist(board, "ABCC") << endl;
    return 0;
}

bool exist(vector<vector<char>>& board, string word)
{
    int m = board.size();
    int n = board[0].size();

    for(int i = 0; i < m ;i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(existXY(board, word, 0, i, j)) return true;
        }
    }
    return false;
}

bool existXY(vector<vector<char>>& board, string word, int index, int x, int y)
{
    int m = board.size();
    int n = board[0].size();
    int val = 0;

    if(x >= m || x < 0 || y >= n || y < 0) return false;
    if(board[x][y] == '#') return false;

    if(board[x][y] != word[index]) return false;
    if(index == word.size() - 1) return true;

    val = board[x][y];
    board[x][y] = '#';

    if(existXY(board, word, index + 1, x - 1, y)) return true;
    if(existXY(board, word, index + 1, x + 1, y)) return true;
    if(existXY(board, word, index + 1, x, y - 1)) return true;
    if(existXY(board, word, index + 1, x, y + 1)) return true;

    board[x][y] = val;
    return false;
}