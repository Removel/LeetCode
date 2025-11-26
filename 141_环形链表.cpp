#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        //要求空间复杂度为O（1）
        //快慢指针？如果存在环会导致两者都进入环内，
        //快指针总会追上慢指针
        //快慢指针的初始化有点不够优雅了
        /*
        ListNode *slow=head;
        if(!head)return false;
        ListNode *fast=head->next;
        while(slow&&fast&&fast->next){
            if(slow==fast)return true;
            slow=slow->next;
            fast=fast->next->next;
        }
        return false;
        */
       //更加优雅的写法
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast&&slow&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)return true;
        }
        return false;
    }
};






int main(){

}