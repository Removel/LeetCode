#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
/*
最近公共祖先问题：
    方法1：
    比较暴力的方法：
    对没有到指定两个节点中的层序顺序较前的节点前的所有节点进行深搜，搜到就更新，搜不到就下一个，直到到那个节点，对那个节点深搜，找得到就是它，找不到就是目前的节点
    假设前提：当更前面的一个节点前都没有公共祖先的时候，祖先即该点
    艹了写不出来，看解析吧
    
    方法2：
    依旧暴力的方法：
    找到root->p，root->q的路径，找到其中靠近最靠近末尾相同的点

——————以上为比较暴力的方法——————

    方法3：
    较为巧妙的方法：
        1、对于目标节点，找到了该节点之后停止向下遍历
        2、对于当前节点，将其子树分为左右两个子树：
            一、对左右两个子树分别递归查找目标节点，如果找到了则返回目标节点，使得返回结果非空
            二、若左和右子树都找到了节点（非空），那么说明当前节点是祖先节点；若都没找（全为空）到说明不是祖先节点，返回空；如果只找到了其中一方（一个空一个不空）说明只是找到了某一个目标的祖先节点，返回找到的一方使其向上传递
        
    方法4：
    更为巧妙的方法：直接合并了方法三当中的if条件，使得代码更加优雅
        1、终止递归条件：判断当前节点是否是目标或者空，是则找到了目标，返回；不是则未找到目标，返回空
        2、如果当前节点不终止递归，则说明

核心：返回左子树？右子树？当前节点？空？     
递归返回值的三种含义：
1、返回 NULL：当前子树中既没有p也没有q
2、返回非空节点（但不是当前节点）：当前子树中包含p或q（或已经找到的LCA）
3、返回当前节点：当前节点本身就是p或q，或者是找到的LCA   

！！！后序遍历能帮助我们先判断左右子树的情况再判断当前节点（即根节点）的情况

以下是对应的时空复杂度与特点：
方法	时间复杂度	空间复杂度	特点
暴力搜索	O(n²)	O(h)	简单但效率低
路径记录	O(n)	O(n)	需要额外存储路径
递归查找	O(n)	O(h)	最优解，代码简洁

*/
/*
方法三：
    TreeNode* dfs(TreeNode* root,TreeNode* p,TreeNode*q){
        if(!root)return NULL;
        if(root->val==p->val||root->val==q->val)return root;
        TreeNode *leftfind = dfs(root->left,p,q);
        TreeNode *rightfind= dfs(root->right,p,q);
        if(leftfind&&rightfind)return root;
        if(!leftfind&&rightfind)return rightfind;
        if(leftfind&&!rightfind)return leftfind;
        else return NULL;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root,p,q);
    }
*/
//方法四：
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //注：力扣题述表明节点值唯一，若值不唯一则应当比较的是指针而不是节点的值
        if(!root || root->val==p->val ||root->val == q->val)return root;
        TreeNode *l=lowestCommonAncestor(root->left,p,q);
        TreeNode *r=lowestCommonAncestor(root->right,p,q);
        //如果当前节点左右都找到了，说明是祖先
        if(l&&r)return root;
        //只找到一个则返回对应的树
        return l?l:r;
    }
};



int main(){

}