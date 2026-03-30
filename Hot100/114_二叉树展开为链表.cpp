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
/*
    //O(n)空间复杂度解法
    void preOrder(TreeNode* root,vector<int>&ans){
        if(!root)return ;
        ans.push_back(root->val);
        preOrder(root->left,ans);
        preOrder(root->right,ans);
    }
    
    void flatten(TreeNode* root) {
    //依照题目描述，空间复杂度为O(n)的算法很简单，将先序遍历到的节点放到一个新的链表当中即可
    if(!root)return;
    vector<int> ans;
    preOrder(root,ans);
    TreeNode* cur=root;
    TreeNode* res=cur;
    for(int i=1;i<ans.size();++i){
    cur->left=nullptr;
    TreeNode *next=new TreeNode(ans[i]);
    cur->right= next;
    cur=cur->right;
    }
    root=res;
    }
    //写的还是过于繁琐了，可以直接用treenode的
    //但是并不重要。。。
*/
/*
    //O(1)空间复杂度解法（原地算法）,但是时间复杂度来到了O(n方)
    void flatten(TreeNode* root) {
        if(!root)return ;
        flatten(root->left);
        flatten(root->right);
        TreeNode * nowr=root->right;
        root->right=root->left;
        root->left=nullptr;
        TreeNode* cur=root;
        while(cur->right){
            cur=cur->right;
        }
        cur->right=nowr;
    }
*/
//时间复杂度为O(n)方法
    TreeNode* prev = nullptr;

    void flatten(TreeNode* root) {
    if (!root) return;
    // 先处理右子树，再处理左子树
    flatten(root->right);
    flatten(root->left);
    // 将当前节点连接到前一个节点
    root->right = prev;
    root->left = nullptr;
    prev = root;
    }
//其实使用的是右左根，类似后序遍历，记录已处理好的链表的头节点，将当前遍历到的节点插入链表表头即可
//这样链表反过来（正序）就是根左右，即前序遍历
};





int main(){

}
