#include <string>
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
/*
//效率过低，时间太长,O(n*k)
    int maxVowels(string s, int k) {
        unordered_set<char>list = {'a','e','i','o','u'};
        int maxSize = 0;
        for(int i=0;i<=s.size()-k;++i){ //这里必须是<=
            string window=s.substr(i,k);
            int count =0;
            for(char ch : window){
                auto it = list.find(ch);
                if(it!=list.end()){
                    count++;
                }
            }
            maxSize=max(maxSize,count);
        }
        return maxSize;
    }
*/
    int maxVowels(string s, int k) {    
        //我们当然可以通过使用五个if判断是否是元音字母，但是那样我认为不够优雅（
        unordered_set<char>list = {'a','e','i','o','u'};
        int maxSize=0;
        //第一轮，初始化窗口
        for(int i=0;i<k;++i){
            if(list.count(s[i]))maxSize++;
        }
        //移动窗口
        int count=maxSize;
        for(int i=k;i<s.size();++i){
            //i向前移动一位
            //如果离开窗口的是元音那么-1
            if(list.count(s[i-k]))count--;
            //如果进入窗口的是元音那么+1
            if(list.count(s[i]))count++;
            //更新值
            maxSize=max(count,maxSize);
        }
        //返回结果
        return maxSize;
    }   

};

