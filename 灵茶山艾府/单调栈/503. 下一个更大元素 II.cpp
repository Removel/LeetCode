#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
/*
    问题1：我们在不是循环数组的情况下很容易完成这道题，但是现在是循环数组
    -》将循环大小变成 nums.size()*2,之后将i%nums.size()即可，在比较/保存的时候都这样记录
    问题2：stack存什么
    -》存位置索引
*/
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> ans(nums.size(),-1);
        if(nums.size()==0)return{};
        // 正向遍历
        for(int i=0;i<nums.size()*2;++i){
            // 1、栈非空 2、栈顶索引指向元素<当前元素 
            while(!st.empty()&&nums[st.top()]<nums[i%nums.size()]){
                // 如果符合那么我们记录并弹栈，不断循环直到不符合
                ans[st.top()]=nums[i%nums.size()];
                st.pop();
            }
            // 压栈，为了下一个使用
            st.push(i%nums.size());
        }
        // 返回结果
        return ans;
    }
};