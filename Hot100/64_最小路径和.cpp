#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
//这种题目还是比较简单的
    int minPathSum(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();++i){//i对应索引为行
            for(int j=0;j<grid[0].size();++j){//j对应索引为列
                int addFromLeft=INT_MAX;
                int addFromUp=INT_MAX;
                if(i-1>=0)addFromUp=grid[i-1][j];
                if(j-1>=0)addFromLeft=grid[i][j-1];
                if(i-1<0&&j-1<0)continue;
                grid[i][j]+=min(addFromLeft,addFromUp); 
            }
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }
};


int main(){

}