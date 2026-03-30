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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.size()==0||inorder.size()==0)return nullptr;
    int index=0;
    TreeNode* root=new TreeNode(preorder[0]);
    for(int i=0;i<inorder.size();++i){
        if(inorder[i]==preorder[0])index=i;
    }
    vector<int> leftchildpreorder(preorder.begin()+1,preorder.begin()+index+1);
    vector<int> leftchildinorder(inorder.begin(),inorder.begin()+index);
    vector<int> rightchildpreorder(preorder.begin()+index+1,preorder.end());
    vector<int> rightchildinorder(inorder.begin()+index+1,inorder.end());
    root->left=buildTree(leftchildpreorder,leftchildinorder);
    root->right=buildTree(rightchildpreorder,rightchildinorder);
    return root;

    }
};


int main(){

}