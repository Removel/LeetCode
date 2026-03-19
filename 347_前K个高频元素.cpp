#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
/*
    //等通知写法：自定义最小堆排序，维护最小堆
    //时间复杂度：O(nlogn)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>rec;
        //1、扫描记录各个数字出现次数
        for(int num:nums){
            rec[num]++;
        }
        //2、使用大小为k的最小堆维护出现频率前k高的元素
        auto cmp = [&rec](int a, int b) {
        return rec[a] > rec[b]; // 注意：greater逻辑，返回true表示a应排在b后面
        };
        priority_queue<int, vector<int>, decltype(cmp)> minHeap(cmp);
        //2.1、先将k个加入到堆中，记录的是索引不是次数
        int count = 0;
        auto i=rec.begin();
        for(i;i!=rec.end();++i){
            if(count<k){
                minHeap.push(i->first);
                count++;  
            }else break;
        }
        //2.2、将剩下的元素尝试加入，如果次数比堆顶元素出现次数多则先弹出原来的再加入，次数少就跳过
        for(i;i!=rec.end();++i){
            if(rec[i->first]>rec[minHeap.top()]){
                minHeap.pop();
                minHeap.push(i->first);
            }
        }
        //3、遍历堆输出结果
        vector<int> ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top());
            minHeap.pop();
        }
        return ans;
    }
*/
    //桶排序方法，时间复杂度为O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //统计相关数字出现次数
        unordered_map<int, int> rec;
        for(int num : nums){
            rec[num]++;
        }
        //创建桶，将出现次数作为索引，元素为一个一维数组，一维数组中记录数字
        vector<vector<int>>buckets(nums.size()+1);
        for(auto i=rec.begin();i!=rec.end();++i){
            buckets[i->second].push_back(i->first);
        }
        //将桶倒序添加k个元素到结果当中
        vector<int>ans;
        for(int i=nums.size();i>=0;--i){
            for(int j=buckets[i].size()-1;j>=0;--j){
                ans.push_back(buckets[i][j]);
                //如果已经够了那么直接返回
                if(ans.size()==k){
                    return ans;
                } 
            }
        }
        //防止报错
        return ans;
    }
};


int main(){}