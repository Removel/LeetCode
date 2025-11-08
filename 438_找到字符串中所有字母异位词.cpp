#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //自己尝试实现,时间复杂度过大，O(n*mlogm)，遂失败
        /*vector <int>res;
        if(s.size()<p.size())return {};
        sort(p.begin(),p.end());
        for(int i=0;i<s.size()-p.size()+1;++i){
            string key=s.substr(i,p.size());
            sort(key.begin(),key.end());
            if(key==p){
                res.push_back(i);
            }
        }
        return res;
        */
        //使用滑动窗口优化版本，即将sort优化为哈希表降低复杂度到O(n*m):
        /*
        if(s.size()<p.size())return {};
        vector <int> res;
        unordered_map<char,int>pchars;
        unordered_map<char,int>windowchars;
        for(int i=0;i<p.size();++i){
            pchars[p[i]]++;
            windowchars[s[i]]++;
        }
        int count=0;
        for(auto i=pchars.begin();i!=pchars.end();++i){
            if(windowchars[i->first]==i->second)count++;
        }
        if(count==pchars.size()){
            res.push_back(0);
        }
        for(int i=0;i<s.size()-p.size()+1;++i){
            count=0;
            windowchars[s[i]]--;
            windowchars[s[i+p.size()]]++;
            for(auto j=pchars.begin();j!=pchars.end();++j){
                if(windowchars[j->first]==j->second)count++;
            }
            if(count==pchars.size())res.push_back(i+1);
        }
        return res;
        //md不够快，艹了
        */
        //官方题解//参考答案：
        if(s.size()<p.size())return {};
        vector <int>res;
        unordered_map<char,int>need_match,window;
        for(char c:p)need_match[c]++;
        int left=0,right=0;
        int match=0;
        while(right<s.size()){
            char c=s[right];
            ++right;
            if(need_match.count(c)){
                window[c]++;
                if(window[c]==need_match[c]){
                    ++match;
                }
            }
            while(right-left==p.size()){
                if(match==need_match.size()){
                    res.push_back(left);
                }
                char l=s[left];
                ++left;
                if(need_match.count(l)){
                    if(window[l]==need_match[l]){
                        --match;
                    }
                    window[l]--;
                }
            }
        }
        return res;

    }
};




int main(){
Solution s;
string str1="cbaebabacd";
string str2="abc";
vector <int> res=s.findAnagrams(str1,str2);
for(int i=0;i<res.size();++i){
cout<<res[i]<<" ";
}
return 0;
}