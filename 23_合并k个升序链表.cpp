#include <iostream>
#include <vector>
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
//使用一个一个合并，总共需要合并K次，时间复杂度为O(n*k)
//在这里使用两个两个合并，总共需要合并logk次，时间复杂度为O(n*logk)
//在这里的时间复杂度和堆优先队列类似
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //合并K个有序链表，使用分治的思想，每次合并两个链表，直到最后只剩一个链表
        //如果链表为空，直接返回NULL
        if(lists.empty())return NULL;
        //合并直到只剩下一个链表
        while(lists.size()>1){
            //暂存的本轮合并后链表头列表
            vector<ListNode*> tmpLists;
            //注意是+=2
            for(int i=0;i<lists.size();i+=2){
                //防止空指针异常，先将head2置空
                ListNode* head1 = lists[i];
                ListNode* head2 = NULL;
                //如果head2存在，才将head2置为lists[i+1]
                if(i+1<lists.size()){
                    head2=lists[i+1];
                }
                //合并并将合并后的链表头加入tmpLists
                tmpLists.push_back(mergeTwoList(head1,head2));
            }
            //更新列表
            lists=tmpLists;
        }
        //最后返回合并后的链表头
        return lists[0];
    }

    //合并两个有序链表
    ListNode* mergeTwoList(ListNode* head1,ListNode* head2){
        ListNode* dummy = new ListNode(0);
        ListNode* ptr1 = head1;
        ListNode* ptr2 = head2;
        ListNode* cur = dummy;
        //两个归并
        while(ptr1&&ptr2){
            //注意：1、要使用if-else if，不能使用if-if
            //      2、是cur->next=ptr2，而不是cur=ptr2，因为cur是用来遍历合并后的链表的，
            //         如果cur=ptr2，那么cur就指向了ptr2了，后续的cur->next就会出问题了
            if(ptr1->val>=ptr2->val){
                cur->next = ptr2;
                cur=cur->next;
                ptr2=ptr2->next;
            }
            else if(ptr1->val<ptr2->val){
                cur->next=ptr1;
                cur=cur->next;
                ptr1=ptr1->next;
            }
        }
        //归并剩一个，另一个直接接上
        if(!ptr1){
            while(ptr2){
                cur->next=ptr2;
                cur=cur->next;
                ptr2=ptr2->next;
            }
        }
        if(!ptr2){
            while(ptr1){
                cur->next=ptr1;
                cur=cur->next;
                ptr1=ptr1->next;
            }
        }
        //返回合并后的链表头
        //注意这里不能用cur=dummy->next，因为cur已经指向了合并后的链表的最后一个节点了
        ListNode* start = dummy->next;
        //删除dummy节点，防止内存泄漏
        delete dummy;
        //返回合并后链表表头
        return start;
    }

};


int main(){

}