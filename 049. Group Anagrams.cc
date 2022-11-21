/*
 * 用 hash table 把易位構詞存在同一個 key 之下
 */

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include "cout.h"

vector<vector<string>> groupAnagrams(vector<string>& strs);

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    coutVectorVector(groupAnagrams(strs));
    return 0;
}

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<string, vector<string>> dict;
    vector<vector<string>> result;
    vector<string> anagrams;
    vector<string> v;
    string s;
    int stringNum = strs.size();
    int anagramsNum = 0;

    for(int i = 0; i < stringNum; i++)
    {
        s = strs[i];
        sort(s.begin(), s.end());
        if(!dict.count(s))
        {
            dict[s] = v;
            anagrams.push_back(s);
        }
        dict[s].push_back(strs[i]);
    }

    anagramsNum = anagrams.size();
    for(int i = 0; i < anagramsNum; i++)
    {
        result.push_back(dict[anagrams[i]]);
    }
    return result;
}