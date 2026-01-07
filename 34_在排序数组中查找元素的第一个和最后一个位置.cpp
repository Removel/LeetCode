#include <vector>
using namespace std;

class Solution {
public:
/*
找到target时不停止搜索
根据查找方向继续缩小范围
binSearch函数通过isleft参数控制查找方向：
1、当isleft = true时（查找左边界）：继续向左搜索
        当nums[mid] == target时：不立即返回，而是让r = mid - 1，继续在左侧搜索，这样最终找到的是最左边的target位置
2、当isleft = false时（查找右边界）：继续向右搜索
        当nums[mid] == target时，不立即返回，而是让l = mid + 1，继续在右侧搜索，这样最终找到的是最右边的target位置

时间复杂度分析：
每次二分查找：O(log n)
两次二分查找：O(2 log n) = O(log n)        
*/
    int binSearch(vector<int>& nums, int target , int isleft){
        int l=0,r=nums.size()-1;
        int index=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]>target)r=mid-1;
            else if(nums[mid]<target)l=mid+1;
            else {
                index=mid;
                if(isleft)r=mid-1;
                else l=mid+1;
            }
        }
        return index;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = binSearch(nums,target,true);
        int right = binSearch(nums,target,false);
        return {left,right};
    }
};


int main(){
    
}