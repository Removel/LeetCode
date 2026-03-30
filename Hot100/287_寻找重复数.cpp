#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
/*
//最暴力的方法就是O（n*n），将所有可能的两个数字组合全部暴力循环一次，查看是否相同
    
    int findDuplicate(vector<int>& nums) {
            for(int i=0;i<nums.size();++i){
                for(int j=i+1;j<nums.size();++j){
                    if(nums[i]==nums[j])return nums[i];
                }
            }
            return -1;
    }

//显然我们不能这样做
*/
/*
//没那么暴力也没那么好的办法：hashset解决，时间复杂度、空间复杂度都为O（n）

    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> rec;
        for(int num :nums ){
            rec[num]++;
        }
        for(auto i = rec.begin();i!=rec.end() ; ++i){
            if(i->second>1)return i->first;
        }
        return -1;
    }

*/   
/*
//给我脑袋想破也想不到这道题可以看作一道链表存环的问题,详见142环形链表II
//这tm诗人？（龙图.jpg）
*/
    int findDuplicate(vector<int>& nums) { 
        int slow = 0;
        int fast = 0;
        while(true){
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(slow==fast)break;
        }
        fast = 0;
        while(true){
            fast = nums[fast];
            slow = nums[slow];
            if(fast==slow)return slow;
        }
        //正常不可能执行到这里
        return -1;
    }
};


int main(){

}