/*
 * 看到 permutation 就想用 backtrack
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

vector<string> letterCombinations(string digits);
void letterCombinationsBacktrack(string digits,int index, vector<string> &buttons, string result, vector<string> &results);

int main()
{
    string digits = "23";
    coutVector(letterCombinations(digits));
    return 0;
}

vector<string> letterCombinations(string digits)
{
    string result;
    vector<string> results;
    vector<string> buttons = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    letterCombinationsBacktrack(digits, 0, buttons, result, results);
    return results;
}

void letterCombinationsBacktrack(string digits,int index, vector<string> &buttons, string result, vector<string> &results)
{
    int digit = digits[index] - '0';

    if(index == digits.size())
    {
        if(result != "") results.push_back(result);
        return;
    }
    
    for(int i = 0; i < buttons[digit].size(); i++)
    {
        result.push_back(buttons[digit][i]);
        letterCombinationsBacktrack(digits, index + 1, buttons, result, results);
        result.pop_back();
    }
    return;
}