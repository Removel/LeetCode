#include <iostream>
#include <unordered_map>
using namespace std;

/*
数据结构基本知识：
前置知识：前缀树

一、定义：
前缀树是26叉树
二、性质：
1、 前缀树的根节点表示空前缀（不对应任何字符）
2、 每条从父节点指向子节点的有向边标记一个字符
3、 节点本身不存储字符，仅用于表示状态：本题中表示单词的结尾，还可以表示单词被插入的次数等信息
4、 从根到某节点的路径所经过的边上的字符序列构成一个前缀
*/

class TrieNode{
public:
    bool isEnd;
    unordered_map<char,TrieNode*>rec;

    TrieNode(){
        isEnd=false;
        rec.clear();
    }

};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur=root;
        for(int i=0;i<word.size();++i){
            if(!cur->rec.count(word[i])){
                cur->rec[word[i]]=new TrieNode();
            }
            cur=cur->rec[word[i]];
        }
        cur->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(char ch : word){
            if(!cur->rec.count(ch))return false;
            cur=cur->rec[ch];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *cur=root;
        for(char ch : prefix){
            if(!cur->rec.count(ch))return false;
            cur=cur->rec[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(){

}