#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
/*
数组旋转导致该有序数组被分为了两个部分，暂且称为a，b，其中有a.min>b.max
于是进行二分查找数组内容：
l，r，mid  -》 mid=（l+r）/2
对于mid对应元素可能存在以下几种情况：
1、 在 a组内，nums[mid] <nums[r]  ->target是否在l，mid当中？在则对该区间二分查找；不在则l=mid+1；
2、 在 b组内，nums[mid] >nums[l]  ->target是否在mid，r当中？在则对该区间二分查找；不在则r=mid-1；
由于a，b子数组有序，于是只需要判断mid等对应元素与target关系就能明白target是否在其中区间
可以画图表示，在纸上画出xoy平面图：y=x+1 和 y=x-1 在x，y属于（2，2）的图像更好理解
*/
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        int mid = 0; 
        while(left<=right){
            mid = (left + right)/2;
            if(target==nums[mid])return mid;
            //第一种情况
            if(nums[mid]>=nums[left]){
                if(target<nums[mid]&&target>=nums[left]){
                    right=mid-1;
                }    
                else left=mid+1;
            }
            //第二种情况
            else if(nums[mid]<nums[right]){
                if(target>nums[mid]&&target<=nums[right]){
                    left=mid+1;
                }
                else right=mid-1;
            }
        }
        /*
        //普通的二分查找
        while(left<right){
        mid=(left+right)/2;
        if(nums[mid]==target)return mid;
        if(nums[mid]<target)left = mid + 1;
        else if(nums[mid]>target)right = mid - 1;   
        }
        */
        return -1;
    }
};

int main(){

}