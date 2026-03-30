#include <stack>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 函数功能：计算字符串中最长有效括号子串的长度
    // 参数 s：仅包含 '(' 和 ')' 的输入字符串
    // 返回值：最长有效括号子串的长度
    int longestValidParentheses(string s) {
        // 栈：存储左括号的下标，用于匹配对应的右括号
        stack<int> tool;
        // 标记数组：rec[i]为true表示s[i]位置的括号是有效括号的一部分，初始全为false
        vector<bool> rec(s.size(), false);

        // 第一步：遍历字符串，标记所有有效括号的位置
        for (int i = 0; i < s.size(); ++i) {
            // 情况1：栈为空且当前字符是右括号 → 无匹配的左括号，直接跳过
            if (tool.empty() && s[i] == ')') {
                continue;
            }
            // 情况2：当前字符是左括号 → 将其下标压入栈，等待匹配
            else if (s[i] == '(') {
                tool.push(i);
            }
            // 情况3：当前字符是右括号，且栈顶下标对应的字符是左括号 → 匹配成功
            else if (s[i] == ')' && s[tool.top()] == '(') {
                // 获取栈顶左括号的下标
                int left = tool.top();
                tool.pop(); // 匹配成功，弹出栈顶左括号下标
                rec[i] = true;   // 标记当前右括号为有效
                rec[left] = true;// 标记匹配的左括号为有效
            }
        }

        // 第二步：遍历标记数组，统计最长连续有效括号的长度
        int maxsize = 0; // 记录最长有效括号长度，初始为0
        int count = 0;   // 临时记录当前连续有效括号的长度，初始为0

        for (int i = 0; i < s.size(); ++i) {
            // 当前位置是有效括号 → 连续长度+1
            if (rec[i]) {
                count++;
            }
            // 当前位置是无效括号 → 结算当前连续长度，更新最大值
            else {
                maxsize = max(count, maxsize);
                count = 0; // 重置临时计数
            }
        }
        // 补充：处理最后一段连续有效括号（避免末尾全为有效括号时未结算）
        maxsize = max(count, maxsize);

        // 返回最长有效括号长度
        return maxsize;
    }
};

int main(){}