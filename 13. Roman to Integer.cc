#include "iostream"
#include "string"
using namespace std;

int romanToInt(string s);

int main()
{
    string s = "MCMXCIV";
    cout << romanToInt(s) << endl;
    return 0;
}

int romanToInt(string s)
{
    int len = s.size();
    int index = len - 1;
    int num = 0;

    while(1)
    {
        if(index >= 0 && s[index] == 'I')
        {
            num++;
            index--;
        }
        else
        {
            break;
        }
    }

    for(int i = index; i >= 0; i--)
    {
        if(s[i] == 'M') num = num + 1000;
        else if(s[i] == 'D') num = num + 500;
        else if(s[i] == 'C')
        {
            if(s[i + 1] == 'D' || s[i + 1] == 'M') num = num - 100;
            else num = num + 100;
        }
        else if(s[i] == 'L') num = num + 50;
        else if(s[i] == 'X')
        {
            if(s[i + 1] == 'L' || s[i + 1] == 'C') num = num - 10;
            else num = num + 10;
        }
        else if(s[i] == 'V') num = num + 5;
        else
        {
            if(s[i + 1] == 'V' || s[i + 1] == 'X') num = num - 1;
            else num = num + 1;
        }
    }
    return num;
}