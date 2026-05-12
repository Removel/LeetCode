#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
/*
1、可以发现，对于每个人向右看，看到的人身高应该是严格递增的，于是我们自然而然的想到单调栈的特性。
2、在单调栈问题中，遍历方向的选择取决于你需要查看的是元素的左边还是右边的信息。
    如果看左侧就是从左往右，看右侧就是从右往左
*/
    vector<int> canSeePersonsCount(vector<int>& heights) {
        // 初始需要的变量和容器准备
        int size = heights.size();
        stack<int> st;
        vector<int> ans(size,0);
        // 单调栈遍历
        for(int i=size-1;i>=0;i--){
            int count = 0;    // 用于记录当前遍历到的对象能看到几个人
            // 这里使用单调栈手动维护一个严格递增序列
            while(!st.empty()&&heights[st.top()]<heights[i]){
                st.pop();
                count++;    // 每移除一个人说明能看到的人多了一个
            }
            
            if(st.empty()){     // 如果栈为空，说明当前人之后没有比他更高的了，于是看到的人是count
                ans[i]=count;
            }else ans[i] = count+1;     // 如果栈不为空，说明当前人之后除了上面能看到的人之外还能看到一个比他更高的人，于是看到的人数是count+1；
            st.push(i);    // 入栈，公式化流程
        }
        return ans;
    }
};