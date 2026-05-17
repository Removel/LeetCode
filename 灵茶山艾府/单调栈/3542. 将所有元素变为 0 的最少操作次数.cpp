#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
/*
注意力惊人：
规律一：把若干相同的最小值同时变为 0，可以节省操作次数。
规律二：如果两个相同的数之间有更小的数，则他们一定不同一起被变为 0。
*/
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int ans = 0;
        for(int i=0;i<nums.size();++i){
            /*我们需要维护一个单调递增栈*/
            // 如果栈顶元素大于当前元素，那么栈顶元素不可能和后面的元素一起操作，需要弹出栈顶
            while(!st.empty()&&nums[st.top()]>nums[i]){
                st.pop();
            }
            // 如果当前元素已经为0那么不用再处理，直接跳过
            if(nums[i]==0) continue;
            // 如果当前栈为空或者栈顶元素小于当前元素，说明当前元素需要新的一轮操作覆盖。入栈并将操作次数+1
            if(st.empty()||nums[st.top()]<nums[i]){
                st.push(i);
                ans++;  
            }
        }
        return ans;
    }
};