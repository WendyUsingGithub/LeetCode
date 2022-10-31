/*
 * = example 1 =
 * 
 * kbabc
 * 12345
 * 
 * (-1) 不是回文
 * (1)  是回文 長度1
 * (3)  是回文 長度3
 * 
 * | start\end | 0           | 1            | 2            | 3            | 4            |
 * | --------- | ----------- | ------------ | ------------ | ------------ | ------------ |
 * | 0         | (k)     (1) | (ka)    (-1) | (kab)   (-1) | (kaba)  (-1) | (kabac) ANS  |
 * | 1         | X           | (a)     (1)  | (ab)    (-1) | (aba)   (3)  | (abac)  (-1) |
 * | 2         | X           | X            | (b)     (1)  | (ba)    (-1) | (bac)   (-1) |
 * | 3         | X           | X            | X            | (a)     (1)  | (ac)    (-1) |
 * | 4         | X           | X            | X            | X            | (c)     (1)  |
 * 
 * | L     | GOAL |
 * | ----- | ---- |
 * | BL    | B    |
 * 
 * GOAL
 * 如果 BL 是回文 並且 GOAL 字串的最前和最後兩個字元相同
 * 則 GOAL 也是回文
 * 如果 BL 不是回文 但是 L 或 B 是回文
 * GOAL 依然不是回文
 * 
 * | start\end | 0           | 1            | 2            | 3            | 4            |
 * | --------- | ----------- | ------------ | ------------ | ------------ | ------------ |
 * | 0         | (k)     (1) | (ka)    (-1) | (kab)   (-1) | (kaba)  (-1) | (kabac) GOAL |
 * | 1         | X           | (a)     (1)  | (ab)    (-1) | (aba)   (3)  | (abac)  (-1) |
 * | 2         | X           | X            | (b)     (1)  | (ba)    (-1) | (bac)   (-1) |
 * | 3         | X           | X            | X            | (a)     (1)  | (ac)    (-1) |
 * | 4         | X           | X            | X            | X            | (c)     (1)  |
 * 
 * 計算方向
 * 
 * | start\end | 0    | 1    | 2    | 3    | 4    |      |
 * | --------- | ---- | ---- | ---- | ---- | ---- | ---- |
 * | 0         | -->  | -->  | -->  | -->  | GOAL |  ^   |
 * | 1         | X    | -->  | -->  | -->  | -->  |  |   |
 * | 2         | X    | X    | -->  | -->  | -->  |  |   |
 * | 3         | X    | X    | X    | -->  | -->  |  |   |
 * | 4         | X    | X    | X    | X    | -->  |  |   |
 */

#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

string longestPalindrome(string s);

int main()
{
    string s = "babad";
    cout << longestPalindrome(s) << endl;
    return 0;
}

string longestPalindrome(string s)
{
    int **DP;
    int len = 0;
    int left = 0;
    int right = 0;
    int max = 0;

    len = s.size();
    DP = new int*[len];
    for(int i = 0; i < len; i++)
    {
        DP[i] = new int[len];
        memset(DP[i], 0, len * sizeof(int));
    }

    for(int i = len - 1; i >= 0; i--)
    {
        for(int j = i + 1; j < len; j++)
        {
            if((DP[i + 1][j - 1] >= 0) && (s[i] == s[j]))
            {
                DP[i][j] = 0;
                if(j - i + 1 > max)
                {
                    left = i;
                    right = j;
                    max = right - left + 1;
                }
            }
            else
            {
                DP[i][j] = -1;
            }
        }
    }

    for(int i = 0; i < len; i++)
    {
        delete [] DP[i];
    }
    delete [] DP;
    return s.substr(left, right - left + 1);
}