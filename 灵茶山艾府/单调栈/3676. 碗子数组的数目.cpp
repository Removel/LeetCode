#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
// 时空复杂度都是O(n)的写法
    long long bowlSubarrays(vector<int>& nums) {
        long long ans = 0;
        stack<int> st;
        for(int i=0;i<nums.size();++i){
            // 体现左低右高
            while(!st.empty()&&nums[st.top()]<nums[i]){
                if(i-st.top()+1>=3)ans++;
                st.pop();
            }
            // 体现左高右低
            if(!st.empty()&&i-st.top()+1>=3){
               ans++;   
            }
            st.push(i);
        }
        return ans;
    }

// 空间复杂度还能下降到O(1)，之后再说吧~    
};