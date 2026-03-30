#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
//时间复杂度为O（n）的排序算法：1、计数排序 2、基数排序 3、桶排序
//本题实现的三个方法：1、快速选择 2、维护最小堆 3、计数排序
//实际方法：快速随机基准排序（qWq）
/*
//算法：计数排序
    //注意：一般的计数排序无法处理负数情况，需要增加偏移量
    int findKthLargest(vector<int>& nums, int k) {
        //记录最大值和最小值以确定区间
        int maxNum=INT_MIN;
        int minNum=INT_MAX;
        for(auto num : nums){
            if(num>maxNum)maxNum=num;
            if(num<minNum)minNum=num;
        }
        //根据最小值确定偏移量
        int offset=-minNum;
        vector<int> arr(offset+maxNum+1,0);
        //记录数字数量
        for(auto num : nums){
            arr[num+offset]++;  //要对应偏移量：当前数字索引=当前数字+偏移量
        }
        //寻找第k大的数字
        for(int i=maxNum+offset;i>=0;--i){  //注意是从maxNum+offset开始
            k-=arr[i];
            if(k<=0)return i-offset;    //返回结果的时候需要修正结果
        }
        return -1;  //一般来说不会执行到这里
    }
*/
//算法：基数排序
    //要支持负数比计数排序更麻烦了，不写了，去写官方题解了

/*
//算法：快速选择：
    //核心：不考虑全部的顺序，只考虑当前元素在排序后的位置
    //ps：是哪个byd设计的第44个用例（恼）
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums,0,nums.size()-1,nums.size()-k); //由后面的逻辑可以得到当前的传入k值应当是size-k值
    }

    int quickSelect(vector<int>& nums,int left,int right,int k){
        //1、如果传入的左边界==右边界，那么直接返回左边界元素
        if(left==right)return nums[left];
        //2、记录分割后的基准元素的索引位置
        int pivotIndex = partition(nums,left,right);
        //3、根据索引位置判断分割情况
        //3.1：如果相等那么已经找到，直接返回
        if(pivotIndex==k)return nums[k];
        //3.2：如果索引小于k那么说明：要找的元素比当前索引元素大，要从索引右边继续找
        else if(pivotIndex<k){
            return quickSelect(nums,pivotIndex+1,right,k);
        }
        //3.3：(pivotIndex>k)如果索引大于k那么说明：要找到元素比当前索引元素小，要从索引左边继续找
        else{
            return quickSelect(nums,left,pivotIndex-1,k);
        }
    }

    int partition(vector<int>& nums,int left ,int right){
        //1、选定一个随机基准元素
        int pivotIndex = left+rand()%(right-left+1);
        //2、将该基准元素记录并交换到右边界上
        int pivotNum=nums[pivotIndex];
        swap(nums[right],nums[pivotIndex]);
        //3、开始for循环，将对应元素根据大小放到两边
        //3.1、声明当前需要交换元素到的位置的索引
        int storeIndex = left;
        for(int i=left;i<right;++i){
            //3.2、如果当前元素小于基准元素那么将其与交换位置进行交换，记录交换位置的索引往后移一位
            if(nums[i]<pivotNum){
                swap(nums[i],nums[storeIndex]);
                storeIndex++;
            }
        }
        //4、遍历完后，一定有：当前交换位置索引前的元素比基准元素小，从交换位置索引开始的元素都比基准元素大，基准元素此时在nums[right]上
        //   于是有将当前基准元素的位置与当前交换位置索引的元素交换，此时完成了对于该基准元素在该区间内的依据该元素的大小的排序
        swap(nums[storeIndex],nums[right]);
        //5、返回当前基准元素排序后的位置
        return storeIndex;
    }
*/
//算法：维护最小堆：
    int findKthLargest(vector<int>& nums, int k) {
        //保证k值合法
        if(k<1||k>nums.size())return -1;
        //创建一个最小堆
        priority_queue<int,vector<int>,greater<int>>minHeap;
        //先将前k个元素加入最小堆
        for(int i=0;i<k;++i){
            minHeap.push(nums[i]);
        }
        //再将后面的元素加入最小堆，维护堆的大小为k
        for(int i=k;i<nums.size();++i){
            //如果当前元素比堆顶元素要大，那么推出堆顶元素，再加入该元素
            //也就是保证当前堆中元素是目前已经遍历到的元素中的前k个最大值，因为是最小堆所以堆顶是k个最大值中最小的那个
            if(nums[i]>minHeap.top()){
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        //最后的结果就是第k大的元素
        return minHeap.top();
    }

};
int main(){}