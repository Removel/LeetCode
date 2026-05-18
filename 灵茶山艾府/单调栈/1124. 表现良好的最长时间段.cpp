#include <stack>
#include <vector>
using namespace std;
class Solution {
public:

    /*
    为什么在这里不能一次遍历解决？
    回答：在一次遍历中无法保证：
        1、栈中存储的是所有可能的左边界候选
        2、并且能在 O(1) 时间内找到满足条件的最左边索引
    当你顺序遍历时，栈顶元素可能不是最小的满足条件的索引，
    但你又不能弹出它（因为后面可能还会用到）。
    */
    int longestWPI(vector<int>& hours) {
        stack<int> st;
        vector<int> diff(hours.size()+1);
        int ans = 0;
        diff[0]=0;
        // 将时间段转化为+-1数组，问题转化为找到+-1数组当中和为正数的最长的数组
        for(int i=0;i<hours.size();++i){
            int num=hours[i]>8?1:-1;
            diff[i+1]=diff[i]+num;
        }
        // 使用前缀和：diff[0]=0,diff[1]=vec[0],......
        /*
        diff[j]-diff[i]=下标i~j的和，由于题目设定，我们需要该值大于1
        对于每个j都找到尽可能小的i
        ->于是我们能够维护一个严格递减单调栈
        hours:[9,9,6,0,6,6,9]->[1,1,-1,-1,-1,-1,1]->diff:[0,1,2,1,0,-1,-2,-1]
        */
        // 构建递减栈：存储可能成为左边界的索引
        for(int i=0;i<diff.size();++i){
            if(st.empty()||diff[st.top()]>diff[i]){
                st.push(i);
            }
        }
        // 从右向左遍历，找最长的正和子数组
        for(int j=hours.size();j>=0;j--){
            while(!st.empty()&&diff[st.top()]<diff[j]){
                ans = max(ans,j-st.top());
                st.pop();
            }
        }
        return ans;

    }
};
