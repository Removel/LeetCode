#include <stack>
#include <iostream>
using namespace std;

class MinStack {
private:
//之前苦恼于思考如何在栈内知道最小值排序的顺序，经过提醒使用两个栈之后这个问题解决了
//一个用于记录最小值，栈的数据结构就代表了它的顺序，一个用于记录所有数字，维护两个栈即可
//使用两个栈
    stack<int> recordMin;
    stack<int> recordAll;
public:

    MinStack() {
        stack<int> recordMin;
        stack<int> recordAll;
    }
    
    void push(int val) {
        if(recordMin.empty()||val<=recordMin.top()){
            recordMin.push(val);
        }
        recordAll.push(val);
    }
    
    void pop() {
        if(recordAll.top()==recordMin.top()){
            recordAll.pop();
            recordMin.pop();
        }else recordAll.pop();
    }
    
    int top() {
        return recordAll.top();
    }
    
    int getMin() {
        return recordMin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){

}