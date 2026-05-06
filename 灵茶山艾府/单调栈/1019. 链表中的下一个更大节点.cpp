#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
/*
// 一、暴力转化+单调栈法
    vector<int> nextLargerNodes(ListNode* head) {
        // 链表转为数组
        vector<int> recNums;
        ListNode* cur = head;
        while(cur){
            recNums.push_back(cur->val);
            cur = cur->next; 
        }
        // 单调栈
        vector<int> ans(recNums.size(),0);
        stack<int> st;
        for(int index = 0;index<recNums.size();++index){
            while(!st.empty()&&recNums[st.top()]<recNums[index]){
                ans[st.top()]=recNums[index];
                st.pop();
            }
            st.push(index);
        }
        // 返回
        return ans;
    }
*/
// 二、使用pair作为位置记录+单调栈法
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans;
        stack<pair<ListNode*,int>> st;    // 第一个记录链表节点，第二个记录索引
        ListNode* cur = head;
        int index = 0;
        // 单调栈遍历
        while(cur){     
            ans.push_back(0);   // 这里要先占位，否则容易越界
            while(!st.empty()&&st.top().first->val<cur->val){
                ans[st.top().second]=cur->val;
                st.pop();
            }
            st.push({cur,index});
            index++;
            cur=cur->next;
        }
        return ans;
    }
};