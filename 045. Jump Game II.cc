/*
 * 要找最短距離
 * 因此使用 BFS
 * 把 queue 裡面的位置 pop 出來處理
 * 處理完之後把這個位置可以通往的下一個位置 push 進 queue 裡
 * 
 * 需要注意的是
 * 單純使用 BFS 會得到 time limit excced
 * 還需要維護一個陣列紀錄已經被踩過的位置
 * 因為如果有一個位置已經被踩過
 * 之後又被踩一次
 * 第二次踩到的路徑必定是相等或是更長
 * 因此如果發現踩到的位置已經被踩過
 * 那這個位置不需要處理
 * 只需要跳過就好
 */

#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int jump(vector<int>& nums);

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << jump(nums) << endl;
    return 0;
}

int jump(vector<int>& nums) 
{
    vector<int> stepOnIt;
    queue<int> q;
    int len = nums.size();
    int currentPos = 0;
    int available = 0;
    int jumps = 0;
    int qLen = 0;
    int next = 0;

    if(len == 0) return 0;
    q.push(0);
    stepOnIt.assign(len, 0);

    while(1)
    {
        qLen = q.size();
        for(int i = 0; i < qLen; i++)
        {
            currentPos = q.front();
            q.pop();

            if(currentPos == len - 1) return jumps;

            available = nums[currentPos];
            for(int j = 1; j <= available; j++)
            {
                next = currentPos + j;
                if(next < len && stepOnIt[next] == 0)
                {
                    stepOnIt[next] = 1;
                    q.push(next);
                }
            }
        }
        jumps++;
    }
    return jumps;
}