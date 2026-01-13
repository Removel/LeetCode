#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
    // }
/*
//暴力查找法：
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[i].size();++j){
                if(matrix[i][j]==target)return true;
            }
        }
    return false;
    }
    //时间复杂度O（n*m）
*/

/*
//双二分查找法：
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int findrowl=0,findrowr=matrix.size()-1;
    int locrow=0;
    while(findrowl<=findrowr){
        int mid=(findrowl+findrowr)/2;
        if(matrix[mid][0]==target)return true;
        else if(matrix[mid][0]<target)findrowl=mid+1;
        else if(matrix[mid][0]>target)findrowr=mid-1;
    }

    if(findrowr<0)return false;
    else locrow=findrowr;

    int findcoll=0,findcolr=matrix[locrow].size()-1;
    int loccol=0;
    while(findcoll<=findcolr){
        int mid=(findcoll+findcolr)/2;
        if(matrix[locrow][mid]==target)return true;
        else if(matrix[locrow][mid]<target)findcoll=mid+1;
        else if(matrix[locrow][mid]>target)findcolr=mid-1;
    }
    return false;
    }
    //时间复杂度O（logm+logn）
*/

//单二分查找法
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();//n为行数，m为列数
        int l=0,r=n*m-1;//由于矩阵特性，将二维矩阵-》一维矩阵
        while(l<=r){
            int mid=(l+r)/2;
            int col=mid%m,row=mid/m;//对应映射关系，一维索引对应二维索引
            if(matrix[row][col]>target)r=mid-1;
            else if(matrix[row][col]<target)l=mid+1;
            if(matrix[row][col]==target)return true;
        }
        return false;
    }
    //时间复杂度O（logmn）


/*
    //动态边界法
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0,col=matrix[0].size()-1;
        while(row<matrix.size()&&col>=0){
            if(matrix[row][col]<target)row++;
            else if(matrix[row][col]>target)col--;
            else if(matrix[row][col]==target)return true;
        }
        return false;
    }
    //时间复杂度O（m+n）

*/
};


int main(){

}