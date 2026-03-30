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

//Definition for a binary tree node.
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

    void inorderTraversal(TreeNode *cur ,bool &ans,long &preVal){
        //某序遍历的规律：根据根的位置，将需要进行处理的代码放在相应位置即可
        //例如本题内容，需要使用中序遍历，于是放在了左右之间
        //本题思路：二叉搜索树在中序遍历上是严格递增的，只需要对比上一个遍历的值查看其是否严格递增即可
        if(!cur)return; 
        inorderTraversal(cur->left,ans,preVal);
        if(cur->val<=preVal){
            ans=false;
            return;
        }
        preVal=cur->val;
        inorderTraversal(cur->right,ans,preVal);
    }

    bool isValidBST(TreeNode* root) {
        bool ans=true;
        if(!root)return false;
        //byd力扣硬是要搞极端值恶心人
        //此处为了防止左右int极值，使用long防止溢出
        long preVal=LONG_MIN;
        inorderTraversal(root,ans,preVal);
        return ans;
    }
};




int main(){

}