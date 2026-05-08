#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
/*
    // 乍一看很像01背包问题啊
    // 忘了只能最多要2个了hhh
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        vector<int> dp(budget,0);
        dp[budget-1]=0;
        for(int i=0;i<costs.size();++i){
            for(int j=budget-1;j>=0;--j){
                if(j-costs[i]>=0){
                    dp[j]=max(dp[j],dp[j-costs[i]]+capacity[i]);
                }
            }
        }
        return dp.back();
    }
*/
/*
对于当前机器，前面的机器如果容量更大且成本更小，一定是更好的搭档
弹出规则保证栈顶始终是 成本最小中的容量最大 可行搭档
*/
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        // 记录对应的内容
        vector<pair<int,int>> rec;
        // 对于单台预算就超过的机器我们不要
        for(int i=0;i<costs.size();++i){
            if(costs[i]<budget){
                rec.emplace_back(costs[i],capacity[i]);
            }
        }
        // 排序
        sort(rec.begin(), rec.end()); // 按成本升序
        // 单调栈使用
        stack<pair<int,int>>st;
        st.emplace(0,0);    //增加哨兵
        int ans = 0;
        for(auto &[cost,cap]:rec){
            // 如果当前栈顶机器+当前遍历到的机器预算和>总预算，则弹出栈顶太贵的机器
            while(cost+st.top().first>=budget){
                st.pop();
            }
            // 更新ans，即为容量
            ans = max(ans,cap+st.top().second);
            // 如果当前遍历到的机器的容量>栈顶机器的容量那么我们将当前机器压栈
            if(cap>st.top().second){
                st.emplace(cost,cap);
            }
        }
        return ans;
    }
};