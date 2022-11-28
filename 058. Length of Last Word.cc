#include <string>
#include <iostream>
using namespace std;

int lengthOfLastWord(string s);

int main()
{
    string s = "Hello World  ";
    cout << lengthOfLastWord(s) << endl;
    return 0;
}

int lengthOfLastWord(string s)
{
    int sLen = s.size();
    int len = 0;
    int lastLen = 0;

    for(int i = 0; i < sLen; i++)
    {
        if(s[i] == ' ')
        {
            if(len != 0) lastLen = len;
            len = 0;
        }
        else
        {
            len++;
        }
    }
    return len == 0 ? lastLen : len;
}