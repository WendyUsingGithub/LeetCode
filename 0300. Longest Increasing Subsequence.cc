/*
 * LIS[i] 是如果 LIS 結束在第 i 個 index
 * 也就是 index i 一定要被選入 LIS 的話
 * 所能夠得到的 LIS 長度
 * 如果 index i 恰好比他前面的所有 elelment 都還要更小
 * 那結束在 index i 的長度就會是 1
 * 這個 LIS 只有他自己
 * 
 * 假設我們已經知道前四項的 LIS 長度分別是 2 1 3 1
 * 而第五個 element 的值是 10
 * 我們找到前四項裡面比 10 小的 element 把 10 附加在 LIS 最尾巴
 * 這會使得 LIS 長度加一
 * 我們就會得到更長的 LIS
 * 
 * 因為我們不知道實際上 LIS 會終止在哪個 index
 * 所以得到 LIS 陣列之後
 * 還要去 traverse 他得到最大的 LIS 長度
 */

#include <vector>
#include "cout.h"

int lengthOfLIS(vector<int>& nums);

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(nums) << endl;
    return 0;
}

int lengthOfLIS(vector<int>& nums)
{
    vector<int> LIS(nums.size(), 1);
    int lis = 0;
    int max = 1;

    for(int i = 1; i < nums.size(); i++)
    {
        for(int j = 0; j < i; j++)
        {
            lis = 1;
            if(nums[j] < nums[i])
            {
                if(LIS[j] + 1 > LIS[i]) LIS[i] = LIS[j] + 1;
            }
        }
    }

    for(int i = 0; i < nums.size(); i++)
    {
        if(LIS[i] > max) max = LIS[i];
    }
    return max;
}