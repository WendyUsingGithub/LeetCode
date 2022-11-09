#include <iostream>
#include <string>
#include <cmath>
#include <climits>
using namespace std;

int myAtoi(string s);
bool isSpace(char c);
bool isDigit(char c);
bool isSign(char c);

int main()
{
    string s = " -42";
    cout << myAtoi(s) << endl;
    return 0;
}

int myAtoi(string s)
{
    long long num = 0;
    int len = s.size();
    int index = 0;
    int sign = 1;
    char c;

    /* skip whitespace befor num */
    while(1)
    {
        c = s[index];
        if(isSpace(c)) index++;
        else break;
    }

    /* no digits were read, return 0*/
    if(!isDigit(c) && !isSign(c)) return 0;

    /* check sign */
    c = s[index];
    if(isSign(c))
    {
        if(c == '-') sign = -1;
        index++;
    }

    /* start num construction */
    while(1)
    {
        if(index > len) break;

        c = s[index];
        if(!isDigit(c)) break;
        
        num = num * 10 + (c - '0');
        if(sign == 1 && num > INT_MAX) return INT_MAX;
        if(sign == -1 && num > (long long)INT_MAX + 1) return INT_MIN;
        index++;
    }
    return sign * num;
}

bool isSpace(char c)
{
    if(c == ' ') return true;
    return false;
}

bool isDigit(char c)
{
    if(c >= '0' && c <= '9') return true;
    return false;
}

bool isSign(char c)
{
    if(c == '+' || c == '-') return true;
    return false;
}