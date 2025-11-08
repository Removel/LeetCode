#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //使用map会增加时间消耗，在该道题中不需要map自动排序的功能
        unordered_map <string,vector <string> >record;
        int size=strs.size();
        for(int i=0;i<size;++i){
            string key=strs[i];
            //sort不会返回一个值
            sort(key.begin(),key.end());
            record[key].push_back(strs[i]);
        }
        vector<vector <string>>res;
        //此处i应当为!= 因为在迭代器当中常使用不等于，只有特殊的几个才会使用小于等于
        for(auto i=record.begin();i!=record.end();++i){
            res.push_back(i->second);
        }
        return res;
    }

};


int main(){
Solution s;
vector <string> strs;
s.groupAnagrams(strs);



return 0;
}
