#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      //属于是立刻想到了前缀和，但是再如何查找sum[i]-sum[j]是否等于k值陷入了思考
        //提示中提到使用哈希表，但是没想到怎么用，经过提醒想到一个方向：
        //sum[i]-sum[j]=k 可以表示为sum[i]-k=sum[j],对sum[j]只需要用哈希表查表是否存在即可
        //这样做将查找的时间复杂度由O(n)->O(1);
        //尝试自己实现：失败了，使用的方法跟下面相同但是不知道为什么有问题
        int res=0;
        int cur_num=0;
        unordered_map<int,int> record;
        record[cur_num]=1;
        for(int i=0;i<nums.size();++i){
            cur_num+=nums[i];
            int target=cur_num-k;
            if(record[target]){
                res+=record[target];//原因在这里，hash表记录了和为cur_num的子数组的数量，如果不加就只能找到一个，从而不符合条件，估计之前错就是在这里
            }
            record[cur_num]+=1;//这里必须是+=1
        }
        return res;  
    }
};



int main(){

}