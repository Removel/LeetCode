#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
/*
//使用栈：
    int majorityElement(vector<int>& nums) {
        stack <int> st;
        for(int num : nums){
            if(st.empty()||st.top()==num)st.push(num);
            else st.pop();
        }
        return st.top();
    }
//由上可以优化：
摩尔投票算法（常数空间版本）
基本思路：
1、选择第一个数作为候选众数，计数器设为 1。
2、遍历数组：
    ·如果当前数字等于候选众数，计数器加 1。
    ·如果当前数字不等于候选众数，计数器减 1。
    ·如果计数器减到 0，就更换候选众数为当前数字，计数器重置为 1。
3、遍历结束后，候选众数就是答案（题目保证一定存在多数元素）。
*/
    int majorityElement(vector<int>& nums) {
    int res = nums[0];
    int count = 1;
    for(int num : nums){
        if(num!=res&&count>1)count--;
        if(num!=res&&count==1){
            res=num;
            count=1;
        }
        if(num==res)count++;
    }
    return res;
    }
};

int main(){

}