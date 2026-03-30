#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
/*
——————！！！以下个人尝试内容都是错误的，如果赶时间请不要看！！！——————
个人尝试中：
大致思路：
        1、将每门课程视为一个节点，其前置课程相当于其pre指针指向前置课程的节点
        2、将每个课程对应的前置课程连接起来，会形成一个类线性链表
        3、若课程存在互为前置课程，说明此两个课程所在的链表存在环
        4、检测链表是否存在环：141_环形链表
故有流程：
        1、声明isVisited数组大小为课程数量初始化为false
        2、遍历所有的课程，形成链表
        3、遍历isVisited数组查看是否存在负环
尝试中：        

    struct ListNode{
        int val;
        ListNode *pre;
        ListNode(int x) : val(x) , pre(NULL){}
    };

    bool hasCycle(ListNode* head,unordered_map<int,bool>&isVisited){
        if(!head->pre)return false;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast&&slow&&fast->pre){
            isVisited[fast->val]=true;
            isVisited[slow->val]=true;
            fast=fast->pre->pre;
            slow=slow->pre;
            if(fast==slow)return true;
        }
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,bool>isVisited;
        vector <ListNode*> nodes(numCourses,NULL);
        for(int i=0;i<prerequisites.size();++i){
            if(!isVisited.count(prerequisites[i][0])){
                ListNode* node =new ListNode(prerequisites[i][0]);
                nodes[prerequisites[i][0]]=node;
                //isVisited[prerequisites[i][0]]=false;
                isVisited.insert({prerequisites[i][0],false});
            }
            if(!isVisited.count(prerequisites[i][1])!=0){
                ListNode* node =new ListNode(prerequisites[i][1]);
                nodes[prerequisites[i][1]]=node;
                //isVisited[prerequisites[i][1]]=false;
                isVisited.insert({prerequisites[i][1],false});
            }
        }

        for(auto node : nodes){
            if(!isVisited[node->val]){
                bool res = hasCycle(node,isVisited);
                if(res)return false;
            }
        }
        return false;
    }

尝试失败：原因
1、数据结构选择不当：使用自定义链表结构过于复杂
2、环检测算法错误：快慢指针法只适用于链表，不适用于可能有多个入度/出度的图
3、未正确处理多个依赖关系：一个课程可能有多个前置课程
4、isVisited使用错误：没有正确记录访问状态
*/
/*
//正确做法：拓扑排序，邻接表法通过广度优先实现，若能完成所有课程的学习则会存在一个合法的拓扑排序
    bool topologySort(vector<vector<int>>&graph,vector<int>&inDegree){
        queue<int>q;
        for(int i=0;i<inDegree.size();++i){
            if(inDegree[i]==0)q.push(i);
            if(i==inDegree.size()-1&&q.empty())return false;
        }
        while(!q.empty()){
            int num=q.front();
            for(int i=0;i<graph[num].size();++i){
                inDegree[graph[num][i]]--;
                if(inDegree[graph[num][i]]==0){
                    q.push(graph[num][i]);
                }
            }
            q.pop();
        }
        for(int num : inDegree){
            if(num!=0)return false;
        }
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        vector<int>inDegree(numCourses,0);
        for(int i=0;i<prerequisites.size();++i){
            //prerequisites[i][0]的数字直接对应graph的下标
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
            inDegree[prerequisites[i][1]]++;
        }
        return topologySort(graph,inDegree);
    }   
晕厥qwq
    问题在于，两个前后关系完全写反了，但是歪打正着，只是将原来的图所有的边反方向了，不影响最终能否拥有合法的拓扑排序
    要修改的话将0改为1，1改为0即可
*/
//进一步优化版本，修改了逻辑错误，优化了最终结果的判别方式
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //初始化对应需要的数据
        vector<vector<int>>graph(numCourses);
        vector<int>inDegree(numCourses,0);
        //记录入度
        for(int i=0;i<prerequisites.size();++i){
            //prerequisites[i][0]的数字直接对应graph的下标
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }
        //调用拓扑排序
        return topologySort(graph,inDegree);
    } 

bool topologySort(vector<vector<int>>&graph,vector<int>&inDegree){
        //使用count进行记录已经遍历过的课程数量    
        int count=0;
        queue<int>q;
        //初始化队列
        for(int i=0;i<inDegree.size();++i){
            if(inDegree[i]==0){
                count++;
                q.push(i);
                }
        }
        //如果初始化结束队列仍然为空则说明结果为false
        if(q.empty())return false;
        //拓扑排序遍历
        while(!q.empty()){
            int num=q.front();
            for(int i=0;i<graph[num].size();++i){
                inDegree[graph[num][i]]--;
                if(inDegree[graph[num][i]]==0){
                    q.push(graph[num][i]);
                    count++;
                }
            }
            q.pop();
        }
        //返回结果
        return count==inDegree.size();
    }

};



int main(){

}