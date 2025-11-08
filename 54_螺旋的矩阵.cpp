#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    //时时更新上下左右边界，并在一边输出过后检查边界是否达到了停止条件
    int left=0,right=matrix[0].size();
    int top=0,bottom=matrix.size();
    vector <int> res;
    while(left<right&&top<bottom){
        //从左上到右上
        for(int i=left;i<right;++i){
            res.push_back(matrix[top][i]);
        }
        ++top;
        if(top>=bottom)break;
        //从右上到右下
        for(int i=top;i<bottom;++i){
            res.push_back(matrix[i][right-1]);
        }
        --right;
        if(left>=right){
            break;
        }
        //从右下到左下
        for(int i=right-1;i>=left;--i){
            res.push_back(matrix[bottom-1][i]);
        }
        --bottom;
        if(top>=bottom)break;
        //从左下到右上
        for(int i=bottom-1;i>=top;--i){
            res.push_back(matrix[i][left]);
        }
        ++left;
    }   
    return res;
    }
};





int main(){

}