#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
//类似的，我们不需要知道到底从头/尾删去多少，因为剩下的一定在中间形成子数组-》窗口
//我们只需要统计这部分剩下的部分元素的和在哪里有 子和 = 总和 - x
    int minOperations(vector<int>& nums, int x) {
        
        // 获得总和
        int sum = 0;
        for(int num : nums){
            sum+=num;
        }
        
        if(sum<x)return -1;     // 如果总和都比x小，说明做不到
        else if(sum==x)return nums.size();      //如果总和正好等于x那么直接返回
        // 滑动窗口变量初始化
        int l = 0;
        int remain = sum - x; //声明并计算子和
        sum  = 0 ;      // 变量复用，此时sum的意义转变为当前窗口的元素和
        int windowLen = 0;
        for(int r=0 ;r<nums.size();++r){
            sum += nums[r];
            while(sum > remain){
                sum -= nums[l];
                l++;
            }
            // 相等时比较
            if(sum == remain){
                // 因为我们答案需要最小的操作数，则窗口应当为最大
                windowLen = max(windowLen,r-l+1);
            }
        }
        // 遍历一轮过后如果窗口长度为0说明没有符合的操作，返回-1
        if(windowLen==0)return -1;
        // 返回结果
        return nums.size()-windowLen;
    }
};