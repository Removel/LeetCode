#include <iostream>
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
//先交换左子树的左右子树，若为轴对称则此时左右子树会相同，再依次根据左右子树内容递归检查即可
//但是这样写好像有点事多，并且破坏了树结构
/*
    void exchangeChild(TreeNode * cur){
        if(!cur)return ;
        TreeNode *tmp;
        tmp=cur->left;
        cur->left=cur->right;
        cur->right=tmp;
        exchangeChild(cur->left);
        exchangeChild(cur->right);
    }

    bool isSameChild(TreeNode *left,TreeNode *right){
        if(!left&&!right)return true;
        else if((left&&!right)||(!left&&right))return false;
        else if(left->val!=right->val)return false;
        //这一行的return的值意义在于：递归调用的时候当前子树是否相同的return值取决于其后面递归调用的其子树检查的值是否为真
        return isSameChild(left->left,right->left)&&isSameChild(left->right,right->right);//return的值是这个，记住了不要分开写
    }
    //要使用递归调用的结果

    bool isSymmetric(TreeNode* root) {
        exchangeChild(root->left);
        return isSameChild(root->left,root->right);
    }
*/
    bool isMirror(TreeNode *left ,TreeNode *right){
        if(!left&&!right)return true;
        else if((left&&!right)||(!left&&right))return false;
        else if(left->val!=right->val)return false;
        return isMirror(left->right,right->left)&&isMirror(left->left,right->right);
    }


    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left,root->right);
    }

};


int main(){
    
}