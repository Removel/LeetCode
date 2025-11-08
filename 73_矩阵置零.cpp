#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    /*
    //自己想法：遍历数组找到所有的0，记录遍历到的0的行和列
    //记录完之后对所有记录的行和列进行遍历置零
    //时间复杂度为O（nm），空间复杂度为O（？）
    int m=matrix.size();//行数
    int n=matrix[0].size();//列数
    vector <vector <int>> recRowandColumn;
    for(int i=0;i<matrix.size();++i){
        for(int j=0;j<matrix[i].size();++j){
            //rec记录先行后列
            if(matrix[i][j]==0)recRowandColumn.push_back({i,j});
        }
    }
    for(int i=0;i<recRowandColumn.size();++i){
        //对当前遍历到的记录对行置零：
        for(int j=0;j<n;++j){
            matrix[recRowandColumn[i][0]][j]=0;
        }
        //对当前遍历到的记录对列置零：
        for(int j=0;j<m;++j){
            matrix[j][recRowandColumn[i][1]]=0;
        }
    }
    */
    //对于以上代码肯定是有问题的，不是最优解法
    //优化版本：使用两个数组记录行和列，只要该行/列出现过0，则代表该行/列全为0
    //但是这样空间复杂度依旧比较高
    //进一步优化：使用到原数组的第一行和第一列，在遍历过程中只要出现过0就将该行或者该列对应的位置修改为0
    //最后根据行列进行修改
    //注意：第一行第一列的交点会被使用到两次，使用另一个单独变量记录该点即可
    //空间复杂度下降至O（1）
    int recrow1=1;
    for(int i=0;i<matrix.size();++i){
        for(int j=0;j<matrix[i].size();++j){
            if(matrix[i][j]==0){
                //在第一行上有元素等于0
                if(i==0)recrow1=0,matrix[0][j]=0;
                //其他情况
                else matrix[i][0]=0,matrix[0][j]=0;
            }
        }
    }
    //对行进行置零,先不管第一行
    for(int i=1;i<matrix.size();++i){
        if(matrix[i][0]==0){
            for(int j=1;j<matrix[0].size();++j){
                matrix[i][j]=0;
            } 
        }
    }
    //对列进行置零
    for(int i=0;i<matrix[0].size();++i){
        if(matrix[0][i]==0){
        for(int j=1;j<matrix.size();++j){
            matrix[j][i]=0;    
            }
        }
    }
    //第一行
    if(recrow1==0){
        for(int i=0;i<matrix[0].size();++i){
            matrix[0][i]=0;
        }
    }
    
    }
};


int main(){

}

