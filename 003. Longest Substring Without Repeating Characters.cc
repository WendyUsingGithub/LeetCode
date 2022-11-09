/*
 * 基本想法是使用 for 來找出以每一個字元為起始時的最大長度
 * 共有 len 個最大長度
 * 透過 shrink window 可以跳過某些一定不會是最大長度的子字串
 * 因為在 right 不動 而 left 向右移動的情況下
 * 只可能會製造出更短的子字串
 * maxlength 裡存的是以 left 字元起始的字串 其最大長度
 * 
 * Sliding Window
 * 
 * for(traverse string)
 *     expand window
 *     while(encounter duplicated charactor)
 *         shrink window
 *         update maxlength
 * 
 * = example 1 =
 * 
 * right 向右移 加入新字元 k
 * abckek (X) -> 字串長度 5
 * bckek  (X) -> 字串長度 4
 * ckek   (X) -> 字串長度 3
 * kek    (X) -> 字串長度 2
 * ek     (O) -> 字串長度 2
 */

#include <iostream>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s);

int main()
{
    string s = "au";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}

int lengthOfLongestSubstring(string s)
{
    int left = 0;
    int right = 0;
    int len = s.size();
    int alphabet[256] = {0};
    int *maxLength = new int[len];
    char c;
    int max = 0;

    if(s == "") return 0;
    for(right = 0; right < len; right++)
    {
        c = s[right];
        alphabet[c]++;

        if(alphabet[c] > 1)
        {
            maxLength[left] = right - left;
            while(s[left]!= c)
            {
                alphabet[s[left]]--;
                left++;
            }
            alphabet[s[left]]--;
            left++;
        }
    }

    maxLength[left] = right - left;
    for(int i = 0; i < len; i++)
    {
        if(maxLength[i] > max) max = maxLength[i];
    }

    delete [] maxLength;
    return max;
}