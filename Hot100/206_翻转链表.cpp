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

struct ListNode
{
    /* data */
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};




class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    //迭代法
    /*
    ListNode *preNode=nullptr;
    ListNode *currentNode=head;
    ListNode *nextNode = nullptr; 
    while(currentNode!=nullptr){
        //先记录下一个节点
        nextNode=currentNode->next;
        //将当前节点next指针指向上一个节点
        currentNode->next=preNode;
        //移动pre节点到当前节点
        preNode=currentNode;
        //将当前节点移动到下一个节点
        currentNode=nextNode;
    }  
    return preNode;
    */
    //递归法
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    
    return newHead;

}
};






int main(){

}