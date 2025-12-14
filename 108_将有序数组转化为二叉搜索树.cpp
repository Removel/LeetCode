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

// Definition for a binary tree node.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }

    TreeNode* helper(vector <int> &nums, int l,int r){
        //终止条件：左指针在右指针之后
        if(l>r)return nullptr;
        //确定当前将要产生的根节点的值
        int mid=(l+r)/2;
        TreeNode *cur = new TreeNode(nums[mid]);
        //递归左右数组，在左边的数组就是左子树，右边的就是右子树
        cur->left=helper(nums,l,mid-1);
        cur->right = helper(nums,mid+1,r);
        //返回结果
        return cur;
    }
};





int main(){

}