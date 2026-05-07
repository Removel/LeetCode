#include <stack>
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
// 暴力做法：时间复杂度为O(n*n)
// woc一次过！？
    // 遍历找到副数组的最大值的索引
    int findMaxNumIndex(vector<int>& nums,int left,int right){
        int resIndex = left;
        for(int i=left;i<=right;++i){
            resIndex=nums[resIndex]>nums[i]?resIndex:i;
        }
        return resIndex;
    }

    // 核心：递归建树
    TreeNode* buildTree(vector<int>&nums,int left,int right){
        // 停止条件：左右到达边界或者左大于右-》返回空指针
        if(left<0||right>=nums.size()||left>right)return nullptr;
        // 寻找当前最大值并建立当前根节点
        int nowMaxNumIndex = findMaxNumIndex(nums,left,right);
        TreeNode* root =new TreeNode(nums[nowMaxNumIndex]);
        // 递归左右建树，通过左右边界提取副数组边界，同时记得递归时调用更新左右边界
        root->left=buildTree(nums,left,nowMaxNumIndex-1);
        root->right=buildTree(nums,nowMaxNumIndex+1,right);
        // 返回
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // 建树
        return buildTree(nums,0,nums.size()-1);
    }
*/
// 单调栈做法：时间复杂度为O(n)
/*
核心：
一、找每个元素在最终树里的父节点：每个元素的父节点是它左边第一个更大的数和右边第一个更大的数中较小的那个。
二、确定左右孩子关系：
    1、如果左边更大的数更小，那当前元素就是左边那个数的右孩子。
    2、如果右边更大的数更小，那当前元素就是右边那个数的左孩子。
    3、如果没有更大的数，它就是根。
由二可使用单调栈
*/
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // 需要使用的变量声明
        stack<int> st;
        vector<int> left(nums.size(),-1),right(nums.size(),-1);     //left用于记录当前数字左侧第一个比他更大的数字，right则是右侧
        vector<TreeNode*>tree(nums.size());     //用于保存树节点
        // 单调栈遍历
        for(int i=0;i<nums.size();++i){
            tree[i]=new TreeNode(nums[i]);      //保存树节点
            // 单调栈：寻找到当前元素的右侧的第一个更大值
            while(!st.empty()&&nums[st.top()]<nums[i]){
                right[st.top()]=i;
                st.pop();
            }
            // 遍历完后，如果栈非空，此时应当有栈顶索引对应元素>此时的元素，此时该栈顶对应元素对应就是当前元素的左边第一个更大元素，记录到对应的left当中，
            if(!st.empty()){
                left[i]=st.top();
            }
            // 入栈
            st.push(i);
        }

        // 建树过程
        TreeNode* root = nullptr;
        for(int i=0;i<nums.size();++i){
            // 1、没有左右更大 → 全局最大 → 根节点
            if(left[i]==-1&&right[i]==-1){
                root = tree[i];
            }
            // 2、左边更大的数字 相较于 右边更大的数字 更小 → i 是 left[i] 的右孩子 或者 没有右边的数字了->当前数字一定是左边更大数字的右节点
            else if(right[i]==-1||(left[i]!=-1&&nums[left[i]]<nums[right[i]])){
                tree[left[i]]->right = tree[i];
            }
            // 3、右边更大更小 → i 是 right[i] 的左孩子
            else tree[right[i]]->left = tree[i];
        }
        return root;
    }
};
// 可以了解一下笛卡尔树，本题相当程度上就是在构建笛卡尔树，单调栈的做法就是在构建笛卡尔树的过程中寻找每个节点的父节点。