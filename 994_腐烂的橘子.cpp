#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int>di={-1,1,0,0};
    vector<int>dj={0,0,-1,1};

    struct Location{
        int row;
        int col;
    };

    int BFS(vector<vector<int>> &isVisited,vector<vector<int>>& grid,vector<Location>badOrange){
        queue<Location> q;
        for(int i=0;i<badOrange.size();++i){
        Location origin;
        origin.row=badOrange[i].row,origin.col=badOrange[i].col;
        q.push(origin);   
        }
        int count=0;
        while(!q.empty()){
            int size=q.size();
            bool addPoint=false;
            //将这一轮遍历到的点提出来，并将下一轮的点加入
            for(int k=0;k<size;++k){
                Location tmp=q.front();
                q.pop();
                // if(grid[tmp.row][tmp.col]==1){
                //     isVisited[tmp.row][tmp.col]=1;
                // }
                //入点
                for(int h=0;h<4;++h){
                    //前提：满足边界条件
                    //如果周围四个点：
                    //1：grid上为2，不加入，因为这个点能到的地方当前点一定能到
                    //2：grid上为1，isVisited为0：加入；isVisited为1：加入；isVisited为2：不加入：
                    //3：grid上为0，跳过
                    int row=tmp.row+di[h],col=tmp.col+dj[h];
                    if((row>=0&&row<grid.size())&&(col>=0&&col<grid[0].size())){
                        if(grid[row][col]==1&&isVisited[row][col]!=2){
                            Location next;
                            next.row=row;
                            next.col=col;
                            q.push(next);
                            isVisited[row][col]=2;
                            addPoint=true;
                        }
                    }
                }
            } 
            //如果加入了点，一轮遍历完之后将count即分钟数自增1
            if(addPoint)count++;
        }
        //将本轮访问过的1在isVisited上设置为被访问过
        for(int k=0;k<grid.size();++k){
            for(int h=0;h<grid[0].size();++h){
                if(isVisited[k][h]==2)isVisited[k][h]=1;
            }
        }
        return count;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector <Location> badOrange;
        //防止没有橘子的情况
        int ans=0;
        //0:未被访问 1：之前被访问 2：本轮被访问
        vector <vector<int>> isVisited(m,vector <int>(n,0));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==2){
                    Location l;
                    l.row=i,l.col=j;
                    badOrange.push_back(l);
                }
            }
        }
        ans=BFS(isVisited,grid,badOrange);
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==1&&isVisited[i][j]==0){
                    return -1;
                }
            }
        }
        return ans;
    }
};



int main(){

}