#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>record;
        int left = 0;
        int maxNum = 0;
        for(int right=0;right<fruits.size();++right){
            //尝试加入
            record[fruits[right]]++;
            //更新维护哈希表
            while(record.size()>2){
                record[fruits[left]]--;
                //为零的要记得删掉对应的key保证哈希表大小减小
                if(record[fruits[left]]==0){
                    record.erase(fruits[left]);
                }
                left++;
            }
            maxNum = max(maxNum,right-left+1);
        }
        return maxNum;
    }
};