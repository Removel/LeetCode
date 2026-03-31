#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count = 0;
        //第一次滑动窗口（初始化）
        for(int i=0;i<k;++i){
            if(blocks[i]=='W')count++;
        }
        //如果第一次滑动窗口就符合条件那么我们直接返回结果
        if(count==0)return 0;
        int res = count;
        for(int i=k;i<blocks.size();++i){
            //如果丢掉的是白色，那么当前窗口需要染色的数量-1，黑色不用管
            if(blocks[i-k]=='W')count--;
            //如果加入的是黑色，那么当前窗口需要染色的数量+1，黑色不用管
            if(blocks[i]=='W')count++;
            //如果当前窗口全是黑色那么直接返回0
            if(count==0)return 0;
            //更新结果
            res = min(count,res);
        }
        return res;
    }
};