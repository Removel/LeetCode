#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    //动态规划？:当前元素的最大和=max（前一个元素的最大和+当前元素，当前元素）
    vector <int> dp(nums.size());
    dp[0]=nums[0];
    int maxres=dp[0];
    for(int i=1;i<nums.size();++i){
        dp[i]=max(dp[i-1]+nums[i],nums[i]);
        if(maxres<dp[i])maxres=dp[i];
    }
    return maxres;
    }
};



int main(){

}