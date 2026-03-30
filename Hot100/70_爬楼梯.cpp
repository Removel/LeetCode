#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int pre1=1,pre2=1;
        int ans;
        if(n==1||n==2)return 1;
        else {
            for(int i=3;i<n;++i){
                ans=pre1+pre2;
                pre1=pre2;
                pre2=ans;
            }
        }
    return ans;
    }
};





int main(){

}