#include <iostream>
#include <vector>
using namespace std;

//其实就是二分查找
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      int l=0,r=nums.size()-1;
      while(l<=r){
        int mid=(l+r)/2;
        int findnum=nums[mid];
        if(findnum==target)return mid;
        if(findnum>target)r=mid-1;
        else l=mid+1;
      }  
        return l;
    }
};


int main(){

}