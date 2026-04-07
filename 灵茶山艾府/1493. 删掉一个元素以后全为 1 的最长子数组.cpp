#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
/*
    int longestSubarray(vector<int>& nums) {
        int count = 0;
        int l=0,r=0;
        int zeroNum = 0;
        while(r<nums.size()){
            //尝试先加入
            if(nums[r]==0)zeroNum++;
            //如果多了那么调整左指针，直到少了为止
            while(zeroNum>1){
                if(nums[l]==0){
                    zeroNum--;
                }
                l++;
            }
            //更新长度
            count=max(count,r-l+1);
            r++;    //最后再更新r
        }
        //返回结果，-1是因为当前子串中有一个0需要减去
        return count-1;
    }
*/   
//优化版本
    int longestSubarray(vector<int>& nums) {
        int l=0;
        int zeroNum=0;
        for(int r=0;r<nums.size();++r){
            //如果是零那么计数器增加
            if(nums[r]==0)zeroNum++;
            //这里逻辑有点奇怪但是能过，更加推荐使用上面的方法更加直观一点,
            //虽然上面更慢就是不知道为什么
            if(zeroNum>1){
                if(nums[l]==0)zeroNum--;
                l++;
            }
        }
        return nums.size()-l-1;
    }

};