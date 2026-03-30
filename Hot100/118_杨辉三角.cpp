#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector <int> getline(int num){
        //第n行（从零开始）有n+1个元素
        vector<int> row(num+1,1);
        for(int k=1 ; k<=num;++k){
        // 利用公式 C(n,k) = C(n,k-1) * (n-k+1) / k
            row[k]=row[k-1]*(num-k+1)/k;
        // 对称赋值（一行中有一半的元素是相同的）
            row[num-k]=row[k];
        }
        return row;
    }

    vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    for(int i=0;i<numRows;++i){
        ans.push_back(getline(i));
    }    
    return ans;
    }
};





int main(){

}