#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    //暴力算法：遍历一遍找到0就把它删除再在数组后面加0；
    //问题：速度太慢
        /*
       int count=0;
       for(int i=0;i<nums.size();++i){
        if(nums[count]==0){
            nums.erase(nums.begin()+count);
            nums.push_back(0);
            count--;
        }
        count++;
       }
       */
    //双指针算法：ptr1记录当前需要交换的位置，ptr2记录当前遍历的位置
    //如果ptr2对应元素的指针不是0，则与ptr1交换，交换后ptr1的位置向后靠一位，ptr2的位置向后移一位
    //                   如果是0，则不做处理，ptr2向后移一位
    //问题：空间复杂度有点高，但是想不到更好的办法了
       int ptr1=0,ptr2=0;
       while(ptr2<nums.size()){
        if(nums[ptr2]!=0){
            //swap(nums[ptr1],nums[ptr2]);
            int temp;
            temp=nums[ptr1];
            nums[ptr1]=nums[ptr2];
            nums[ptr2]=temp;
            ptr1++;
        }
        ptr2++;
       }
    }
};

int main(){

}