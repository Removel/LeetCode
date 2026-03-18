#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        //如果给定字符长度为0则直接返回空集
        if(digits.size()==0)return{};
        //给定参数准备：
        unordered_map<char,string>rec{
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        string tmp ="";
        vector<string> res{};
        //调用函数
        dfs(res,digits,0,rec,tmp);
        return res;
    }

    void dfs(vector<string> &res ,string &digits,int index,unordered_map<char,string> &rec,string &tmp){
        //截至条件：tmp长度与digits相等
        if(tmp.size()==digits.size()){
            res.push_back(tmp);
            return ;
        }
        //多层逻辑转换：
        //index-》digits遍历，digits[index]-》得到对应的遍历数字，rec[digits[index]]-》得到对应字符串，getChar-》得到字符串遍历字符
        for(auto getChar : rec[digits[index]]){
            //常用回溯方法如下：
            tmp.push_back(getChar);
            //记得index+1表示下一个，由于在前面tmp长度足够的时候就截至，不会出现index越界情况
            dfs(res,digits,index+1,rec,tmp);
            tmp.pop_back();
        }
    }

};


int main(){}