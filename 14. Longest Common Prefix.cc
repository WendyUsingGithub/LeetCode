/*
 * 假設有字串 L1 L2 L3 ... Ln
 * L1 和 L2 先比對出一個 LCP
 * 再用這個 LCP 去和 L3 比對出新的 LCP
 * ...
 * 最後用這個 LCP 去和 Ln 對比出最終的 LCP
 */

#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

string longestCommonPrefix(vector<string>& strs);
string LCP(string s1, string s2);

int main()
{
    vector<string> v;
    string s1 = "aaa";
    string s2 = "aaa";
    string s3 = "aaaj";

    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);

    cout << longestCommonPrefix(v) << endl;
    return 0;
}

string longestCommonPrefix(vector<string>& strs)
{
    string result = strs[0];
    int strsNum = strs.size();

    for(int i = 1; i < strsNum; i++)
    {
        result = LCP(strs[i], result);
        if(result == "") return "";
    }

    return result;
}

string LCP(string s1, string s2)
{
    int len = s1.size() < s2.size() ? s1.size() : s2.size();
    
    for(int i = 0; i < len; i++)
    {
        if(s1[i] != s2[i]) return s1.substr(0, i);
    }
    return s1.substr(0, len);
}