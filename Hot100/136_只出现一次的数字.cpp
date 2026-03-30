#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    /*太tm骚了：数电神力发力了
        1、异或操作满足交换律和结合律
        2、一个数字与自己异或的结果为0，即a^a=0
        3、0与任何数字异或等于这个数字，即0^a=a
      于是有：只要将数组内所有元素异或一遍，最后的结果就是只出现一次的数字
    （ps：何异位？）
    */
    int ans=0;
    for(int i=0;i<nums.size();++i){
        ans=ans^nums[i];
    }
    return ans;
    }
};


int main(){

}