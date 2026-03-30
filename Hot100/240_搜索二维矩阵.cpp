#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //非常显然的是这道题最慢的速度是O（mn）
    /*
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(matrix[i][j]==target)return true;
        }
    }
    return false;
    */
    //该如何优化呢？可以尝试在每一行进行二分查找，这样的时间复杂度能够下降到O（mlogn），但是好像依旧不够快
    /*
    for(int i=0;i<matrix.size();++i){
    int l=0,r=matrix[0].size();    
    while(l<r){
        if(matrix[i][l]==target||matrix[i][r]==target)return true;
        int mid=(l+r)/2;
        if(mid==target)return true;
        else if(mid>target)r=mid-1;
        else if(mid<target)l=mid+1;
    }
    }
    return false;
    */
    //还有方法能够下降时间复杂度吗？
    //有的兄弟，有的：对于该矩阵的上下、左右的有序特性，
    //在反L(就是离散数学类似非的符号)的位置上满足单调递减序列
    //只需要在转折点上分析其与target的大小即可
    //比target大：说明该target不可能在该列上，向左移动反L
    //比target小：说明target不可能在该行上，向下移动反L
    //直到找到或者到达左下角位置为止
    //该方法的时间复杂度为O(m+n)
    //还是运用到了动态边界类似的思维逻辑
    int row=0,col=matrix[0].size()-1;
    while(row<matrix.size()&&col>=0){
        if(matrix[row][col]==target)return true;
        else if(matrix[row][col]>target)col--;
        else if(matrix[row][col]<target)row++;
    }
    return false;
    }
};





int main(){

}