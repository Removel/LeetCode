#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

/*
本质上还是零钱找钱的问题：
钱币面额-》完全平方数
要找回的面额-》给定的数字
找回的纸币数量-》结果

本道题无法使用贪心算法，贪心算法成立的前提是对于任意一个面额，
都满足对比它小的所有的数字面额，都有它的面额是它们的至少两倍，
因为此时一张能抵两张使用使得总数量更小
但是现在不满足条件比如9*2=18>16

本道题的动态规划就是在面额当中不断遍历缩小所需的最小张数

仍旧存在可以优化的空间与速度。但是意义不大，思路才是最重要的。
*/


class Solution {
public:
    int numSquares(int n) {
       //初始化
        vector<int>dp(n+1,1e9);
       dp[0]=0;
       dp[1]=1;
       //转移方程
       for(int i=2;i<n+1;++i){
        for(int j=1;j*j<=n;++j){
            if(i-j*j>=0){
                dp[i]=min(dp[i-j*j]+1,dp[i]);
            }else break;
        }
       }
       //输出结果
        return dp[n];
    }               
};

int main(){

}