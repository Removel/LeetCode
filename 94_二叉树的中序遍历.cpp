#include <iostream>
#include <vector>
#include <stack>
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
//递归法
    void inorderRcrusive(TreeNode* root,vector <int> &ans){
        if(!root)return ;
        inorderRcrusive(root->left,ans);
        ans.push_back(root->val);
        inorderRcrusive(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
    vector <int> ans;
    inorderRcrusive(root,ans);
    return ans;
    }
*/
//迭代法：
    vector<int> inorderTraversal(TreeNode* root) {
    vector <int> ans;
    stack<TreeNode*> st;
    TreeNode *cur=root;
    while(cur||!st.empty()){
        while(cur){
        st.push(cur);
        cur=cur->left;    
        }
        cur=st.top();
        ans.push_back(cur->val);
        st.pop();
        cur=cur->right;
    }
    
    return ans;
    }
};



int main(){

}