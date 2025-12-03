/**
 * Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
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
//所谓翻转二叉树实际上就是队二叉树的左右子树进行交换
//然后递归所有节点进行交换即可
    void invertTreefunc(TreeNode* cur){
        if(!cur)return;
        TreeNode *tmp=cur->left;
        tmp=cur->left;
        cur->left=cur->right;
        cur->right=tmp;
        invertTree(cur->left);
        invertTree(cur->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        TreeNode *cur=root;
        invertTreefunc(cur);
        return root;
    }
};

int main(){

}