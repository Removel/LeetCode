#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        //细节：先int求和，再除以k，最后返回double类型的结果
        //这样能够减少求和过程中由于double类型的计算产生的时间+误差
        int sum = 0;
        for(int i=0;i<k;++i){
            sum+=nums[i];
        }
        int res = sum;
        for(int i=k;i<nums.size();++i){
            sum-=nums[i-k];
            sum+=nums[i];
            res=max(sum,res);
        }
        return (double)res/(double)k;
    }
};