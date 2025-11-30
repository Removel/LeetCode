#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    //创建虚拟头节点
    ListNode *dummy=new ListNode(0,head);
    //创建组内倒置的开头结点指针
    ListNode *groupPre=dummy;
    while(true){
        //移动cur节点使得找到组内倒置的末尾节点
        ListNode* cur=groupPre;
        int kth=k;
        while(kth>0&&cur){
            kth--;         
            cur=cur->next;
        }
        //如果cur为空说明分组倒置结束
        if(!cur){
            break;
        }
        //开始倒置节点：
        ListNode* groupNxt=cur->next;//确定cur->next的节点为组内倒置节点的末尾节点
        ListNode* pre=groupNxt;//从nxt开始，使用pre记录上一个节点
        cur=groupPre->next;//将cur节点设置为组内倒置开始前的开始节点的下一个节点，也就是真正开始倒置的节点
        ListNode *tmp=NULL;//记录下一个倒置的节点
        while(cur != groupNxt){//倒置结束条件：cur到达groupnxt
            tmp=cur->next;//记录下一个倒置的节点
            cur->next=pre;//将cur的下一个节点设置为pre节点
            pre=cur;//将cur所在的节点设置为下一个pre节点
            cur=tmp;//移动cur节点到暂存的tmp节点，即下一个将要倒置的节点
        }
        tmp=groupPre->next;//这时候groupPre->next指向的是到之后的最后一个节点，使用tmp暂存以便后来groupPre移动
        groupPre->next=pre;//由于原来倒置后导致grouppre仍指向倒置后最后一个节点，这时候pre指向的是倒置后的第一个节点，修改指向
        groupPre = tmp;//移动groupPre指针到下一组开始前的位置
    }
    return dummy->next;
    }

};

int main(){

}