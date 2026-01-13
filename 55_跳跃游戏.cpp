#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
/*
    bool canJump(vector<int>& nums) {
        vector<int> canReach(nums.size(),0);
        canReach[0]=nums[0];
        for(int i=1;i<nums.size();++i){
            if(canReach[i-1]>i-1)canReach[i]=max(i+nums[i],canReach[i-1]);
        }
        return canReach[nums.size()-1]>=nums.size()-1?true:false;
    }
*/

//内存优化版本：
    bool canJump(vector<int>& nums) {
        //数组为空或者只有一个的情况处理
        if(nums.size()<=1)return true;
        //使用canReach标定当前能达到的最大的索引
        int canReach=nums[0];
        for(int i=1;i<nums.size();++i){
            //更新逻辑：当前能达到的最大索引=max（当前位置能跳到的最远的距离，旧的能达到的最远距离）
            if(canReach>=i)canReach=max(i+nums[i],canReach);
            //如果已经达到则返回真
            if(canReach>=nums.size()-1)return true;
        }
        //都结束了还没返回说明没达到，返回假
        return false;
    }
};

int main(){

}