#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //传参设定
        vector<vector<int>>res;
        vector<int>tmpArr;
        int tmpSum = 0;
        //调用
        dfs(candidates,target,tmpSum,tmpArr,res);
        return res;
    }
    //传入参数除了target（用于代替计算当前之和）和index（用于体现当前遍历到的元素的索引下标），其他都最好引用提高速度
    void dfs(vector<int>& candidates, int target,int index,vector<int>&tmpArr,vector<vector<int>>&res){
        //截止条件
        if(target<0)return ;
        if(target==0){
            res.push_back(tmpArr);
            return ;
        }
        //回溯经典方法
        for(int i=index;i<candidates.size();++i){
            //dfs剪枝，不剪枝会导致出现相同元素但是顺序不同的组合，可以通过别的方法去重，但是没必要而且太慢
            //核心：dfs剪枝：在决策树上不要 当前遍历到元素 的 之前的所有元素
            if(target-candidates[i]>=0){    //这里是先做条件判断减少不必要的递归
                tmpArr.push_back(candidates[i]);
                dfs(candidates,target-candidates[i],i,tmpArr,res);
                tmpArr.pop_back(); 
            }
        }
    }

};