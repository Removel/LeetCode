#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
/*
    //尝试邪修
    //尝试失败，处理左指针不对
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left = 0,right = nums.size()-1;
        while(nums[left]*k<nums[right]){
            right--;
        }
        return nums.size()-(right-left+1);
    }
*/
    int minRemoval(vector<int>& nums, int k) {
        //先排序使得数组有序
        sort(nums.begin(),nums.end());
        int maxLen = 0;
        int l = 0;
        //对于每次移动右边框
        for(int r=0;r<nums.size();++r){
            //如果右边框的大小比左边框的k倍大，那么我们移动左边框直到符合条件
            while(nums[r]>(long long)nums[l]*k){
                l++;
            }
            //更新当前最大长度
            maxLen = max(maxLen,r-l+1);
        }
        //我们找到的窗口是符合的最大长度，但是题目需要的是移除元素的最小数量，所以我们需要返回数组长度-窗口长度
        return nums.size()-maxLen;
    }
};