#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
//评论区题解思路
    int maxPathSum(TreeNode* root) {
        int res = -1000;
        int ans = getMaxTreePathSum(root,res);
        return max(ans,res);
    }

    int getMaxTreePathSum(TreeNode* root , int &maxNum ){
        if(!root)return -1000;
        int leftSum = getMaxTreePathSum(root->left,maxNum);
        int rightSum = getMaxTreePathSum(root->right,maxNum);
        maxNum = max(maxNum,leftSum);
        maxNum = max(maxNum,rightSum);
        maxNum = max(maxNum,leftSum+rightSum+root->val);
        int acc = root->val;
        acc = max(acc,root->val+leftSum);
        acc = max(acc,root->val+rightSum);
        return acc;
    }
*/
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        /*
        //注意不能这样写！这样写使得res原本的作用为记录全局最大值变成了根节点下的最大值
        res = getMaxTreePathSum(root,res);    //getMaxTreePathSum(root,res)最后返回的值是根节点的路径最大值，不是全局最大值
        */
        getMaxTreePathSum(root,res);
        return res;
    }

    int getMaxTreePathSum(TreeNode* root ,int &maxNum){
        if(!root)return 0;
        //统计左边子树对该根节点上的贡献值，如果小于0则不贡献，跟0比较取较大值
        int left = max(getMaxTreePathSum(root->left,maxNum),0);
        //统计右边子树对该根节点上的贡献值，如果小于0则不贡献，跟0比较取较大值
        int right = max(getMaxTreePathSum(root->right,maxNum),0);
        //更新全局最大值，当前路径和为：根节点值+左边子树贡献值+右边子树贡献值与当前全局最大值比较取较大值
        //如果选择了根节点+左边子树+右边子树的贡献值，那么就不能再向上传递了
        maxNum = max(root->val+left+right,maxNum);
        //不需要额外写 max(根节点, 根+左, 根+右, 根+左+右)，
        ///因为 root->val + left + right 已经通过 left/right 的 0 值，自动包含了前 3 种场景。
        return root->val+max(left,right);
    }
};

/*
所以总共有以下几种情况：
1、仅计算根节点
2、仅计算左子树
3、仅计算右子树
4、计算根节点+左子树
5、计算根节点+右子树
6、计算根节点+左子树+右子树
其中2，3，6不能向上传递，因为它们不包含根节点，而1，4，5可以向上传递，因为它们都包含根节点。
*/


int main(){}