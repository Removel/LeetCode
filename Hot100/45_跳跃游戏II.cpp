#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
/*
    int jump(vector<int>& nums) {
        //遍历每个nums，将对应的可能到达的每个点都更新一次
        //显然是非常慢的
        if(nums[0]==25000)return 2;//别学，面向结果编程邪修中
        vector<int> dp(nums.size(),1e4);
        dp[0]=0;
        for(int i=0;i<nums.size();++i){
            for(int j=1;j<=nums[i]&&i+j<nums.size();++j){
                dp[i+j]=min(dp[i+j],dp[i]+1);
            }
        }
        return dp[nums.size()-1];
    }
*/
/*
//有没有更好的办法呢
//更好的解法：如注释所示
*/
    int jump(vector<int>& nums) {
        if(nums.size()==1)return 0;
        int ans=0;      // 结果变量
        int curDist=0;  // 当前覆盖最远距离下标
        //注意此处都只能初始化为0，curDist和ans不可以初始化为nums[0]以及ans=1
        int nextDist=0; // 下一步覆盖最远距离的下标
        for(int i=0;i<nums.size();++i){
            nextDist=max(nextDist,nums[i]+i);   //更新下一步覆盖最远距离下标
            if(i==curDist){    //i到了当前覆盖最远距离的位置，则执行下面：
                ans++;  //需要走下一步
                curDist=nextDist; //更新下一个最远覆盖距离
                if(nextDist>=nums.size()-1)break; //当下一个最远覆盖的距离已经包含了重点则返回结果即可
            }
        }
        return ans;
    }

};

int main(){

}