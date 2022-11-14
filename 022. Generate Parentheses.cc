/*
 * 是比較特別的 backtracking
 * 因為路徑的選擇是動態的
 * 
 * 左括號只能用 n 次
 * 在左括號用完的情況下
 * 不能選左括號
 * 
 * 右括號只能在 (左括號數量 - 右括號數量) 為正時可以用
 * 也就是還有左括號是打開的狀態下
 * 才能夠選擇右括號
 * 
 * def backtrack(route, decisions)
 *     if terminal condition satisfied
 *         result.add(route)
 *         return
 * 
 *     for decision in disision list
 *         make decision
 *         backtrack(route, decision lists)
 *         withdraw decision
 */

#include <iostream>
#include <vector>
#include <string>
#include "cout.h"
using namespace std;

vector<string> generateParenthesis(int n);
void generateParenthesisBacktrack(int n, int availableLeft, int availableRight, string result, vector<string> &results);

int main()
{
    int n = 3;
    coutVector(generateParenthesis(n));
    return 0;
}

vector<string> generateParenthesis(int n)
{
    vector<string> results;
    string result;

    generateParenthesisBacktrack(n, n, 0, result, results);
    return results;
}

void generateParenthesisBacktrack(int n, int availableLeft, int availableRight, string result, vector<string> &results)
{
    if(result.size() == 2 * n)
    {
        results.push_back(result);
        return;
    }

    if(availableLeft > 0)
    {
        result.append("(");
        generateParenthesisBacktrack(n, availableLeft - 1, availableRight + 1, result, results);
        result.pop_back();
    }

    if(availableRight > 0)
    {
        result.append(")");
        generateParenthesisBacktrack(n, availableLeft, availableRight - 1, result, results);
        result.pop_back();
    }
    return;
}