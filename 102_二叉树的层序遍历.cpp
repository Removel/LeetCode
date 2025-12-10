#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
    /*
        queue<TreeNode*> nowlevel;
        queue<TreeNode*> nextlevel;
        vector <vector <int>> ans;
        if(!root)return ans; 
        nextlevel.push(root);
        while(!nowlevel.empty()||!nextlevel.empty()){
            vector <int> levelans;
            while(!nextlevel.empty()){
                nowlevel.push(nextlevel.front());
                nextlevel.pop();
            }
            while(!nowlevel.empty()){
                levelans.push_back(nowlevel.front()->val);
                if(nowlevel.front()->left!=nullptr)nextlevel.push(nowlevel.front()->left);
                if(nowlevel.front()->right!=nullptr)nextlevel.push(nowlevel.front()->right);
                nowlevel.pop();
            }
            ans.push_back(levelans);
        }
        return ans;
        */
        //优化中
        //使用两个队列过于繁琐，优化：进行下一轮之前记录当前队列大小并按照次数弹出即可代替另外一个队列的作用
        queue<TreeNode*> q;
        vector<vector<int>>ans;
        if(!root)return ans;
        q.push(root);
        while(!q.empty()){
            int levelSize=q.size();
            vector <int> levelAns;
            for(int i=0;i<levelSize;++i){
                levelAns.push_back(q.front()->val);
                if(q.front()->left!=nullptr)q.push(q.front()->left);
                if(q.front()->right!=nullptr)q.push(q.front()->right);
                q.pop();
            }
            ans.push_back(levelAns);
        }
        return ans;
    }
};




int main(){

}