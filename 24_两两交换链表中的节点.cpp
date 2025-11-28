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
    ListNode* swapPairs(ListNode* head) {
    ListNode *dummy=new ListNode(0,head);
    ListNode *pre=dummy;
    ListNode *cur=dummy->next;
    while(cur&&cur->next){//特性：如果cur真假值为假，那么不会再看第二个cur->next，防止了空指针错误
        //进行交换
        ListNode *rev=cur->next;
        cur->next=rev->next;
        pre->next=rev;
        rev->next=cur;
        //移动指针
        pre=cur;
        cur=cur->next;
    }
    return dummy->next;
    }
};

int main(){

}