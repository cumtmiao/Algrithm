/*
Implement a trie with insert, search, and startsWith methods.
Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/
#include<bits/stdc++.h>
using namespace std;
class TrieNode{
public:
    bool isword;
    TrieNode* children[26];
    TrieNode()
    {
        isword=false;
        for(auto &a:children)//必须加引用，才能起到初始化的作用。
        a=NULL;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int length=word.size();
        TrieNode* p=root;
        for(int i=0;i<length;i++)
        {
            int index=word[i]-'a';
            if(p->children[index]==NULL)
            {
                p->children[index]=new TrieNode();
            }
            p=p->children[index];
        }
        p->isword=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int length=word.size();
        TrieNode* p=root;
        for(int i=0;i<length;i++)
        {
            int index=word[i]-'a';
            if(p->children[index]==NULL)
            return false;
            p=p->children[index];
        }
        if(p->isword==false)
        return false;
        else
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int length=prefix.size();
        TrieNode* p=root;
        for(int i=0;i<length;i++)
        {
            int index=prefix[i]-'a';
            if(p->children[index]==NULL)
            return false;
            p=p->children[index];
        }
        return true;
    }
private:
    TrieNode* root;
};