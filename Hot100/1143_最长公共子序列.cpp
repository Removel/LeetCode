#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
/*
    为了表示与计算方便将二维dp数组设置为多一行+多一列
    dp[i][j]表示在text1的前i个字符与text2的前j个字符的最长公共子序列的长度
    对于dp[i][j]只有几种情况：
    1、text1[i-1] == text2[j-1]（当前遍历到的字符相等）
    -》那么有dp[i][j]是dp[i-1][j-1]+1，为之前i,j的最大子序列加一
    2、text1[i-1] != text2[j-1]（当前遍历到的字符不相等）
    -》那么可以注意到，dp[i][j+1]和dp[i+1][j]分别对应的是在「去掉text1当前字符」的最长公共子序列或「去掉text2当前字符」的最长公共子序列这两种情况，取其最大值即可
*/
    int longestCommonSubsequence(string text1, string text2) {
        // 步骤1：定义并初始化二维dp数组
        // 行数：text1.size()+1，列数：text2.size()+1，所有元素初始化为0
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        // 步骤2：双层循环遍历两个字符串，填充dp数组
        // 外层循环：遍历text1的每个字符（i是text1的索引，对应dp的i+1行）
        for(int i=0;i<text1.size();++i){
            // 内层循环：遍历text2的每个字符（j是text2的索引，对应dp的j+1列）
            for(int j=0;j<text2.size();++j){
                // 情况1：当前字符相等，对应dp[i+1][j+1] = dp[i][j] + 1
                if(text1[i]==text2[j]){
                    dp[i+1][j+1] = dp[i][j] + 1 ;
                }
                // 情况2：当前字符不相等，取两个子问题的最大值
                else{
                    dp[i+1][j+1]= max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        
        // 步骤3：返回最终结果
        // dp[text1.size()][text2.size()] 表示text1完整字符串和text2完整字符串的LCS长度
        return dp[text1.size()][text2.size()];
    }
};




int main(){

}