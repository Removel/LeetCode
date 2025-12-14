#include <iostream>
#include <vector>
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
    //使用中序遍历查找，当查找到第k个的时候返回结果即可
    void findnum(TreeNode *cur,int rank,int &nowRank,int &ans){
        if(!cur)return ;
        findnum(cur->left,rank,nowRank,ans);
        nowRank++;        
        if(nowRank==rank){
        ans=cur->val;
        return;
        }
        findnum(cur->right,rank,nowRank,ans);
    }
    //没有完成进阶的操作
    int kthSmallest(TreeNode* root, int k) {
    if(!root)return -1;
    int ans=0;
    int nowRank=0;
    findnum(root,k,nowRank,ans);
    return ans;    
    }
};


int main(){

}