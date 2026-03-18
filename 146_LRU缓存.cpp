#include <iostream>
#include <unordered_map>
using namespace std;

//双向链表定义
class Node {
public:    
    int key;
    int val;
    Node* pre;
    Node* next;

    //构造函数
    Node(int k,int v){
        key=k;
        val=v;
        pre = NULL;
        next = NULL;
    }
};


class LRUCache {
public:
    //用于查询
    unordered_map<int ,Node*> u_map;
    //记录大小
    int cap ;
    //方便头尾节点处理
    Node* head;
    Node* tail;

    //构造函数
    LRUCache(int capacity) {
        cap=capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        //初始将双向链表头尾相连
        head->next = tail;
        tail->pre = head;
    }
    
    //规则：如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
    int get(int key) {
        //当前关键字存在
        if(u_map.count(key)){
            //维护步骤：
            //1、将双向链表当中的节点移动出去
            remove(u_map[key]);
            //2、再将该节点从头插入
            headInsert(u_map[key]);
            //查询步骤：
            //返回结果            
            return u_map[key]->val;
        }
        //没有则返回-1
        return -1;
    }
    
    //规则: 如果关键字 key 已经存在，则变更其数据值 value ；
    //      如果不存在，则向缓存中插入该组 key-value 。
    //      如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
    void put(int key, int value) {
        /*
        一、key存在：
            1、更新节点在双向链表当中的位置
            2、在哈希表中更新节点的值
        二、key不存在：
            1、创建新节点（key，val）
            2、将该节点头插入双向链表
            3、在哈希表当中记录该节点的key，node值    

        从以上步骤我们可以发现，key不存在时的操作≈key存在时更新的操作
        于是只需要判断哈希表当中是否已经存在了key值，如果有则删除key对应节点和在哈希表当中的key
        然后重新创建-》插入-》记录
        */
        //判断是否已经存在与双向链表当中
        if(u_map.count(key)){
            //将节点从表中分离
            remove(u_map[key]);
            //删除该节点
            delete u_map[key];
            //将哈希表对应记录设置为空
            u_map[key]=NULL;
        }
        //创建新节点
        Node* newNode = new Node(key,value);
        //头插入新节点
        headInsert(newNode);
        //哈希表更新/添加记录
        u_map[key]=newNode;
        //如果大小超过了那么将最后一个节点删除
        if(u_map.size()>cap){
            Node* node = tail->pre;
            remove(tail->pre);
            //注意这里要先擦除记录再删除节点
            u_map.erase(node->key);
            delete node;
        }
    }

    //辅助函数：将给定节点从双向链表中分离
    void remove(Node* node){
        Node* tmpPre = node->pre;
        Node* tmpNext = node -> next;
        tmpPre->next = tmpNext;
        tmpNext->pre = tmpPre;
    }

    //辅助函数：将给定节点头插入链表
    void headInsert(Node* node){
        Node* oldFirstNode = head->next;
        head->next = node ;
        node->pre = head;
        node->next = oldFirstNode;
        oldFirstNode->pre = node;
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){}