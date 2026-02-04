#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
/*
处理字符串-》类似于数学括号处理。先处理最里面的再往外
*/
    string decodeString(string s) {
        //解题用的栈
        stack<string> rec;
        //使用for遍历s字符串
        for(int i=0;i<s.size();++i){
            //当当前遍历到的元素是"["的时候
            if(s[i] != ']'){
                //使用tmp字符串将一个字符转化为字符串以为了符合栈容器的数据类型要求
                string tmp ;
                tmp =tmp+s[i];
                //记得压栈，压入下一个字符
                rec.push(tmp);
            }
            //当当前遍历到的元素是"]"时，说明出现了一个需要解码的完整的内容
            else {
                string tmp;
                while(rec.top()!="["){
                    //获取到中括号当中的内容
                    tmp=rec.top()+tmp;
                    //记得弹栈，取出下一个字符
                    rec.pop();
                }
                //弹到最后栈顶的字符是"["，弹出
                rec.pop();
                //用string来记录num，复制的数量
                string num;
                //1、栈非空     2、当前栈顶字符是数字
                while(!rec.empty()&&isdigit((rec.top())[0])){
                    //注意数字顺序，加在字符串的左侧，而不是右侧
                    num = rec.top()+num;
                    //加入数字后要弹出该数字
                    rec.pop();
                }
                //依据数字和得到的中括号内的数字进行复制得到当前解码的内容
                string str;
                int cnt = stoi(num);
                while(cnt){
                    str+=tmp;
                    --cnt;
                }
                //将解码得到的字符串压入栈，能将被包括的子串处理完成
                rec.push(str);
            }
        }
        //最后栈中的元素在最外层的同一层级上可能会有多个字符串，即都在栈中，不只有栈顶
        //于是要将其都合在一起：
        string res;
        while(!rec.empty()){
            res=rec.top()+res;
            rec.pop();
        }
        //返回结果
        return res;
    }
};



int main(){

}