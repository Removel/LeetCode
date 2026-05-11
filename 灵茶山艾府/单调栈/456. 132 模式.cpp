#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int size=nums.size();
        int last = INT_MIN;     //132的2
        stack<int> st;      //存132的3
        if(size<3)return false;     // 如果连三个都没有肯定是false
        /*
        为什么我们要逆序遍历？：
        ·逆序遍历保证了132中在栈内2和3的索引大小是符合规则的。
        ·如果你用单调栈从左往右，你会找到类似“3”的候选，但不知道右边是否有一个更小的“2”。
        ·逆序时，栈中存的是可能的“3”（值较大），last 是最近弹出的候选“2”（比某个 3 小），这样当左边值小于 last 时，就构成 132。
        */
        for(int i=size-1;i>=0;--i){
            /*
            为什么只要有这一行判断就能判断返回真？：
            2的出现一定会保证它是在某个nums.top()弹出来后变化的，于是此时2一定有比它更大的3，如果这是还出现比2更小的1，那么此时一定有132模式
            */
            if(nums[i]<last)return true;   
            // 更新2，更新说明一定有更大的3
            while(!st.empty()&&nums[st.top()]<nums[i]){
                last = nums[st.top()]; 
                st.pop();
            }
            // 入栈
            st.push(i);
        }
        // 到最后都没返回true说明没有
        return false;
    }
};