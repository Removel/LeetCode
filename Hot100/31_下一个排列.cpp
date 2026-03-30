#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*
multiset:
1、cpp的一种stl容器，能够做到记录重复的数字，保证该容器内有序排列
2、 .erase(number) 从容器中删除该数字
    .upper_bound(number) 从容器中找到>=number最接近的数字
    .emplace(number) 将该数字插入到该多重集合当中 
*/
/*
思路：
从决策树来看，可以通过回溯的方式得到所有的排列
从所有排列当中必定存在题目给定排列，于是从该排列开始回溯：
假如给定的排列是[1,4,2,5,3]:
1、从尾部开始回溯：此时数组为[1,4,2,5,3]，集合为空
2、回溯3：此时数组为[1,4,2,5,nil]，集合为[3]。我们此时尝试寻找比3更大的最接近的数字-》不存在，继续回溯
3、回溯5：此时数组为[1,4,2,nil,nil]，集合为[3,5]。我们此时尝试寻找比5更大的最接近的数字-》不存在，继续回溯
4、回溯2：此时数组为[1,4,nil,nil,nil]，集合为[2,3,5]。我们此时尝试寻找比2更大的最接近的数字：3
-》将3填入数组，此时为：[1,4,3,nil,nil]，集合为[2,5]。
5、只要将一个数字回填之后，即满足下一个字典序排列在该位置的需要，在之后的位置只需要将集合中的数字按顺序从小到大加入：
-》数组为:[1,4,3,2,5]，集合为空
于是我们就这样得到了下一个字典序排列

注意：如果当前字典序排列已经最大会导致下一个字典序排列最小，比如：
当前：[5,4,3,2,1]->下一个:[1,2,3,4,5]

*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //初始化使用的数据结构：多重集合
        multiset<int> candidates;
        //当数组内还有数字而且还没回填的时候
        while(nums.size()){
            //提取数组最后一个数字到集合当中，记得将该数字从数组中踢出去
            int preNum = nums.back();
            nums.pop_back();
            candidates.emplace(preNum);
            //在集合当中寻找比当前数字更大但是最接近的数字
            if(candidates.upper_bound(preNum)!=candidates.end()){
                //找到了那么就将集合中该数字回填到数组当中，记得从集合中删除
                auto curNum = candidates.upper_bound(preNum);
                nums.push_back(*curNum);
                candidates.erase(curNum);
                //回填过一次就要结束循环
                break;
            }
        }
        //将剩下的集合中的数字按照顺序从小到大从尾部加入到数组当中
        for(auto num : candidates){
            nums.push_back(num);
        }
    }
};


int main(){}
