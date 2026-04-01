#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    //原理：因为每次只能从头/尾拿，最后一定会剩下数组大小-k个连续的中间元素，
    //找到取出最大值的取法就是找到中间剩余元素和最小的取法，
    //用数组总和-窗口内最小和，从而变成滑窗找最小和的方式
    int maxScore(vector<int>& cardPoints, int k) {
        //实际上就是最经典的滑动窗口
        //但是这题很容易被错误地使用递归/动态规划/贪心做
        int sum = 0;
        //注意这里的窗口长度不是k而是总长-k长
        int windowSize = cardPoints.size()-k;
        for(int i=0;i<windowSize;++i){
            sum+=cardPoints[i];
        }
        int minWindowSum = sum;
        int windowSum = sum;
        for(int i=windowSize;i<cardPoints.size();++i){
            sum+=cardPoints[i];
            windowSum+=cardPoints[i];
            windowSum-=cardPoints[i-windowSize];
            minWindowSum = min(windowSum,minWindowSum);
        }
        return sum - minWindowSum;

    }
};