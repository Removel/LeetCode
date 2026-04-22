#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
/*
//暴力方法：hash查找到nums2中的元素位置，再从该位置向后查找
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> rec;
        // 题目明确说明所有整数互不相同，故不存在hash冲突问题
        for(int i=0;i<nums2.size();++i){
            rec[nums2[i]]=i;
        }
        // 准备结果数组
        vector<int> ans(nums1.size(),-1);
        // 第一层for遍历nums1
        for(int i=0;i<nums1.size();++i){
            int loc = rec[nums1[i]];
            // 第二层for遍历从nums1当前元素开始之后nums2
            for(int j=loc;j<nums2.size();++j){
                // 如果符合那么更新并进入到下一个nums1元素
                if(nums1[i]<nums2[j]){
                    ans[i]=nums2[j];
                    break;
                }
            }
        }
        // 返回结果
        return ans;
    }
*/

// 来都来了，就不要用暴力了
// 单调栈写法：
/*
        注意到nums1数组仅仅起到查询的作用，于是乎我们并不需要知道nums1如何。
        我们只需要对nums2处理，知道nums2每个元素的下一个最大值是多少就可以-》单调栈
        查询的时候用hashmap查询即可 -》哈希表
*/
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        // 准备要用的容器
        unordered_map<int,int>rec;  // 映射原nums2的数字与位置，key:nums2[i] ,val:index
        stack<int> st;  // 单调栈
        vector<int> resNums2(nums2.size(),-1);  //用于存储单调栈处理过后的nums2的各个位置上的下一个最大元素
        // 反向遍历数组，保证当前遍历到的元素之后的元素已经确定过
        for(int i=nums2.size()-1;i>=0;--i){
            int nowNum = nums2[i];
            rec[nowNum]=i;  //这里记录原nums2的数字与位置
            //  如果当前栈为空或者栈顶元素大于当前元素，那么弹出
            while(!st.empty()&&st.top()<nowNum){
                st.pop();
            }
            //  如果栈不为空那么处理后的结果为栈顶元素，否则处理后的结果为-1（数组初始化时已经设定好了）
            if(!st.empty()){
                resNums2[i]=st.top();
            }
            //  将当前原元素入栈为之后元素备用
            st.push(nums2[i]);
        }
        // 遍历查询
        vector<int> ans(nums1.size(),-1);
        for(int i=0;i<nums1.size();++i){
            ans[i]=resNums2[rec[nums1[i]]];
        }
        return ans;
    }
};