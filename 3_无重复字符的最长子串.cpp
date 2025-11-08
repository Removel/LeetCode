/*
给定一个字符串 s ，请你找出其中不含有重复字符的最长子串的长度。
示例 1:

输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。


提示：
0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成
*/

class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			//以下为使用滑动窗口进行寻找，时间复杂度为o(n);
			string win = "";
			int left = 0;
			int size = s.size();
			int max = 0;
			if (size == 0) {
				return 0;
			}
			//此处可以使用hash表进行更加高效率的查阅内容
			for (int i = 0; i < size; ++i) {
				while (win.find(s[i]) != string::npos) {
					win.erase(0, 1);
					++left;
				}
				if (max < i - left + 1) {
					max = i - left + 1;
				}
				win += s[i];
			}
			return max;

		}
};