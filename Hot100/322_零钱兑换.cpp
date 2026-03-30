#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,INT_MAX-1);
        if(amount==0)return 0;
        dp[0]=0;
        for(int i=1;i<amount+1;++i){
            for(int j=0;j<coins.size();++j){
                if(i-coins[j]>=0){
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        if(dp[amount]==INT_MAX-1)return -1;
        else return dp[amount];
    }
};

int main(){

}