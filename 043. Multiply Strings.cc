/*
 * 手算怎麼算
 * 程式怎麼寫
 */

#include <vector>
#include <string>
#include "cout.h" 

string multiply(string num1, string num2);
string addStrings(string num1, string num2);

int main()
{
    cout << multiply("1234", "56789") << endl;
    return 0;
}

string multiply(string num1, string num2)
{
    vector<int> nums1;
    vector<int> nums2;
    vector<int> result;
    int len1 = num1.size();
    int len2 = num2.size();
    int len = len1 > len2 ? len1 : len2;
    int value = 0;
    int carryIn = 0;
    string s;

    if(num1 == "0" || num2 == "0") return "0";

    nums1.assign(len1, 0);
    nums2.assign(len2, 0);
    result.assign(len1 + len2, 0);

    for(int i = 0; i < len1; i++)
    {
        value = num1[i] - '0';
        nums1[len1 - 1 - i] = value;
    }

    for(int i = 0; i < len2; i++)
    {
        value = num2[i] - '0';
        nums2[len2 - 1 - i] = value;
    }

    for(int i = 0; i < len1; i++)
    {
        carryIn = 0;
        for(int j = 0; j < len2; j++)
        {
            value = result[i + j] + nums1[i] * nums2[j] + carryIn;
            result[i + j] = value % 10;
            carryIn = value / 10;
        }
        result[i + len2] = carryIn;
    }
    if(result.back() == 0) result.pop_back();

    len = result.size();
    for(int i = 0; i < len; i++)
    {
        s = s + to_string(result.back());
        result.pop_back();
    }
    return s;
}