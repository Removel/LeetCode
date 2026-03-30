#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
	public:
		vector<int> twoSum(vector<int> &nums, int target) {
			/*
				//暴力算法：
				vector <int>res(2, 0);
				int size = nums.size();
				for (int i = 0; i < size; ++i) {
					for (int j = 0; j < size && i != j; ++j) {
						if (nums[j] == target - nums[i]) {
							res[0] = i;
							cout << i << " ";
							res[1] = j;
							cout << j << endl;
							return res;
						}
					}
				}
			}
			*/
			//尝试使用类似hash表减少事件复杂度：
			//没有意识到同样的数字会使得hash表（map）冲突，需要改正

			vector <int> res(2, 0);
			map<int, int>hash;
			int size = nums.size();
			for (int i = 0; i < size; ++i) {
				//需要在加入前寻找是否存在补数
				int num = target - nums[i];
				if (hash.find(num) != hash.end() ) {
					res[0] = hash[num];
					res[1] = i;
					return res;
				}
				//找不到再加入
				else
					hash[nums[i]] = i;
			}
			return res;
		}





};

int main() {
	Solution p;

	vector <int> nums = {3, 3};
	int target = 6;
	vector <int> op = p.twoSum(nums, target);
	cout << op[0] << " " << op[1] << endl;
	return 0;
}
