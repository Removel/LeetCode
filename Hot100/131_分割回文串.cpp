#include <string>
#include <iostream>
#include <vector>
using namespace std;

//可以发现，回溯最常见的难点是找到需要遍历的对象与对象处理
class Solution{
public:
vector<vector<string>> partition(string s) {
    vector<vector<string>> res;  // 存储最终所有合法的分割方案
    vector<string>tmpRes;        // 存储当前正在尝试的分割路径
    dfs(s,0,tmpRes,res);        // 启动深度优先搜索
    return res;
}

bool isPalindrome(string &str){
    if(str.size()<1)return false;  // 空串不是回文
    int left=0,right=str.size()-1;
    while(left<right){             // 双指针从两端向中间校验
        if(str[left]!=str[right])return false;
        left++;
        right--;
    }
    return true;
}

void dfs(string &s, int index, vector<string>&tmpRes,vector<vector<string>> &res){
    // 递归终止条件：已经遍历到字符串末尾（分割完成）
    if(index>=s.size()){
        res.push_back(tmpRes);  // 将当前合法的分割方案加入结果
        return ;
    }
    // 从当前 index 开始，尝试分割出所有可能的子串
    for(int i=index;i<s.size();++i){
        // 截取子串：从 index 到 i（包含 i）
        string tmp = s.substr(index,i-index+1);
        // 如果该子串是回文，说明这一步分割合法，继续递归
        if(isPalindrome(tmp)){
            tmpRes.push_back(tmp);  // 将合法子串加入临时路径
            dfs(s,i+1,tmpRes,res);  // 递归处理下一个位置（i+1）
            tmpRes.pop_back();      // 回溯：撤销当前选择，尝试下一种分割
        }
    }
}

};

int main(){}