#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
//比较简单：相连的陆地使用深度优先的时候能够使得所有相连的陆地都被检测到，于是乎只需要看使用了几次广度优先即可知道有几个岛屿
    vector<int>di={0,0,-1,1};
    vector<int>dj={-1,1,0,0};
    void DFS(vector <vector <bool>>&isVisited,vector<vector<char>>&grid,int i,int j){
        for(int k=0;k<4;++k){
            if((i+di[k]>=0&&i+di[k]<grid.size())&&(j+dj[k]<grid[0].size()&&j+dj[k]>=0)){//边界检查
                if(!isVisited[i+di[k]][j+dj[k]]&&grid[i+di[k]][j+dj[k]]=='1'){ 
                    isVisited[i+di[k]][j+dj[k]]=true;
                    DFS(isVisited,grid,i+di[k],j+dj[k]);
                }
            }
        }

    }

    int numIslands(vector<vector<char>>& grid) {
    int m=grid.size(),n=grid[0].size();
    vector <vector <bool>>isVisited(m,vector <bool>(n,false));
    int count=0;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(isVisited[i][j])continue;
            else if(!isVisited[i][j]&&grid[i][j]=='0'){
                isVisited[i][j]=true;
            }
            else if(!isVisited[i][j]&&grid[i][j]=='1'){
                isVisited[i][j]=true;                
                DFS(isVisited,grid,i,j);
                count++;
            }
        }
    }
    return count;
    }
};


int main(){

}
