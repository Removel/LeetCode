#include <iostream>
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
    int treeDepth(TreeNode *cur,int &maxlength){
        if(!cur)return 0;
        int leftlength=treeDepth(cur->left,maxlength);
        int rightlength=treeDepth(cur->right,maxlength);
        maxlength=max(maxlength,leftlength+rightlength);
        return max(leftlength,rightlength)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res=0;
        int tmp=treeDepth(root,res);
        return res;
    }
};