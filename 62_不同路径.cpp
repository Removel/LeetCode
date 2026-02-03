#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /*
    //数学问题这一块：机器人想要到达终点，从起点开始终将走到终点需要在边上分别走过m-1，n-1的距离
    //机器人一定会走m+n-2步，即从m+n-2中挑出m-1步向下走
    //于是最终的总共的方法数量是一种组合公式C（（m+n-2），（m-1））,使用cmath的tgamma函数得到阶乘
    //但是直接带入计算，数字大小会爆:
    int uniquePaths(int m, int n) {    
        unsigned long long a = (unsigned long long)tgamma(n + m-1)/(unsigned long long)tgamma(n);
        a=a/(unsigned long long)tgamma(m);
        return (int)a;
    }
    */
    //可以发现在地图上，每个格子的到达数量=左+上 的到达数量，其似乎在每个45°斜线上遵循杨辉三角的规律
    //无需多言
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,1));
        for(int i=1;i<n;++i){//i对应列的索引
            for(int j=1;j<m;++j){//j对应行的索引
                dp[j][i]=dp[j-1][i]+dp[j][i-1];
            }
        }
        return dp[m-1][n-1];
    }
};

 int main(){

}