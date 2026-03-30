#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    //以下是自己尝试实现，失败，只能实现部分内容，会出现重复的问题
    /*
        sort(nums.begin(),nums.end());
      vector <vector <int>> res;
      for(int i=0;i<nums.size();++i){
      vector <int> oneres;  
    //    if(nums[i]==nums[i+1])continue;
        int ptr1=i+1,ptr2=nums.size()-1;
        while(ptr1<ptr2){
        //    while(nums[ptr1]!=nums[ptr1+1]&ptr1<ptr2)ptr1++;
        //    while(nums[ptr2]!=nums[ptr2-1]&ptr1<ptr2)ptr2--;
            if(nums[ptr1]+nums[ptr2]>-nums[i]){
                ptr2--;
            }
            else if(nums[ptr1]+nums[ptr2]<-nums[i]){
                ptr1++;
            }
            else if(nums[ptr1]+nums[ptr2]==-nums[i]){
                oneres.push_back(nums[i]);
                oneres.push_back(nums[ptr1]);
                oneres.push_back(nums[ptr2]);
                res.push_back(oneres);
                break;
            }
        }
      }  
      return res;
      */
    vector <vector <int>>res; 
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();++i){
        if(i>0&&nums[i]==nums[i-1])continue;
        int l=i+1,r=nums.size()-1;
        int target=0-nums[i];
        while (l<r){
        if(nums[l]+nums[r]==target){
            res.push_back({nums[i],nums[l],nums[r]});
            while(l<r&&nums[l]==nums[l+1])l++;
            while(l<r&&nums[r]==nums[r-1])r--;
            l++;
            r--;
        }
        else if(nums[l]+nums[r]<target)l++;
        else r--;
        }
    }
    return res;
}
};

int main (){
Solution s;
vector <int> test={-1,0,1,2,-1,-4};
vector <vector <int> >res=s.threeSum(test);
for(int i=0;i<res.size();++i){
    for(int j=0;j<res[i].size();++j){
        cout<<res[i][j]<<" ";
    }
    cout<<endl;
}
return 0;
}