#include <vector>
#include "cout.h"

bool isValidSudoku(vector<vector<char>>& board);

int main()
{
    vector<vector<char>> v = 
    {{'5','3','.','.','7','.','.','.','.'}
    ,{'6','.','.','1','9','5','.','.','.'}
    ,{'.','9','8','.','.','.','.','6','.'}
    ,{'8','.','.','.','6','.','.','.','3'}
    ,{'4','.','.','8','.','3','.','.','1'}
    ,{'7','.','.','.','2','.','.','.','6'}
    ,{'.','6','.','.','.','.','2','8','.'}
    ,{'.','.','.','4','1','9','.','.','5'}
    ,{'.','.','.','.','8','.','.','7','9'}};

    cout << isValidSudoku(v) << endl;
    return 0;
}

bool isValidSudoku(vector<vector<char>>& board)
{
    int row_used[9][9] = {0};
    int col_used[9][9] = {0};
    int box_used[3][3][9] = {0};
    char c;
    int val;

    for(int row = 0; row < 9; row++)
    {
        for(int col = 0; col < 9; col++)
        {
            c = board[row][col];
            val = c - '1';

            if(c == '.')
            {
                continue;
            }
            else
            {
                if(row_used[row][val] == 0) row_used[row][val] = 1;
                else return false;

                if(col_used[col][val] == 0) col_used[col][val] = 1;
                else return false;

                if(box_used[row / 3][col / 3][val] == 0) box_used[row / 3][col / 3][val] = 1;
                else return false;
            }
        }
    }
    return true;
}