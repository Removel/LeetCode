#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    //自己的想法1：类似回文子串的方法使用双指针遍历，时间复杂度O(n方)估计是
    //时间过长，需要另一个方法hhh，不过好歹空间复杂度除开结果数组就是O(1);
    /*
    vector <int> res(nums.size());
    for(int i=0;i<nums.size();++i){
        int l=i-1,r=i+1;
        int mult=1;
        while(l>=0){
            mult=nums[l]*mult;
            l--;
        }
        while(r<=nums.size()-1){
            mult=nums[r]*mult;
            r++;
        }
        res[i]=mult;
    }   
    return res;
    */
    //前缀和-》前缀积，后缀和-》后缀积？
    //这依旧不是最好的方法，因为这导致了空间复杂度为O(n);
    //存在空间复杂度为O(1)的方法
    /*
    vector <int> frontmult(nums.size());
    vector <int> behindmult(nums.size());
    vector <int> res(nums.size());
    int front=1,behind=1;
    for(int i=0;i<nums.size();++i){
        front=front*nums[i];
        behind=behind*nums[nums.size()-i-1];
        frontmult[i]=front;
        behindmult[nums.size()-i-1]=behind;
    } 
    for(int i=0;i<nums.size();++i){
        if(i==0)res[i]=behindmult[i+1];
        else if(i==nums.size()-1)res[i]=frontmult[i-1];
        else {
            res[i]=frontmult[i-1]*behindmult[i+1];
        }
    }
    return res;
    */
    //思考过后可以得到，若想要把空间复杂度将为O(1)，我们可以选择不使用两个缀积（man！）数组，而是使用两个变量直接更新当前数组？
    //但问题是在正向遍历的时候，后缀积的数字没有得到，而且直接改变的话会导致原数组无法使用
    //欸我有个点子，既然题目提到结果数组不算空间，那么我钻空子？把原数组直接给结果数组然后把原数组改为后缀数组，再将res数组正向遍历更新即
    //可？
    vector <int> res=nums;
    int front=1,behind=1;
    for(int i=nums.size()-1;i>=0;--i){
        behind=nums[i]*behind;
        nums[i]=behind;
    }
    for(int i=0;i<nums.size();++i){
        if(i==0){
            front=res[i];
            res[i]=nums[i+1];
            }
        else if (i==nums.size()-1)res[i]=front;  
        else{
            int nownum=res[i];
            res[i]=front*nums[i+1];
            front*=nownum;
        }
    }
    return res;
    }
    //时间复杂度为O(n),空间复杂度为O(1),分别超过100%和80.75%的人，win

};

int main(){

}

