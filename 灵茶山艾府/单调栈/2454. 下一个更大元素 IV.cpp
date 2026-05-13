#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
/*
//两个栈，第一个栈存储未找到过第一个大的元素，用于寻找到第一个大的元素；第二个栈存储已经找到过第一个大元素的对象，用于寻找到第二个大的元素
    vector<int> secondGreaterElement(vector<int>& nums) {
        // 1、初始化
        stack<int> st1,st2;
        int size = nums.size();
        vector<int> ans(size,-1);
        // 遍历每个元素
        for(int i=0;i<size;++i){
            // 2、初始化用于存储将要移动到第二个栈全部对象的数组容器
            vector<int> tmp;
            // 3、第一次单调栈，栈是栈1
            while(!st1.empty()&&nums[st1.top()]<nums[i]){
                tmp.push_back(st1.top());    //这里要取弹出栈的元素到数组当中
                st1.pop();
            }
            // 4、当前元素入第一个栈
            st1.push(i);
            // 5、第二次单调栈，栈是栈2
            while(!st2.empty()&&nums[st2.top()]<nums[i]){
                ans[st2.top()]=nums[i];     //如果当前遍历的元素比栈顶元素还大就说明是第二大元素
                st2.pop();
            }
            // 6、将之前的暂存的元素存入到栈2当中
            for(int j=tmp.size()-1;j>=0;--j){
                st2.push(tmp[j]);
            }
        }
        // 7、返回结果
        return ans;
    }
*/   
// 使用栈优化，避免频繁开辟数组导致性能问题
    vector<int> secondGreaterElement(vector<int>& nums) {
        // 1、初始化
        stack<int> st1,st2,tmp;
        int size = nums.size();
        vector<int> ans(size,-1);
        // 遍历每个元素
        for(int i=0;i<size;++i){            
            // 2、第一次单调栈，栈是栈1
            while(!st1.empty()&&nums[st1.top()]<nums[i]){
                tmp.push(st1.top());    //这里要取弹出栈的元素到数组当中
                st1.pop();
            }
            // 3、当前元素入第一个栈
            st1.push(i);
            // 4、第二次单调栈，栈是栈2
            while(!st2.empty()&&nums[st2.top()]<nums[i]){
                ans[st2.top()]=nums[i];     //如果当前遍历的元素比栈顶元素还大就说明是第二大元素
                st2.pop();
            }
            // 5、将之前的暂存的元素存入到栈2当中
            while(!tmp.empty()){
                st2.push(tmp.top());
                tmp.pop();
            }
        }
        // 6、返回结果
        return ans;
    }
};