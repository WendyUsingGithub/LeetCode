#include <vector>
#include <string>
#include "cout.h"

string countAndSay(int n) ;
vector<int> countAndSayVector(vector<int> v);

int main()
{
    cout << countAndSay(1) << endl;
    return 0;
}

string countAndSay(int n) 
{
    vector<int> v = {1};
    int len = 0;
    string s;

    if(n == 1)
    {
        return string("1");
    }

    for(int i = 0; i < n - 1; i++)
    {
        v = countAndSayVector(v);
        coutVector(v);
    }

    len = v.size();
    for(int i = 0; i < len; i++)
    {
        s.append(to_string(v[i]));
    }
    return s;
}

vector<int> countAndSayVector(vector<int> v)
{
    vector<int> result;
    int len = v.size();
    int count = 1;
    int lastNum = v[0];
    int currentNum = 0;

    if(len == 1)
    {
        result.push_back(1);
        result.push_back(v[0]);
        return result;
    }

    for(int i = 1; i < len; i++)
    {
        currentNum = v[i];
        if(lastNum == currentNum)
        {
            count++;
        }
        else
        {
            result.push_back(count);
            result.push_back(lastNum);
            lastNum = currentNum;
            count = 1;
        }
        
        if(i == len - 1)
        {
            result.push_back(count);
            result.push_back(lastNum);
        }
    }

    return result;
}