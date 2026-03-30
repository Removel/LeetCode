#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
//使用双指针，一个开头一个结尾
//只有在移动短板的时候才有可能使得容器体积变大     
        int size=height.size();
        int ptr1=0,ptr2=size-1;
        int maxwater=0;
        while(ptr1<=ptr2){
            int length=ptr2-ptr1;
            int high=min(height[ptr2],height[ptr1]);
            maxwater=maxwater<=length*high?length*high:maxwater;
            if(high==height[ptr1]){
                ptr1++;
            }else if(height[ptr2]==high){
                ptr2--;
            }
            
        }
        return maxwater;
    }
};

int main(){



}