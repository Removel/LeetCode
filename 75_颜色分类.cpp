#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
/*
//类似于双指针当中的移动0那道题，多使用几个指针就可以了多遍历几次就可以了？
    void sortColors(vector<int>& nums) {
        int zeroPtr = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0){
                swap(nums[zeroPtr],nums[i]);
                zeroPtr++;
            }
        }
        int onePtr = zeroPtr;
        for(int i=zeroPtr;i<nums.size();++i){
            if(nums[i]==1){
                swap(nums[onePtr],nums[i]);
                onePtr++;
            }
        }
        int twoPtr = onePtr;        
        for(int i=onePtr;i<nums.size();++i){
            if(nums[i]==2){
                swap(nums[twoPtr],nums[i]);
                twoPtr++;
            }
        }
    }
//这样写似乎有点过于繁琐了，但是好处是这样下来的思路比较清晰    
*/    
/*
//优化了一下写法，能够使得在以后该程序被调用的时候不止仅限于012三种颜色编号。
//有几个颜色就会将数组遍历几次，还是太慢了（即时间复杂度O（kn））
    void sortColors(vector<int>& nums) {
        int ptr=0;
        int nowNum = 0;
        int maxNum = 2;
        while(nowNum<=maxNum){
            int nowStart = ptr;
            for(int i = nowStart;i<nums.size();++i){
                if(nums[i]==nowNum){
                    swap(nums[i],nums[ptr]);
                    ptr++;
                }
            }
            nowNum++;
        }
    }
*/

/*
荷兰国旗问题解决方法：三指针法
三指针：left、mid、right（又可称：low、mid、high）
left指针表示已经排序的第一种元素的最后位置，mid既是当前元素又是已经排序的第二种元素的最后一个位置，right就是已经排序的第三种元素，但是right指向最开始的位置（从后往前）
当当前的mid指针<=right时保持循环：
1、mid-》0，与left指向互换，二者共同向后移动一个元素
2、mid-》1，不用管，认为已经排序好了，后移一位
3、mid-》2，与right指向呼唤，mid后移一位，right前移一位
*/
    void sortColors(vector<int>& nums) {
        int left = 0,mid = 0,right = nums.size()-1;
        while(mid<=right){
            if(nums[mid]==0){
                swap(nums[mid],nums[left]);
                left++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }else {//nums[mid]==2
                swap(nums[mid],nums[right]);
                right--;
            }
        }    
    }

/*
其实还有更加直白的方法：遍历一边数组统计一次各个元素出现的次数，再填充一次即可，但是这样下来的空间复杂度不是常数级别
    void sortColors(vector<int>& nums) {
        vector <int> arr(3,0);
        for(int num:nums){
            arr[num]++;
        }
        int arrptr=0;
        for(int i=0;i<nums.size();++i){
            if(arr[arrptr]>0){ 
                nums[i]=arrptr;
                arr[arrptr]--;
            }
            else {
                arrptr++;
                i--;//这里写的并不标准，请使用更加标准的方法来合理处理回退i的方式
            }
        }
    } 
*/
};


int main(){

}