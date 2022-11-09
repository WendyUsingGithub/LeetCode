#include <iostream>
#include <string>
using namespace std; 

string intToRoman(int num);

int main()
{
    int num = 1994;
    cout << intToRoman(num) << endl;;
    return 0;
}

string intToRoman(int num)
{
    string result = "";
    int tmp = num;
    int ones = 0;
    int tens = 0;
    int hundreds = 0;
    int thousands = 0;

    ones = num % 10;
    tmp = tmp - ones;
    tens = tmp % 100;
    tmp = tmp - tens;
    hundreds = tmp % 1000;
    tmp = tmp - hundreds;
    thousands = tmp % 10000;

    /* thousand */
    for(int i = 0; i < thousands / 1000; i++)  result.push_back('M');

    /* hundred */
    if(hundreds == 900) result.append("CM");
    else if(hundreds == 400) result.append("CD");
    else
    {
        if(hundreds >= 500)
        {
            result.push_back('D');
            hundreds = hundreds - 500;
        }
        for(int i = 0; i < hundreds / 100; i++) result.push_back('C');
    }

    /* ten */
    if(tens == 90) result.append("XC");
    else if(tens == 40) result.append("XL");
    else
    {
        if(tens >= 50)
        {
            result.push_back('L');
            tens = tens - 50;
        }
        for(int i = 0; i < tens / 10; i++) result.push_back('X');
    }

    /* one */
    if(ones == 9) result.append("IX");
    else if(ones == 4) result.append("IV");
    else
    {
        if(ones >= 5)
        {
            result.push_back('V');
            ones = ones - 5;
        }
        for(int i = 0; i < ones; i++) result.push_back('I');
    }
    return result;
}