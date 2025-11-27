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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
ListNode *ptr1=list1;
ListNode *ptr2=list2;
ListNode *head=new ListNode(0);
ListNode *cur=head;
while(ptr1&&ptr2){
    if(ptr1->val>=ptr2->val){
        cur->next=ptr2;
        cur=cur->next;
        ptr2=ptr2->next;
    }
    else if(ptr1->val<ptr2->val){
        cur->next=ptr1;
        cur=cur->next;
        ptr1=ptr1->next;
    }
}
if(!ptr1){
    while(ptr2){
        cur->next=ptr2;
        ptr2=ptr2->next;
        cur=cur->next;
    }
}
if(!ptr2){
    while(ptr1){
        cur->next=ptr1;
        ptr1=ptr1->next;
        cur=cur->next;
    }
}
ListNode *start=head->next;
delete head;
return start;
}
};




int main(){

}