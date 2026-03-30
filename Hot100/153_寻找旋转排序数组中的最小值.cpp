#include <iostream> 
#include <vector> 
using namespace std; 

class Solution {
public:

//自己的写法：参考33题
//好吧这就是标准写法（*^V^*）
    int findMin(vector<int>& nums) {
        //若不存在旋转，必然有第一个元素小于最后一个元素；若存在旋转，则必然有第一个元素大于最后一个元素
        if(nums[0]<nums[nums.size()-1])return nums[0];
        int left=0,right=nums.size()-1;
        int mid=0;
        while(left<right){
            mid =(left+right)/2;
            if(nums[left]<nums[right])return nums[left];
            if(nums[mid]>=nums[left])left=mid+1;
            else if(nums[mid]<=nums[right])right=mid;
        }
        return nums[right];
    }

};



int main(){

}