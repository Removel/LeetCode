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
    vector<int> rightSideView(TreeNode* root) {
//使用层序遍历，将每层（队列）当中的最后一个元素加入答案数组即可
    vector <int>ans;
    queue<TreeNode*>bfs;
    //防止空树
    if(!root)return ans;
    //初始化空树
    bfs.push(root);
    while(!bfs.empty()){
        int size=bfs.size();
        for(int i=0;i<size;++i){
            TreeNode *cur=bfs.front();
            //依据遍历情况，此处应当先左后右
            if(cur->left)bfs.push(cur->left);
            if(cur->right)bfs.push(cur->right);
            //本轮结束的时候将本轮最后一个节点加入到答案数组当中
            if(i==size-1){
            ans.push_back(cur->val);
            }
            bfs.pop();
        }
    }
    return ans;
    }
};




int main(){

}