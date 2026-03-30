#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
这道题我们不需要去关注如何才能拼凑出来这个单词，
而是需要关注组成该单词的从某个位置开始的前缀是否能在给定的词组中找得到

于是这道题也是一种动态规划：
使用dp[i]（bool）类型的数组记录从开始到这个位置是否存在于词组当中即可
而在dp[i+？]能找得到的前提就是在已经找到的dp[i]的地方加上词组中的某个词和当前的子串一样

于是有：
一、递推公式：（在满足上述条件的前提下）
dp[i+word.size()]=dp[i];

二、初始化条件：
1、bool类型的dp数组（记录是否有效子串）
2、dp[0]=true;

三、遍历与判断条件：
1、s字符串需要遍历一遍
2、在遍历s字符串的时候把wordDict都试一遍
3、判断条件：dp[i]=true                      //(already exist)
            dp[i]+word.size()<=s.size()     //(new string must not be longger than s)
            word==s.substr(i,word.size())   //(word must exist in correct place)

四、返回结果：
返回如代码所示            
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(s.size()+1,false);
        dp[0]=true;
        for(int i=0;i<s.size();++i){
            for(auto& word : wordDict){
                if(dp[i]&&(i+word.size()<=s.size())&&(word==s.substr(i,word.length()))){
                    dp[i+word.size()]=dp[i];
                }
        }
       } 
       return dp[s.size()];
    }
};

int main(){

}