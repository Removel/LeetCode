#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
/*
一、状态定义
设 dp[i] 表示偷到第 i 间房子（从 0 开始编号）为止能得到的最大金额。
注意：dp[i] 并不要求一定要偷第 i 间房子，而是到第 i 间为止的最优解。

二、状态转移
对于第 i 间房子，只有两种选择：
1、偷第 i 间房子：那么第 i-1 间不能偷，所以最大金额 = dp[i-2] + nums[i]。
2、不偷第 i 间房子：那么最大金额 = dp[i-1]。
所以转移方程为：
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
*/

//空间复杂度为O(n)方法，更加直观
/*
    int rob(vector<int>& nums) {
       int size=nums.size();
       if(size==0)return 0;
       else if(size==1)return nums[0];
       vector<int>dp(size,0);
       dp[0]=nums[0];
       dp[1]=max(nums[0],nums[1]);
       for(int i=2;i<size;++i){
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
       }
       return dp[size-1];
    }
*/

//空间复杂度为O(1)方法，更加优化
//被大佬的做法吓哭了（qwq）
    int rob(vector<int>& nums) {
        int size=nums.size();
        if(size==0)return 0;
        else if(size==1)return nums[0];  
        int dp0=nums[0];
        int dp1=max(nums[0],nums[1]);
        for(int i=2;i<size;++i){
            int dpi=max(dp0+nums[i],dp1);
            dp0=dp1;
            dp1=dpi;
       }
       return dp1;
    }

};


int main(){}