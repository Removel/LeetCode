#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 状态转移方程的推导：
     * 
     * 1. 初始状态（边界条件）：
     *    - dp[0][j] = j  （空字符串 -> word2的前j个字符，需要j次插入操作）
     *    - dp[i][0] = i  （word1的前i个字符 -> 空字符串，需要i次删除操作）
     * 
     * 2. 一般情况下的状态转移：
     *    对于 dp[i][j]，考虑 word1 的第 i 个字符（即 word1[i-1]）和 
     *    word2 的第 j 个字符（即 word2[j-1]）的关系：
     * 
     *    情况一：word1[i-1] == word2[j-1]
     *         两个字符相同，不需要额外操作
     *         当前状态就等于两个字符串各减少一个字符的状态
     *         dp[i][j] = dp[i-1][j-1]
     * 
     *    情况二：word1[i-1] != word2[j-1]
     *         需要从三种操作中选择一种使得操作次数最少：
     *         
     *         a) 删除操作：删除 word1 的第 i 个字符
     *            即 word1[0...i-2] -> word2[0...j-1] 的基础上 +1
     *            dp[i][j] = dp[i-1][j] + 1
     * 
     *         b) 插入操作：在 word1 的第 i 个字符后插入一个与 word2[j-1] 相等的字符
     *            即 word1[0...i-1] -> word2[0...j-2] 的基础上 +1
     *            dp[i][j] = dp[i][j-1] + 1
     * 
     *         c) 替换操作：将 word1 的第 i 个字符替换为 word2[j-1]
     *            即 word1[0...i-2] -> word2[0...j-2] 的基础上 +1
     *            dp[i][j] = dp[i-1][j-1] + 1
     * 
     *         取这三种操作的最小值：
     *         dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
     * 
     * 3. 最终答案：
     *    dp[len1][len2] 即为将整个 word1 转换为整个 word2 所需的最少操作次数
     * 
     * 时间复杂度：O(len1 * len2)
     * 空间复杂度：O(len1 * len2)
     */
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        
        // 创建dp数组，dp[i][j]对应word1前i个字符和word2前j个字符
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        
        // 初始化第一行：空字符串转换为word2的前j个字符
        for (int j = 1; j <= len2; ++j) {
            dp[0][j] = j;  // 需要j次插入操作
        }
        
        // 动态规划填表
        for (int i = 1; i <= len1; ++i) {
            dp[i][0] = i;  // 初始化第一列：word1的前i个字符转换为空字符串，需要i次删除操作
            
            for (int j = 1; j <= len2; ++j) {
                // 注意：dp[i][j]对应的是word1的第i个字符word1[i-1]和word2的第j个字符word2[j-1]
                if (word1[i - 1] == word2[j - 1]) {
                    // 字符相同，不需要额外操作
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // 字符不同，取三种操作的最小值（删除、插入、替换）+ 1
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
            }
        }
        
        // 返回将整个word1转换为整个word2的最小操作次数
        return dp[len1][len2];
    }
};



int main(){}