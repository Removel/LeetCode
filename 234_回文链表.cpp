#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    bool isPalindrome(ListNode* head) {
    //寻找链表的中心元素，将链表一分为二
    ListNode* slow=head;
    ListNode* fast=head->next;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    //将分出来的两个链表中的右边（slow）进行翻转
    ListNode* second=reverseList(slow->next);
    slow->next=nullptr;
    //对比两部分链表
    ListNode* first=head;
    while(second){
        if(first->val!=second->val){
            return false;
        }
        first=first->next;
        second=second->next;
    }   
    return true;
    }

    ListNode* reverseList(ListNode * head){
    ListNode* pre=nullptr;
    ListNode* cur=head;
    while(cur){
        ListNode* next=cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;
    }
    return pre;
    }
};

int main(){

}