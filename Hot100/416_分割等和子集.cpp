#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    //两个子集的元素和相等，又有两个子集的元素和 = 整个集合的元素和
    //于是有：任意一个子集的元素和 = 整个数组元素和的一半
    //->01背包问题--动态规划
    bool canPartition(vector<int>& nums) {
        //如果只有一个元素，那么肯定不可能将数组分为两个子集
        if(nums.size()==1)return false;
        //计算该数字的和
        int sum = 0;
        for(int num : nums){
            sum += num ;
        }
        //如果和为奇数那么肯定不可能分为两个和相等的子集
        if(sum%2!=0)return false;
        //dp[i]表示了是否存在和为索引i的子集
        vector<bool> dp(sum/2+1,false);
        //初始化
        dp[0]=true;
            for(int j=0;j<nums.size();++j){
                //如果出现了大于总和一半的数字，说明不能分
                if(nums[j]>sum/2)return false;
                //如果出现了等于总和一半的数字，说明肯定能分
                if(nums[j]==sum/2)return true;
                /*
                此处使用倒序，若是正序的情况下遍历会导致某些先前被赋值为true的dp在此轮被重复使用：
                比如可能存在情况：
                该轮当中
                原本dp[k]=true，通过赋值使得dp[k+i]=true;
                然而在遍历到dp[k+i]的时候，原来的dp[k+i]不应该为true，但是由于该错误使得dp[k+i]被误认为true，
                从而使用了dp[k+i]，认为dp[k+i +i]为true，这样必然导致错误
                也就是0-1背包-》完全背包（error！）

                方法解决：
                1、在外部nums遍历的时候使用dp_tmp记录本轮变化，使用dp来进行判断是否可以变化。本轮结束之后将dp_tmp给到dp
                -》warning：在面对较大的dp的时候会使得速度慢。
                2、如下，倒序遍历dp[]，i-nums[j]未在本轮当中遍历到，dp[i-nums[j]]一定是上一轮未被污染的结果。
                -》有效防止了数组复制带来的时间开销
                */
                for(int i=sum/2;i>=0;--i){
                    if(i-nums[j]>=0&&dp[i-nums[j]]){
                        dp[i]=true;
                    }
                } 
            }
        return dp[sum/2];
    }

};

int main(){

}