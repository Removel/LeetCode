#include <iostream>
#include <vector>
#include <string>
using namespace std;

//该方法时间、空间复杂度较高，是因为先创建了z型数组储存目标的样式后再输出
//使得效率较低
class Solution {
	public:
		string convert(string s, int numRows) {
			int numrows = numRows;
			vector <vector <char>> z(numrows);
			int size = s.size();
			if (numrows == 1) {
				return s;
			}
			int count = 0;
			while (count < size ) {
				for (int i = 0; i < numrows + numrows - 2; ++i) {
					if (count >= size) {
						break;
					}
					if (i < numrows) {
						z[i].push_back(s[count]);
					} else if (i >= numrows) {
						z[2 * numrows - i - 2].push_back(s[count]);
					}
					count++;
				}
			}
			string res;
			for (int i = 0; i < numrows; ++i) {
				for (size_t j = 0; j < z[i].size(); ++j) {
					//	cout << z[i][j];
					res += z[i][j];
				}
				//cout << endl;
			}
			return res;
		}
};

//如果想要效率更高的话，不用生成这些东西在输出，而是直接用算法将结果生成
//以下为直接生成算法：
class Solution {
	public:
		string convert(string s, int numRows) {
			if (numRows == 1)//只有一行直接输出，而不却决于有多少字
				return s;
			string result;
			int n = s.length();
			int cycleLen = 2 * numRows - 2;  // 关键：周期长度

			for (int i = 0; i < numRows; i++) {
				for (int j = 0; j + i < n; j += cycleLen) {//此处j直接索引到当前行的每一个元素
					// 每列的主要字符
					result += s[j + i];//相当于把s字符串按照cyclelen划分组，j表示当前组，i表示当前组中第i个的元素
					// 斜线上的字符（不包括第一行和最后一行）
					if (i != 0 && i != numRows - 1 && j + cycleLen - i < n) {
						result += s[j + cycleLen - i];
					}
				}
			}
			return result;
		}
};