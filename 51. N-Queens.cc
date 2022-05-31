#include <iostream>
#include <vector>
#include <cstdbool>
using namespace std;

vector<vector<string>> solveNQueens(int n);
void solveNQueensBacktrack(int n, int row, vector<string>& board, vector<vector<string>>& boards, vector<int>& used);
bool isValid(vector<string> board, int row, int col, int n);
void coutBoard(vector<string> board);
void coutBoards(vector<vector<string>> boards);

int main()
{
    coutBoards(solveNQueens(4));
    return 0;
}

vector<vector<string>> solveNQueens(int n) 
{
    vector<vector<string>> boards;
    vector<string> board(n, string(n, '.'));
    vector<int> used(n, 0);
    solveNQueensBacktrack(n, 0, board, boards, used);
    return boards;
}

void solveNQueensBacktrack(int n, int row, vector<string>& board, vector<vector<string>>& boards, vector<int>& used)
{
    if(row == n)
    {
        boards.push_back(board);
        return;
    }

    for(int col = 0; col < n; col++)
    {
        if(used[col] == 0)
        {
            board[row][col] = 'Q';
            used[col] = 1;

            if(isValid(board, row, col, n))
            {
                solveNQueensBacktrack(n, row + 1, board, boards, used);
            }

            board[row][col] = '.';
            used[col] = 0;
        }
    }
    return;
}

bool isValid(vector<string> board, int row, int col, int n)
{   
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if(board[i][j] == 'Q') return false;
    }
    for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if(board[i][j] == 'Q') return false;
    }
    return true;
}

void coutBoard(vector<string> board)
{
    vector<string>::iterator it;

    for(it = board.begin(); (it + 1)!= board.end(); it++)
    {
        cout << "\"" << *it << "\"" << ",";
    }
    cout << "\"" << *it << "\"";
    return;
}

void coutBoards(vector<vector<string>> boards)
{
    vector<vector<string>>::iterator it;

    if(boards.empty()) return;

    cout << "[";
    for(it = boards.begin(); (it + 1)!= boards.end(); it++)
    {
        cout << "[";
        coutBoard(*it);
        cout << "],";
    }
    cout << "[";
    coutBoard(*it);
    cout << "]]";
    return;
}