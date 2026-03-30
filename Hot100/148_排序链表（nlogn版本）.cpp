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
    //byd常数级别的空间复杂度做不到啊，太弱小了qwq
public:
    ListNode* sortList(ListNode* head) {
    //防止只有一个或者为空的情况
    if(!head||!head->next)return head;
    //快慢指针分表 
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast&&fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    //标定表一、表二
    ListNode* first = head;
    ListNode* second = slow->next;
    slow->next=nullptr;
    //使用递归实现归并分表
    first=sortList(first);
    second=sortList(second);
    //return的值起归并作用
    return mergeList(first,second);
    }

    ListNode* mergeList(ListNode* first ,ListNode* second){
        ListNode* dummy = new ListNode(0);
        ListNode* cur=dummy;
        //这里是&& 不是 || 
        while(first&&second){
            //写成<=就是降序（从大到小），写成>=就是升序（从小到大）
            if(first->val<=second->val){
                cur->next=first;
                first=first->next;
            }
            else {
                cur->next=second;
                second=second->next;
            }
            cur=cur->next;
        }
        //由于分表方式使得左右两表最多相差一个节点
        //在上述归并结束之后最多产生一个节点没进去，只可能出现要么左空右1，要么左1右空
        if(first){
            cur->next=first;
        }
        else cur->next = second;
        return dummy->next;
    }
};




int main(){

}

