#include <iostream>
using namespace std;

struct ListNode
{
    /* data */
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //基本想法：先遍历一遍a链表，记录遍历到的点的次数为1；再遍历b链表，如果遍历到的点的的次数是1，那么说明有存在的交点，如果遍历到结束都没
    //         有找到那么说明没有交点
    //时间复杂度满足要求O（n+m），但是空间复杂度未达到O（1）的要求，此处空间复杂度为O（n+m）
    //如何优化呢？
    //由于1、不能改变链表节点的结构 2、链表的结点是否为同一个节点与该节点的val值无关，只有规定是相同地址才会是相同节点。 于是：
    //比较a、b链表的长度，将较长的链表先移动到较短的链表的长度，再一起向后移动，比较节点是否相同即可
    //尝试实现;
    /*
    //检测a链表的长度
    ListNode *current=headA;
    int listalen=0;
    while(current!=nullptr){
        listalen++;
        current=current->next;
    //    current->next=current->next;
    } 
    //检测b链表的长度
    int listblen=0;
    current=headB;
    while(current!=nullptr){
        listblen++;
        current=current->next;
    //    current->next=current->next;
    }
    //如果a链表长度大于b链表长度，则将a链表先遍历到剩余与b等长的位置，并且对比的时候看是否符合结果要求
    ListNode *currenta=headA;
    ListNode *currentb=headB;
    if(listalen>=listblen){
        while(listalen>listblen){
            currenta=currenta->next;
            if(currenta==currentb)return currenta;
            listalen--;
        }
    }
    //同上，a与b反过来
    else{
        while(listblen>listalen){
            currentb=currentb->next;
            if(currenta==currentb)return currentb;
            listblen--;
        }
    }
    while(currenta!=nullptr&&currentb!=nullptr){
            if(currenta==currentb)return currenta;
            else{
                currenta=currenta->next;
                currentb=currentb->next;
            }
        }
    return nullptr;
    */
    //能够成功通过但是不够优雅
    //以下是另一种方法实现（官方双指针法）
    //核心：两个指针走过相同长度的路径，最后要么会在同一点相遇要么没有交点
    
    if(!headA||!headB)return nullptr;
    ListNode *p=headA, *q=headB;
    while(p!=q){
        p=p?p->next:headB;
        q=q?q->next:headA;
    }
    return p;
    
    }
};

int main(){

}
