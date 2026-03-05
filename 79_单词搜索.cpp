#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        //获取二维数组的信息：行列数
        int rows = board.size();
        int cols = board[0].size();
        //初始化标记二维数组
        vector<vector<bool>>isVisited(rows,vector<bool>(cols,false));
        //对每一个元素进行dfs，得到一个结果
        for(int row=0;row<rows;++row){
            for(int col=0;col<cols;++col){
                //有一个成功就说明找得到
                if(dfs(board,word,0,row,col,isVisited)){
                    return true;
                }
            }
        }
        //说明整个数组都找不到
        return false;
    }

    //具体的dfs方法实现
    /*
    * @ param board 要寻找的二维数组
    * @ param word 要寻找的字符串
    * @ param index 当前要找的字符的索引
    * @ param row 当前元素所在行
    * @ param col 当前元素所在列
    * @ param isVisited 用于辅助判断当前元素在本轮dfs中是否已经访问过了
    * @ return 以当前元素进行dfs的结果
    */
    bool dfs(vector<vector<char>>& board, string &word,int index,int row,int col,vector<vector<bool>>&isVisited){
        //截止条件
        if(index == word.size() )return true;
        int rows = board.size();
        int cols = board[0].size();
        //精妙：使用index标记当前寻找到的位置而不是使用.find()
        //停止条件：1、越界 2、dfs到的该元素已经访问过 3、dfs到的该元素不符合要求
        if(row >= rows || row < 0||col >= cols||col <0 ||isVisited[row][col]||board[row][col]!=word[index]){
            return false;
        }
        //标记
        isVisited[row][col] = true;
        //提前声明结果，预设为false
        bool res = false;
        // |= ：即res = res || xxx
        //分别对应四个方向：
        res |= dfs(board,word,index+1,row+1,col,isVisited);
        res |= dfs(board,word,index+1,row-1,col,isVisited);
        res |= dfs(board,word,index+1,row,col+1,isVisited);
        res |= dfs(board,word,index+1,row,col-1,isVisited);
        //精妙：将标记用二维数组在递归中自己就重置了，不需要额外重置
        //回溯体现？方便下一轮
        isVisited[row][col] = false;
        return res;
    }

};

int main(){}