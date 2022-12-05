/*
 * = example 1 =
 * 
 * cycle = 2(R-1)
 * R = 5
 * 
 * 0           8         16
 * 1        7  9       15
 * 2     6     10    14
 * 3  5        11  13
 * 4           12
 * 
 * 0             2(R-1)   4(R-1)        
 * 1        2R-3 .        .
 * 2     2R-4    .     .
 * 3  2R-5       .  .
 * R-1           .
 * 
 * 
 * ? - (2R - 3) = 1
 * ? = 2R - 2
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string convert(string s, int numRows);

int main()
{
    string s = "a";
    int numRows = 3;
    cout << convert(s, numRows) << endl;
    return 0;
}

string convert(string s, int numRows)
{
    vector<string> result;
    string str = "";
    int len = s.size();
    int cycle = 2 * numRows - 2;
    int index = 0;

    if(numRows == 1) cycle = 1;
    result.assign(numRows, str);

    for(int i = 0; i < len; i++)
    {
        index = i % cycle;
        if(index < numRows)
        {
            result[index].push_back(s[i]);
        } 
        else
        {
            result[2 * numRows - 2 - index].push_back(s[i]);
        } 
    }

    for(int i = 0; i < numRows; i++)
    {
        str = str + result[i];
    }
    return str;
}