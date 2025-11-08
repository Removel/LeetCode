#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;



class Solution {
public:
//方法一：时间复杂度：O(n)
    int longestConsecutive1(vector<int>& nums) {
        unordered_map <int,int> record;
    int size=nums.size();
    for(int i=0;i<size;++i){
        int head=record.find(nums[i]-1)==record.end()?0:record[nums[i]-1];
        int tail=record.find(nums[i]+1)==record.end()?0:record[nums[i]+1];
        if(record.find(nums[i])==record.end()){
        record[nums[i]]=head+tail+1;
        record[nums[i]-head]=record[nums[i]];
        record[nums[i]+tail]=record[nums[i]];    
        }
    }
    int max=0;
    for(auto i=record.begin();i!=record.end();++i){
        if(max<i->second)max=i->second;
    }
    return max;
    }
//方法二：时间复杂度：O(nlogn),不推荐使用，因为是暴力解法，在n<=10的时候会比上面的快
//但是在力扣上时间更快???    
int longestConsecutive2(vector<int>& nums) {
    if(nums.size()==0)return 0;
    sort(nums.begin(),nums.end());
    auto last = unique(nums.begin(), nums.end());
    nums.erase(last, nums.end());
    // for(int i=0;i<nums.size();++i){
    //     cout<<nums[i]<<" ";
    // }
    // cout<<endl;
    int maxlength=1;
    int nowsize=1;
    for(int i=0;i<nums.size()-1;++i){
       if(nums[i]==nums[i+1]-1){
            nowsize++; 
            maxlength=max(nowsize,maxlength);
        }else {
           
            nowsize=1;
        }
    }
    return maxlength;
    }
};

int main(){
Solution s;
vector <int> nums={0,3,7,2,5,8,4,6,0,1};
cout<<s.longestConsecutive1(nums)<<endl;
cout<<s.longestConsecutive2(nums)<<endl;
return 0;
}