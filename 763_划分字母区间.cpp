#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    //方法一：找区间（第一次与最后一次出现位置）+合并区间
    //略微繁杂
    /*
    vector<int> partitionLabels(string s) {
        unordered_map<char , vector<int>>rec;
        vector<vector<int>> newRec = findLoc(s,rec);
        vector<int>ans = merge(newRec);
        return ans;
    }

    vector<vector<int>> findLoc(string &s, unordered_map<char,vector<int>>&rec){
        //记录位置
        for(int i=0;i<s.size();++i){
            char c = s[i];
            if(!rec.count(c)){
                rec[c].push_back(i);
                rec[c].push_back(i);
            }
            else rec[c][1]=i;
        }
        //处理为数字数组
        vector<vector<int>> newRec;
        for(auto i = rec.begin();i!=rec.end();++i){
            newRec.push_back(i->second);
        }
        //返回结果
        return newRec;
    }

    //合并区间（更详细见56）
    vector<int> merge(vector<vector<int>> &newRec){
        //如果当前区间没有或者只有一个，那么就直接返回对应结果
        vector<int> ans;
        if(newRec.size()<2){
            ans.push_back(newRec.size());
            return ans;
        }
        //使用lambda表达式对区间排序：规则是左区间小的往前，大的往后，从小到大
        sort(newRec.begin(),newRec.end(),[](const vector <int>&newRec1,const vector <int >&newRec2){return newRec1[0]<newRec2[0];});
        //对应设定暂定值
        int tmpStart = newRec[0][0];
        int tmpEnd = newRec[0][1];
        for(int i=0;i<newRec.size();++i){
            //如果当前暂定区间的右边界大于当前遍历到的区间的左边界，说明二者有交集，需要判断谁的右边界在更后面
            //比如以下示例：
            //【   {    】    }
            //【   {   }】
            if(newRec[i][0]<=tmpEnd){
                tmpEnd=max(newRec[i][1],tmpEnd);
            }
            //否则说明当前无交集，一段区间合并完成
            //加入结果，更新边界
            else {
                ans.push_back(tmpEnd-tmpStart+1);
                tmpStart=newRec[i][0];
                tmpEnd=newRec[i][1];
            }
        }
        //处理完后最后一个尚未加入，将其加入即可
        ans.push_back(tmpEnd-tmpStart+1);
        return ans;
    }
    */
    /*
    //方法二,更直观
    vector<int> partitionLabels(string s) {
        if(s.size()<2)return {(int)s.size()};
        //记录字母右边界，即最后一次出现的位置
        unordered_map<char , int>rec;
        for(int i=s.size()-1;i>=0;--i){
            char c = s[i];
            if(!rec.count(c)){
                rec[c]=i;
            }
        }
        //记录该位置上的字母最后出现的位置
        vector<int>right(s.size(),-1);
        for(int i=0;i<right.size();++i){
            right[i]=rec[s[i]];
        }
        //新数组，该位置上的元素是 字符串中该索引位置上字母最后出现的位置 与 数组前一个元素的字母最后出现的位置 的 最大值
        vector<int>max_right(s.size(),-1);
        max_right[0]=right[0];
        for(int i=1;i<right.size();++i){
            max_right[i]=max(max_right[i-1],right[i]);
        }
        //与原来的位置比较，如果数组当前位置上的元素恰好是该索引大小那么分割
        vector<int>res;
        //用于记录
        int length = 0;
        for(int i=0;i<right.size();++i){
            length++;
            if(max_right[i]==i){
                res.push_back(length);
                length=0;
            }
        }
        return res;
    }
    */
    //方法二优化版本
    vector<int> partitionLabels(string s){
        //容器初始化
        vector<int> res;
        unordered_map<char,int> record;
        //记录每种字母的最后出现位置
        for(int i=0;i<s.size();++i){
            record[s[i]]=i;
        }
        //初始化长度计数器和当前最大右边界
        int length=0;
        int max_right = 0;
        for(int i=0;i<s.size();++i){
            length++;
            //更新右边界
            max_right=max(max_right,record[s[i]]);
            //如果右边界更新完之后等于当前索引说明当前为分割点
            if(max_right==i){
                //将长度计数结果加入结果
                res.push_back(length);
                //长度计数归零
                length=0;
            }
        }
        return res;
    }
};

int main(){}