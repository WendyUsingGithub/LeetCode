/*
 * vector 裡存的是路徑行經的檔案夾名稱
 * 往下一層資料夾往下走就 push 進 vector 
 * 如果遇到 .. 就把尾端的檔案夾名稱 pop 掉
 */

#include <vector>
#include <string>
#include "cout.h"

string simplifyPath(string path) ;
string fetchString(string &path);

int main()
{
    string path = "/../home//foo";    
    cout << simplifyPath(path) << endl;
    return 0;
}

string simplifyPath(string path) 
{
    vector<string> dirNames;
    string s;
    string result;

    while(1)
    {
        s = fetchString(path);
        if(s == "") break;
        else if(s == ".") ;
        else if(s == "..") {if(!dirNames.empty()) dirNames.pop_back();}
        else dirNames.push_back(s);
    }

    result.append("/");
    for(int i = 0; i < dirNames.size(); i++)
    {
        result.append(dirNames[i]);
        if(i != dirNames.size() - 1) result.append("/");
    }
    return result;
}

string fetchString(string &path)
{
    int index = 0;
    int len = 0;
    int lenSkip = 0;
    int start = 0;
    string result;

    for( ; index < path.size(); index++)
    {
        if(path[index] != '/') break;
        lenSkip++;
    }
    start = index;

    for( ; index < path.size(); index++)
    {
        if(path[index] != '/') len++;
        else break;
    }
    result = path.substr(start, len);;
    path = path.substr(start + len, path.size() - len - lenSkip);
    return result;
}