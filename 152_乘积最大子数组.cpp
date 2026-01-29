#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //同300题，只要将最长递增子序列的条件限制到严格连续递增即可以找到最长连续非空子数组？
    //理解错了，还以为要元素连续，其实只要位置连续就可以了。。。。。。
    /*
    int maxProduct(vector<int>& nums) {
        if(nums.size()<2)return nums[0];
        int maxSize = 1;
        int tempSize = 1;
        int maxNum = -10;
        int maxNumInVec = 1;
        for(int i=1;i<nums.size();++i){
            maxNum = max(maxNum,nums[i]);
            if(nums[i]==nums[i-1]+1){
                tempSize ++;
                maxSize = max(tempSize,maxSize);
                maxNumInVec = maxSize==tempSize?nums[i]:maxNumInVec;
            }else tempSize = 1;
        }
        int ans = maxNumInVec;
        for(int i=maxNumInVec-1;i>=maxNumInVec-maxSize;--i){
            ans = ans*i;
        }
        return max(ans,maxNum);
    }
    */
   /*
   正确做法：使用两个dp维护，一个记录最大一个记录最小。
   因为最大的情况只会发生在：
   一、当前最小（负号）*当前元素（负号）
   二、当前最大（正号）*当前元素（正号）
   三、当前元素

   然而当前最小的数字需要用最小值维护，
   最小的情况只会发生在：
   一、当前最大（正号）*当前元素（负号）
   二、当前最小（负号）*当前元素（正号）
   三、当前元素

   于是有：
    max_dp = max(nums[i],max(oldMin*nums[i],oldMax*nums[i]));
    min_dp = min(nums[i],min(oldMin*nums[i],oldMax*nums[i]));
   
   注意：
   要使用另外两个变量来记录未更新前的两个最值。
   因为两者的更新不是同步进行的，不使用另外的变量的话会使得一个最值更新了之后影响另一个最值的更新 
    
   */ 
    int maxProduct(vector<int>& nums) { 
    if(nums.size()==1)return nums[0];
    int max_dp=nums[0];
    int min_dp=nums[0];
    int res = nums[0];
    for(int i=1;i<nums.size();++i){
        int oldMax = max_dp ,oldMin = min_dp;
        max_dp = max(nums[i],max(oldMin*nums[i],oldMax*nums[i]));
        min_dp = min(nums[i],min(oldMin*nums[i],oldMax*nums[i]));
        res = max(res,max_dp);
    }
    return res;
    }
};


int main(){
    
}