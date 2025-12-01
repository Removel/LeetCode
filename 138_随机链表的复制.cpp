#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //太弱小了，写不好啊qwq~~~~
        //时间复杂度O（n），空间复杂度为O（1）
        //以下是自己的写法：
        if(!head)return NULL;
        Node *dummy= new Node(0);
        //插入复制的节点
        Node *cur=head;
        while(cur){
            Node *copy=new Node(cur->val);
            copy->next=cur->next;
            cur->next=copy;
            cur=cur->next->next;
        }
        //调整节点的random指针
        cur=head;
        dummy->next=cur->next;
        while(cur){
            if(cur->random){
                cur->next->random=cur->random->next;
            }
            cur=cur->next->next;
        }
        //调整节点的next指针
        cur=head;
        while(cur&&cur->next){
            Node *nxt=cur->next;
            cur->next=cur->next->next;
            cur=nxt;
        }
        return dummy->next;
        
        /*
        //以下是使用哈希表的方法进行深拷贝：
        //时间复杂度O(n),空间复杂度O(n)
        unordered_map<Node*,Node*> deepcpy;
        Node *cur=head;
        while(cur){
            Node *cpy=new Node(cur->val);
            deepcpy[cur]=cpy;
            cur=cur->next;
        }
        cur=head;
        while(cur){
            deepcpy[cur]->next=deepcpy[cur->next];
            deepcpy[cur]->random=deepcpy[cur->random];
            cur=cur->next;
        }
        return deepcpy[head];
        //md怎么好像还没上面快
        */
    }
};

int main(){

}