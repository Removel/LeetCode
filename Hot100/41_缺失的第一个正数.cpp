#include <iostream>
#include <vector>
using namespace std;


//核心：对于一个长度为n的数组，其结果一定在1~n+1之间
//只要将对应的数字放在对应的位置上，遍历一次后再找到对应的下标是否与当前元素符合，符合下一个，不符合下一个，当全部遍历完之后，还没返回则输出N+1即可
//这里类似于将数组看成了hash表
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();++i){
            while(nums[i]>=1&&nums[i]<=nums.size()&&nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=i+1)return i+1;
        }
        return nums.size()+1;
    }
};




int main(){

}