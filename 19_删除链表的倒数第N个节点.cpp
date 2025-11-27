#include <iostream>
using namespace std;


 // Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    //常规做法：遍历一遍链表得到链表的长度后使用两个指针
    //一个指向删除节点的前一个节点一个指向删除节点的后一个节点，再将两个节点相连即可
    //题目要求只遍历一次，然而上述方法会将链表遍历两次
    //创建一个在head之前的虚拟节点
    //创建距离为n的两个指针，共同向后移动直到有一个到链表尾部
    //此时前一个的指针的下一个节点即为要删除的节点
    ListNode * l;
    ListNode * r;
    ListNode *dummy=new ListNode(0,head);
    l=dummy;
    r=head;
    while(n&&r){
        r=r->next;
        n--;
    }
    while(r){
        r=r->next;
        l=l->next;
    }
    l->next=l->next->next;
    // delete dummy;
    return dummy->next;
    }
};


int main(){

}