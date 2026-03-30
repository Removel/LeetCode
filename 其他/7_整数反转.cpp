#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

//问题：函数名已经是reverse不可以使用algorithm的reverse函数进行导致
//需要别的方法进行倒置
/*
class Solution {
public:
    int reverse(int x) {
        if(x==0){return 0;}
        else if(x<0){
            string substr=to_string(-x);
            reverse(substr.begin(),substr.end());
            while(substr[0]==0){
                substr.erase(0,1);
            }
            int res=stoi(substr);            
            return -res;
        }
        else {
            string substr=to_string(x);
            reverse(substr.begin(),substr.end());
            while(substr[0]==0){
                substr.erase(0,1);
            }
            int res=stoi(substr);            
            return res;
        }
    }
};
*/
class Solution {
public:
    int reverse(int x) {
        int res;
        if(x==0)return 0;
        while(x!=0){
           int digit=x%10;
            // 检查正数溢出：rev > INT_MAX/10 或 (rev == INT_MAX/10 且 digit > 7)
           if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) {
                return 0;
            }  
            // 检查负数溢出：rev < INT_MIN/10 或 (rev == INT_MIN/10 且 digit < -8)
            if (res < INT_MIN / 10 || (res== INT_MIN / 10 && digit < -8)) {
                //cout<<res<<" "<<digit<<endl;
                return 0;
            }
           res=res*10+(x%10);        
           x=x/10;
        }
    return res;
    }
};

int main(){
    Solution s;
    int num;
    cin>>num;
    cout<<s.reverse(num);
    return 0;
}