#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void getAllVec(vector<int>&nums,vector<vector<int>>&ans,int pathLen,vector<int>&tmp){  
        //终止条件：当前的pathlen到了nums的长度，即所有数字都尝试过了
        if(pathLen==nums.size()){
            //这个时候才push_back！
            ans.push_back(tmp);
            return;
        }
        //选择当前数字加入数组的情况
        tmp.push_back(nums[pathLen]);
        getAllVec(nums,ans,pathLen+1,tmp);//一定是要在这里就加一而不是最后单独拎出来+1！
        //回溯体现：取消当前数字加入，即选择当前数字不加入数组的情况
        tmp.pop_back();
        getAllVec(nums,ans,pathLen+1,tmp);//同上
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        getAllVec(nums,ans,0,tmp);
        return ans;
    }
};

int main(){

}