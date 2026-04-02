#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // 计算整个营业时间的因为不生气而满意的顾客
        int sum = 0;
        for(int i=0;i<customers.size();++i){
            if(!grumpy[i]){
                sum+=customers[i];
            }
        }
        // 使用滑动窗口，初始化并增加窗口内使用技巧而满意的顾客
        int add=0;
        for(int i=0;i<minutes;++i){
            if(grumpy[i]==1){
                add+=customers[i];
            }
        }
        // 移动滑动窗口，寻找能够增加的最大值
        int maxAdd = add;
        for(int i=minutes;i<customers.size();++i){
            if(grumpy[i-minutes])add-=customers[i-minutes];
            if(grumpy[i])add+=customers[i];
            maxAdd = max(maxAdd,add);
        }
        // 返回结果
        return sum + maxAdd ;
    }
};