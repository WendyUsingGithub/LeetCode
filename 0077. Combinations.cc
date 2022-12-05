#include <vector>
#include "cout.h"

vector<vector<int>> combine(int n, int k);
void combineBacktrack(int n, int k, vector<vector<int>>& results, vector<int>& result, int start);

int main()
{
    coutVectorVector(combine(4, 2));
    return 0;
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> results;
    vector<int> result;
    combineBacktrack(n, k, results, result, 0);
    return results;
}

void combineBacktrack(int n, int k, vector<vector<int>>& results, vector<int>& result, int start)
{
    if(result.size() == k)
    {
        results.push_back(result);
        return;
    }

    for(int i = start; i < n; i++)
    {
        result.push_back(i + 1); /* value is i + 1 at index i*/
        combineBacktrack(n, k, results, result, i + 1);
        result.pop_back();
    }
    return;
}