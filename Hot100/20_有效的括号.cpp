#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack <char> rec;
        for(int i=0;i<s.size();++i){
            //遇到左括号则压栈
            if((s[i]=='(')||(s[i]=='[')||(s[i]=='{')){
                rec.push(s[i]);
                continue;
            }//检查右括号之前先检查是否为空栈
            if (rec.empty())return false;
            //对于右括号，查看栈的顶部元素是否对应，是则弹出，不是则返回false
            else if(s[i]==')'){
                if(rec.top()!='(')return false;
                else rec.pop();
            }
            else if(s[i]==']'){
                if(rec.top()!='[')return false;
                else rec.pop();
            }
            else if(s[i]=='}'){
                if(rec.top()!='{')return false;
                else rec.pop();
            }
        }
        //结束之后若栈不空则说明有左括号没有匹配到，不符合规则，栈空则符合
        if(!rec.empty())return false;
        else return true;
    }
};

int main(){

}