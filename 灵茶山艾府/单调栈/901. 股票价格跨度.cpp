#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class StockSpanner {
public:
    // 成员：栈和数组，栈用于求答案，数组用于记录
    stack<int> st;
    vector<int> nums;   //或许数组我们并不需要，但是我懒得优化了

    // 构造函数，初始化成员
    StockSpanner() {
       st.push(-1); 
       nums={};
    }
    
    int next(int price) {
        // 记录当前价格
        nums.push_back(price);
        // 单调栈体现
        while(st.top()!=-1&&nums[st.top()]<=price){
            st.pop();
        }
        // 用于计算并返回答案
        int preIndex = st.top();
        int nowIndex = nums.size()-1;
        // 入栈，用于下一个计算
        st.push(nowIndex);
        // 返回结果
        return nowIndex-preIndex;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
