#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution {
public:
/*
//深度优先递归法
//awoc 力扣怎么这么坏，谁家curSum还会溢出啊'(qAq)'
    int dfs(TreeNode* root , long long curSum ,int targetSum ){
        if(!root) return 0;
        int count=0;
        curSum+=root->val;
        if(curSum==targetSum)count++;
        count+=dfs(root->left,curSum,targetSum);
        count+=dfs(root->right,curSum,targetSum);
        return count;
    }

    int bfs(TreeNode* root,int targetSum){
        if(!root)return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res=0;
        while(!q.empty()){
            long long curSum=0;
            res+=dfs(q.front(),curSum,targetSum);
            if(q.front()->left)q.push(q.front()->left);
            if(q.front()->right)q.push(q.front()->right);
            q.pop();
        }
        return res;
    }

    int pathSum(TreeNode* root, int targetSum) {
        int ans = bfs(root,targetSum);
        return ans;
    }
    */

//前缀和递归法：
    //大区间前缀和-小区间前缀和=当前期间前缀和（大、小区间都从第一个元素开始）
    //当前期间前缀和==targetSum的话，则有：大区间前缀和-targetSum=小区间前缀和
    //只需要深度优先遍历树+hashmap查找是否存在小区间前缀和即可找到是否存在路径
    //思路类似于 560_和为k的子数组 ？
    //还有记得用long long，byd力扣太坏了
    unordered_map<long long,int> rec;
    int dfs(TreeNode* &root,long long curSum,int &targetSum){
        if(!root)return 0;
        int count=0;
        curSum+=root->val;
        //记得先更新curSum再查表
        //如果存在，则加入hash表
        if(rec.count(curSum-targetSum)){
            count+=rec[curSum-targetSum];
        }
        //将前缀和加入到hash表当中
        rec[curSum]+=1;
        //递归遍历左右子树
        count+=dfs(root->left,curSum,targetSum);
        count+=dfs(root->right,curSum,targetSum);
        //回溯：移除当前前缀和★★★
        //作用：1、确保离开该路径的时候，该路径的影响被消除，在递归的时候会使得递归消除每一个递归上的路径
        //      2、这样使得不用额外产生新的hash表，减少了拷贝时间从而减少了总时间耗时
        rec[curSum]-=1;
        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        //小细节：rec[0]=1,对应curSum==targetSum的情况
        //这也是在560题没有说明的内容
        rec[0]=1;
        return dfs(root,0,targetSum);
    }
};


int main(){

}