#include <iostream>
#include <vector>
using namespace std;

//新最高利润=max(当前价格-当前最低价格，旧最高利润)
//新最低价格=min(当前价格，旧的最低价格)
//更新顺序不能变（吧）
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int ans=0;
    int nowLowestPrice=INT_MAX;
    for(int i=0;i<prices.size();++i){
        ans=ans<prices[i]-nowLowestPrice?prices[i]-nowLowestPrice:ans;
        nowLowestPrice = nowLowestPrice<prices[i]?nowLowestPrice:prices[i];
    } 
    return ans;
    }
};

int main(){

}