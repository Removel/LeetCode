#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        //由于是子字符串而不是子字符序列，所以保证转化的字符串连续
        int maxLen = 0;
        int left = 0;
        int nowCost = 0;
        for(int right=0;right<s.size();++right){
            nowCost+=abs(s[right]-t[right]);
            while(nowCost>maxCost){
                nowCost-=abs(s[left]-t[left]);
                left++;
            }
            maxLen = max(maxLen,right-left+1);
        }
        return maxLen;
    }
};
