#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int count = 0;
        unordered_map<int,int> rec;
        // 使用long long防止整数溢出
        long long sum = 0;
        // 初始化
        for(int i = 0;i<k;++i){
            sum+=nums[i];
            if(!rec.count(nums[i])){
                count++; 
            }
            rec[nums[i]]++;
        }
        // 如果初始窗口满足条件，记录初始和
        long long res = 0;
        if(count>=m)res=sum;
        // 滑动窗口
        for(int i = k;i<nums.size();++i){
            // 处理新加入的元素
            // 注意：这里不能用count判断是否存在过，因为可能之前已经存在这个元素了
            if(rec[nums[i]]==0){
                count++;
            }
            rec[nums[i]]++;
            rec[nums[i-k]]--;
            if(rec[nums[i-k]]==0){
                count--;
            }
            sum+=nums[i];
            sum-=nums[i-k];
            if(count>=m){
                res = max(res,sum);
            }
        }
        return res;
    }
};