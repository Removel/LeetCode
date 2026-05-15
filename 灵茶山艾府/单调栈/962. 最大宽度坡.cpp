#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
/*
// 使用排序的方法实现
    int maxWidthRamp(vector<int>& nums) {
        // 使用pair同时记录元素值与索引
        vector<pair<int,int>> rec;
        // 初始化pair数组
        for(int i=0;i<nums.size();++i){
            rec.push_back({nums[i],i});
        }
        // sort排序，按照值从大到小排序
        sort(rec.begin(),rec.end());
        // 初始化minIndex和ans
        int minIndex = rec[0].second;
        int ans = 0;
        // 遍历更新，此时数组当中从小到大按照数值排序，我们只需要维护找到最小的索引然后对比即可：
        for(int i=0;i<rec.size();++i){
            ans = max(ans,rec[i].second-minIndex);
            minIndex = min(minIndex,rec[i].second);
        }
        return ans;
    }
*/
// 使用单调栈的方法实现    
    int maxWidthRamp(vector<int>& nums) {
        // 初始化使用的栈对象和一些常用变量
        stack<int> st;
        int size = nums.size();
        // 手动维护一个单调递减栈，栈中的元素都是可能成为二元组中的第一个元素
        for(int i =0;i<size;++i){
            /*这里不需要弹栈，只进不出：
            如果遇到一个更大的值，它不能成为更优的起点，因为：
            1、已经存在一个更靠左且值更小的索引
            2、那个更小值的索引能形成更长的斜坡
            */
            if(st.empty()||nums[st.top()]>nums[i]){
                st.push(i);
            }
        }
        // 从右往左遍历，
        int ans = 0;
        for(int i=size-1;i>=0;i--){
            // 如果当前元素大于栈顶元素，那么这是一个二元组，由于单调栈特性我们能够尝试弹栈和栈中的下一个元素进行比较
            while(!st.empty()&&nums[i]>=nums[st.top()]){    //不能用if，因为可能多个符合条件
                ans = max(ans,i-st.top());  
                st.pop();
            }
        }
        return ans;
    }
};