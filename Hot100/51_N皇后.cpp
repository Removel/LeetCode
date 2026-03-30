#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        //参数初始化
        vector<vector<string>> res;
        vector<string> tmpRes(n,string(n,'.'));
        unordered_set<int> col_set;
        unordered_set<int> podiagonal_set;
        unordered_set<int>nediagonal_set;
        int row = 0;
        //调用方法
        dfs(res,tmpRes,col_set,podiagonal_set,nediagonal_set,n,row);
        //返回结果
        return res;
    }

    /*
     * @param res 储存返回结果的容器
     * @param tmpRes 储存每一种结果的容器
     * @param col_set 无序集合，用于标识该列上是否已存在皇后
     * @param podiagonal_set 无序集合，用于标识该正对角线上是否已存在皇后
     * @param nediagonal_set 无序集合，用于标识该反对角线上是否已存在皇后
     * @param n 标识地图大小
     * @param row 标识现在遍历到的皇后（第几个+所在行）
     */

    void dfs(vector<vector<string>>&res,
            vector<string>&tmpRes,
            //因为就是从行开始遍历的，所以逻辑上可以保证不会出现行重复，不需要一个集合来储存行的情况
            unordered_set<int>&col_set,
            unordered_set<int>&podiagonal_set,
            unordered_set<int>&nediagonal_set,
            int &n,
            int row){
        //如果已经到了n个皇后/遍历结束了第n-1行，那么将当前结果存入
        if(row>=n){
            res.push_back(tmpRes);
            return;
        }
        //注意，string本身就是一个数组，因此vector<string>就是一个二维数组，其本身可以通过[pos1][pos2]进行访问对应元素
        for(int col=0;col<n;++col){
            /*
            数学规律：对应每个对角线都符合有：y=x+a||y=-x+a-》y+x=a||y-x=a-》对角线上的行列相加减是一个常数
            那么这样每行对角线就能够通过一个集合表示是否该对角线上已经存在，集合查得到说明有，查不到说明没有
            */
           
            //列上或者两个对角线上存在就跳过
            if(col_set.count(col)||podiagonal_set.count(row+col)||nediagonal_set.count(row-col))continue;
            
            //经典回溯：
            //更新状态
            col_set.emplace(col);
            podiagonal_set.emplace(row+col);
            nediagonal_set.emplace(row-col);
            tmpRes[row][col]='Q';
            //递归调用
            dfs(res,tmpRes,col_set,podiagonal_set,nediagonal_set,n,row+1);
            //回调状态
            col_set.erase(col);
            podiagonal_set.erase(row+col);
            nediagonal_set.erase(row-col);
            tmpRes[row][col]='.';
        }
    }
    
};


int main(){}