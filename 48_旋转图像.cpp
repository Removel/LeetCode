#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    //矩阵转置
    for(int i=0;i<matrix.size();++i){
        for(int j=0;j<=i;++j){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    //矩阵在列上倒置
    for(int i=0;i<matrix.size();++i){
        for(int j=0;j<matrix[0].size()/2;++j){
            swap(matrix[i][j],matrix[i][matrix[0].size()-j-1]);
        }
    }    
    }
};






int main(){

}


