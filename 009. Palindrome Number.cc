#include <iostream>
using namespace std;

bool isPalindrome(int x);
using namespace std;

int main()
{
    int x = 1;
    cout << isPalindrome(x) << endl;
    return 0;
}

bool isPalindrome(int x)
{
    long long xCopy = x;
    int tmp = 0;
    long long y = 0;

    if(x < 0) return false;

    while(x != 0)
    {
        y = y * 10;
        y = y + (x % 10);
        x = x / 10;
    }

    if(xCopy == y) return true;
    else return false;
}