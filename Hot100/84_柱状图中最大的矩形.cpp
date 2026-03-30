#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
/*
//方法一：遍历每一个数字向两边扩散，获取左右边界计算最大矩形面积：
//时间复杂度为O(n*n)，能处理小数据的情况，大数据下会超时
//（ps：哪个byd写的几千个7303的案例？）    
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = INT_MIN;
        for(int i=0;i<heights.size();++i){
            int left = i,right = i;
            //注意短路机制
            while(left>=0&&heights[left]>=heights[i]){
                left--;
            }
            while(right<=heights.size()-1&&heights[right]>=heights[i]){
                right++;
            }
            int nowArea = (right-left-1)*heights[i];
            maxArea=max(maxArea,nowArea);
        }
        return maxArea;
    }    
*/
//方法二：单调栈
    int largestRectangleArea(vector<int>& heights) {
        //left[i]表示第i个柱子左边第一个比它矮的柱子的位置，right[i]表示第i个柱子右边第一个比它矮的柱子的位置   
        //记录的都是索引，而不是高度值
        vector<int> left(heights.size(),-1);
        vector<int> right(heights.size(),heights.size());
        //单调栈，栈顶元素对应的柱子高度是单调递增的
        stack<int> monotonicStack;
        //遍历每一个柱子，获取每一个柱子左右边界的位置
        for(int i=0;i<heights.size();++i){
            //如果当前柱子比栈顶元素对应的柱子矮，则说明当前柱子是栈顶元素对应的柱子右边第一个比它矮的柱子，更新right数组，并弹出栈顶元素
            while(!monotonicStack.empty()&&heights[i]<heights[monotonicStack.top()]){
                right[monotonicStack.top()]=i;
                monotonicStack.pop();
            }
            //弹栈结束之后，单调栈只可能为空或者当前遍历到的数字比栈顶的数字要大，所以当前遍历到的数字左边第一个比它矮的柱子是栈顶元素对应的柱子，更新left数组
            if(!monotonicStack.empty()){
                left[i]=monotonicStack.top();
            }
            //将当前柱子压入栈中
            monotonicStack.push(i);
        }
        int maxArea = 0;
        //遍历每一个柱子，计算以每一个柱子为高的矩形面积，并更新最大矩形面积
        for(int i=0;i<heights.size();++i){
            //公式：以第i个柱子为高的矩形面积=柱子高度*（右边第一个比它矮的柱子位置-左边第一个比它矮的柱子位置-1）
            int nowArea = heights[i]*(right[i]-left[i]-1);
            maxArea = max(maxArea,nowArea);
        }
        //返回结果
        return maxArea;
    }


};

int main(){}