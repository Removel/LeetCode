#include <iostream>
#include <vector>
#include <deque>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector <int> res;
    //双端队列记录的是最大值的下标，利于判断是否还在窗口内
    deque<int> dq;
    //初始化最开始的双端队列和最开始的窗口的最大值
    for(int i=0;i<k;++i){
        //最开始的时候，如果当前元素大于dq的尾端的元素则将dq从尾端弹出元素直到dq为空或者尾端元素比当前元素要大
        while(!dq.empty()&&nums[i]>nums[dq.back()]){
            dq.pop_back();
        }
        //记录此时的最大值的下标到队列尾端当中
        dq.push_back(i);
    }
    //记录当前最大值
    res.push_back(nums[dq.front()]);
    for(int i=k;i<nums.size();++i){
        //判断队头元素是否还存在于当前的窗口当中
        //如果不存在了则将其弹出队列
        while(!dq.empty()&&i-dq.front()+1>k){
            dq.pop_front();
        }
        //同初始化时队列更新的逻辑，如果当前元素大于dq的尾端的元素则将dq从尾端弹出元素直到dq为空或者尾端元素比当前元素要大
        while(!dq.empty()&&nums[dq.back()]<nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        res.push_back(nums[dq.front()]);
    }    
    return res;
    }
};


int main(){

}