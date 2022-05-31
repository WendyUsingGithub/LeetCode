#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> permute(vector<int>& nums);
void permuteBacktrack(vector<int> nums, vector<int>& permutation, vector<vector<int>>& permutations, vector<int>& used);
void coutVector(vector<int> v);

int main()
{
    vector<vector<int>> permutations;
    vector<int> nums{1, 2, 3};
    vector<vector<int>>::iterator it;

    permutations = permute(nums);
    for(it = permutations.begin(); it != permutations.end(); it++)
    {
        coutVector(*it);
    }
    return 0;
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>> permutations;
    vector<int> permutation;
    vector<int> used(nums.size(), 0);

    permuteBacktrack(nums, permutation, permutations, used);
    return permutations;
}

void permuteBacktrack(vector<int> nums, vector<int>& permutation, vector<vector<int>>& permutations, vector<int>& used) 
{
    vector<int>::iterator it;
    int index = 0;

    if(permutation.size() == nums.size())
    {
        permutations.push_back(permutation);
        return;
    }

    for(it = nums.begin(); it != nums.end(); it++)
    {
        index = distance(nums.begin(), it);
        if(used[index] == 0)
        {
            permutation.push_back(*it);
            used[index] = 1;
            permuteBacktrack(nums, permutation, permutations, used);
            permutation.pop_back();
            used[index] = 0;
        }
    }
    return;
}

void coutVector(vector<int> v)
{
    vector<int>::iterator it;

    for(it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return;
}