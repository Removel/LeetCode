#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    //声明快慢指针
    ListNode* slow=head;
    ListNode* fast=head;
    //找环
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
        //找到了环之后：
        //1、将慢指针指向head
        //2、两个指针一同向后移动相同的距离直到相等
        //3、返回结果指针
        if(fast==slow){
            slow=head;
            while(fast!=slow){
                fast=fast->next;
                slow=slow->next;
            }
            return fast;
        }
    }
    //找不到环则返回false
    return NULL;    
    }
};

int main(){

}