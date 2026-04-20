#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
/*
描述简化：
在数组 nums 中，你可以将每个元素 x 修改为 [x-k, x+k] 范围内的任意整数。
问最多能有多少个元素，经过修改后变成相同的值。

即：要求多个区间有最大交集，滑动窗口维护的就是保证该区间所有的数字对应的区间都有交集
*/
    int maximumBeauty(vector<int>& nums, int k) {
        //排序，使得滑动窗口更好的使用
        sort(nums.begin(),nums.end());
        int left = 0;
        int beauty = 0;
        for(int right = 0;right<nums.size();++right){
            //当左指针指向数字的上边界<右指针指向数字的下边界的时候移动左指针
            while(nums[left]+k<nums[right]-k){
                left++;
            }
            beauty = max(beauty,right-left+1);
        }
        return beauty;
    }
};