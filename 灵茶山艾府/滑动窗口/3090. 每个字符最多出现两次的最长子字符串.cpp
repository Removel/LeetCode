#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
/*
//有问题，速度比较慢？
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>record;
        int count = 0;
        int l=0,r=0;
        while(r<s.size()){
            //当出现一个字符出现了两次以上的情况的时候我们将左指针移动直到出现次数少于两次
            if(record[s[r]]<2){
                record[s[r]]++;
                count = max(count,r-l+1);
                r++;
            }else{
                while(record[s[r]]>=2){
                    record[s[l]]--;
                    l++;
                }
                count = max(count,r-l);
            }
        }
        return count;
    }
*/
//优化版本
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> record;
        int count = 0;
        int l = 0, r = 0;
        while (r < s.size()) {
            // 先尝试加入 s[r]
            record[s[r]]++;
            
            // 如果加入后 s[r] 超过 2，移动左指针直到满足条件
            while (record[s[r]] > 2) {
                record[s[l]]--;
                l++;
            }
            
            // 此时窗口有效，更新最大长度
            count = max(count, r - l + 1);
            r++;
        }
        return count;
    }
/*
//另一种思路
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>record;
        int count = 0;
        int l=0,r=0;
        while(r<s.size()){
            //当出现一个字符出现了两次以上的情况的时候我们将左指针移动直到出现次数少于两次
            if(record[s[r]]<2){     // 使用 < 2 而不是 <= 2
                record[s[r]]++;
                count = max(count,r-l+1);
                r++;
            }else{
                // 注意：这里应该先检查 record[s[l]]，而不是 record[s[r]]
                record[s[l]]--;
                l++;
            }
        }
        return count;
    }
*/

};