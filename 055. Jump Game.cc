/*
 * 如果每一步的位置都只能到達 steps 的數字
 * 就不能貪婪 因為會錯過最好的那條路
 * 
 * 但是現在每一步可以到達 1 ~ steps 的數字
 * 如果我們選擇最貪婪的選項
 * 他可以到達所有其他人可以到達的位置
 * 所以你不會錯過任何路
 * 
 * = example 1 =
 * 
 * nums = {4, 1, 12, 1, 1, 10, 1...}
 * 我們從 0 出發可以走 1 到 5 步
 * 1 -> 2
 * 2 -> 14
 * 3 -> 4
 * 4 -> 5
 * 5 -> 15
 * 6 -> 7
 * 
 * 走 5 步可以到最遠的地方 (15)
 * 所以我們選擇走 5 步
 * 我們走 5 步可以檢查 6 - 15
 * 本來就在 5 後面的比如說 6
 * 他們都無法企及 15
 * 都是 5 步可走位置的 subset
 * 
 * 至於走 1 到 4 步
 * 他再走一步可能超過 5 也可能還在 1 到 4 內
 * 他如果超過 5 了也不會超過 15
 * 如果還在 1 到 4 內 那他不是卡住就是下一步繼續往前走
 * 但的下一步即使有超過 5 也不會超過 15
 */

#include <vector>
#include <queue>
#include "cout.h"

bool canJump(vector<int>& nums);

int main()
{
    vector<int> nums = {3,2,1,0,4};
    cout << canJump(nums) << endl;
    return 0;
}

bool canJump(vector<int>& nums)
{
    int numLen = nums.size();
    int steps = 0;
    int currentPos = 0;
    int nextPos  = 0;
    int nextPosBest = 0;
    int nextnextPos = 0;
    int farthest = 0;

    if(currentPos == numLen - 1) return true;

    while(1)
    {
        currentPos = nextPosBest;
        steps = nums[currentPos];
        for(int i = 1; i <= steps; i++)
        {
            nextPos = currentPos + i;
            if(nextPos >= numLen - 1) return true;
            nextnextPos = nextPos + nums[nextPos];
            if(nextnextPos > farthest)
            {
                farthest = nextnextPos;
                nextPosBest = nextPos;
            }
        }
        if(nextPosBest == currentPos) return false;
    }
}