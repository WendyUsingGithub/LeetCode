/*
 * 把 result 初始化成比較長的字串
 * 這樣 traverse 完比較短的字串之後
 * 如果不需要做 carryIn
 * 就可以提早 return result
 */

#include <string>
#include "cout.h"

string addBinary(string a, string b);

int main()
{
    cout << addBinary("11", "1") << endl;
    return 0;
}

string addBinary(string a, string b)
{
    string result = a.size() > b.size() ? a : b;
    int aIndex = a.size() - 1;
    int bIndex = b.size() - 1;
    int index = aIndex > bIndex ? aIndex : bIndex;
    int carryIn = 0;
    int aNum = 0;
    int bNum = 0;

    while(aIndex >= 0 && bIndex >= 0)
    {
        aNum = a[aIndex] - '0';
        bNum = b[bIndex] - '0';
        result[index] = (char)((aNum + bNum + carryIn) % 2 + '0');
        carryIn = (aNum + bNum + carryIn) / 2;

        aIndex--;
        bIndex--;
        index--;
    }
    if(carryIn == 0) return result;

    while(index >= 0)
    {
        if(result[index] == '0')
        {
            result[index] = '1';
            carryIn = 0;
            break;
        }
        else
        {
            result[index] = '0';
        }
        index--;
    }

    if(carryIn == 1)
    {
        result.insert(0, "1");
    }
    return result;
}