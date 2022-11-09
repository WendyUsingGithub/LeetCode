/*
 * stack 經典應用
 * 如果是左括號推進 stack
 * 是右括號從 stack pop 出一個元素
 * 如果 stack 是空的沒有東西可以 pop 則錯誤
 * 兩元素相比對 相同正確 不同錯誤
 * 並且整個字串跑完之後 stack 應該要是空的
 */

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s);

int main()
{
    string s = "(";
    cout << isValid(s) << endl;
    return 0;
}
bool isValid(string s)
{
    stack<char> st;
    int len = s.size();
    char cPop;
    char cNew;

    for(int i = 0; i < len; i++)
    {
        cNew = s[i];

        if(cNew == '(' || cNew == '{' || cNew == '[')
        {
            st.push(cNew);
        }
        else if(st.empty())
        {
            return false; 
        }
        else
        {
            cPop = st.top();
            st.pop();
            if((cPop == '(' && cNew != ')') || (cPop== '{' && cNew != '}') || (cPop == '[' && cNew != ']')) return false;
        }
    }

    if(!st.empty()) return false;
    return true; 
}