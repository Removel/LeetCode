#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //dfs:求得全排列的回溯算法
    void dfs(vector<vector<int>> &res,vector<int> &nums,vector<int>&tmp){
        //终止条件：tmp数组的大小等于nums，即此时tmp数组包含了nums的所有的元素
        if(tmp.size()==nums.size()){
            //将tmp加入到res结果当中
            res.push_back(tmp);
            return;
        }

        //遍历所有可选的数字
        for(int i=0;i<nums.size();++i){
            int j;//此处应当在外声明j，否则下面用不到j
            //检查此时遍历到的索引为i的数字是否已经在tmp当中
            for(j=0;j<tmp.size();++j){
                if(tmp[j]==nums[i])break;
                }
                //若不在数组tmp当中，则加入到tmp
                if(j==tmp.size()){
                    tmp.push_back(nums[i]);
                    //递归探索下一步
                    dfs(res,nums,tmp);
                    //当大小已经足够的时候需要使用该行代码
                    //去除数组最后一个元素，相当于撤销当前操作，回到上一个决策点
                    //在执行此操作之前，结果已被保存
                    tmp.pop_back();
            }
        }
    }
 
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res,nums,tmp);
        return res;
    }
};


int main(){

}