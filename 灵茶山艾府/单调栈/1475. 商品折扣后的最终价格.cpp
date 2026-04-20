#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
/*
// 完全用错了。。。。。。
// 问题在于在处理弹出的过程中如果弹出的数量太多会导致在这些弹出的数字当中可能会丢失应当选择的数字
// 这样处理会导致被弹出的索引对应的元素不能保证是已经被处理过的
// 使用反向遍历就能解决这个问题
// 但是失败是成功之母不是吗？
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> recordLegalIndex;
        vector<int> ans;
        int nowIndex = 0 ;
        // 初始化栈
        for(int i=prices.size()-1;i>=0;--i){
            recordLegalIndex.push(i);
        }
        // 迭代
        while(nowIndex<prices.size()){
            int nowPrice = prices[nowIndex];
            int discount = 0;
            // 弹栈条件：1、前提：栈非空（保护，防止运行时错误） 2、栈顶索引对应元素大于当前price 或者 当前索引等于栈顶索引  
            // 依旧短路机制
            while(!recordLegalIndex.empty()&&(prices[recordLegalIndex.top()]>nowPrice||nowIndex==recordLegalIndex.top())){
                recordLegalIndex.pop();
            }
            if(!recordLegalIndex.empty()){
                discount = prices[recordLegalIndex.top()];
            }
            nowPrice-=discount;
            ans.push_back(nowPrice);
            nowIndex++;
       } 
        return ans;
    }
*/

/*
// 朴实无华暴力循环
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans(prices.size(),0);
        for(int i=0;i<prices.size();++i){
            int nowPrice = prices[i];
            for(int j=i+1;j<prices.size();++j){
                if(prices[i]>=prices[j]){
                    nowPrice=prices[i]-prices[j];
                    break;
                }
            }
            ans[i]=nowPrice;
        }
        return ans;
    }
*/

// 反序单调栈：
    vector<int> finalPrices(vector<int>& prices) {
        // 单调栈：保存 右边已经遍历过的价格下标
        stack<int> recordLegalIndex;
        vector<int> ans(prices.size(),0);
        int nowIndex = 0 ;
        // 反序遍历，确保当前进入栈的索引都已经处理过了
        for(int nowIndex=prices.size()-1;nowIndex>=0;--nowIndex){
            int discount = 0;
            int nowPrice = prices[nowIndex];
            // 弹栈条件：1、前提：栈非空（保护，防止运行时错误） 2、栈顶索引对应元素大于当前price
            /*
                栈不为空，并且 栈顶对应的价格 > 当前价格
                说明：这个栈顶不可能成为 当前元素 或 左边任何元素 的折扣
                因为当前元素更小，且离左边更近，故当前栈顶直接丢掉！
            */
            while(!recordLegalIndex.empty()&&prices[recordLegalIndex.top()]>nowPrice){
                recordLegalIndex.pop();
            }
            // 此时栈顶索引对应元素就是discount
            if(!recordLegalIndex.empty()){
                discount = prices[recordLegalIndex.top()];
            }
            // 更新结果
            ans[nowIndex] = nowPrice - discount;
            // 将当前已经处理完的元素的索引加入，此时栈依然保持单调递增
            recordLegalIndex.push(nowIndex);
        }
        return ans;
    }

};