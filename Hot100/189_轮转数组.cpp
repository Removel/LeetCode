#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    //Function1:数学计算的方式：移动后的位置=（原来位置+实际移动的长度）%k
    //时间复杂度=空间复杂度=O(n),不是最优解法
    /*
    vector <int> newnums=nums;
    for(int i=0;i<nums.size();++i){
        nums[(i+k)%nums.size()]= newnums[i];
    }
    */
    //Function2:原地轮转，空间复杂度下降至O（1）
    k=k%nums.size();
    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+k-1);
    reverse(nums.begin()+k,nums.end());
    }
};

int main(){
    int []arr=new int []{1,2,3,4,5};
}