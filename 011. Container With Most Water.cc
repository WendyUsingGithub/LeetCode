/*
 * 從最左和最右邊兩根柱子開始
 * 要選出兩根柱子 共有 C 柱子數量 取二 種可能性
 * 我們希望不要 C 柱子數量 取二 種可能性全部都算一次
 * 我們想找出有些柱子絕對不可能會製造出最大水容量
 * 然後挑過他不算
 * 
 * 最左和最右開始 水容量的寬度最寬
 * 兩根柱子往中間移動 都只會讓寬度變低
 * 因此唯有高度變高 才有可能使水容量增加
 * 
 * 最左和最右兩根柱子裡面比較低的那一根柱往中間移動
 * 直到下一根比他高的柱子出現 
 * 這根柱子才有可能 可以形成更大的容量
 * 是有可能 不是一定
 * 
 * 那跳過的那幾根柱子是否有可能其實是最終結果但是被我們跳過了
 * 並不可能
 * 因為被跳過的那些柱子
 * 他被跳過正是因為他的更右邊或更左邊有比他更高的柱子
 * 選他不如選這根他的更右邊或更左邊的比他更高的柱子
 * 
 * 當左和右兩根柱子等高時
 * 把兩根柱子都往中心移動
 * 若我們要找一個比現在更大的水容量
 * 包含這兩根柱子的任一根都不可能
 * 這兩根柱子的任一根向中心推進都會導致寬度變小
 * 但是推進任一根只可能導致高度變小
 * 因為即使推進之後找到更高的柱子
 * 也會受限於原本那一根的高度
 */

#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height);

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height) << endl;
    return 0;
}

int maxArea(vector<int>& height)
{
    int len = height.size();
    int left = 0;
    int right = len - 1;
    int area = 0;
    int areaMax = (right - left) * (height[left] > height[right] ? height[right] : height[left]);

    for(int i = 0; i < len; i++)
    {
        if(height[left] < height[right]) left++;
        else if(height[left] > height[right]) right--;
        else
        {
            left++;
            right--;
        }
        if(left >= right) break;
        area = (right - left) * (height[left] > height[right] ? height[right] : height[left]);
        if(area > areaMax) areaMax = area;
    }
    return areaMax;
}