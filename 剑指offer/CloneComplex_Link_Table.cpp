/*
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/
#include<bits/stdc++.h>
using namespace std;
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
//思路一：先进行链表节点的复制，再修改其中指针的值--可以利用哈希，时间复杂度为O(n),空间复杂度为O(n)
RandomListNode* Clone(RandomListNode* pHead)
{
    map<RandomListNode*,RandomListNode*> m;
    RandomListNode* pNode=pHead;
    while(pNode!=nullptr)//迭代的创建节点，并将其插入到哈希表中
    {
        RandomListNode* pCopyNode=new RandomListNode(0);
        pCopyNode->label=pNode->label;
      // m.insert(pair<RandomListNode*,RandomListNode*>(pNode,pCopyNode));
      m[pNode]=pCopyNode;
        pNode=pNode->next;
    }
    map<RandomListNode*,RandomListNode*>::iterator it=m.begin();
     map<RandomListNode*,RandomListNode*>::iterator res=m.begin();
    for(;it!=m.end();it++)//迭代地修改copy节点的指针。
    {
        if(it->first->next!=nullptr)
        it->second->next=m[it->first->next];
        else
        it->second->next=nullptr;
        if(it->first->random!=nullptr)
        it->second->random=m[it->first->random];
        else
        it->second->random=nullptr;
    }
    return res->second;
}

/*
解法二：只需要O(n)的时间复杂度，O(1)的空间。
采用书上给出的方法：
1.复制链表中的节点，将其插在原节点之后；
2.修改复制节点的random指针；
3.将链表分裂为两个链表
*/

RandomListNode* Clone2(RandomListNode* pHead){
    RandomListNode* pNode=pHead;
    while(pNode!=nullptr)//复制链表中的节点，将其插在原节点之后；
    {
        RandomListNode* pCopyNode=new RandomListNode(0);
        pCopyNode->label=pNode->label;
        pCopyNode->next=pNode->next;
        pNode->next=pCopyNode;
        pNode=pCopyNode->next;
    }
    pNode=pHead;
    RandomListNode* pCopyNode=nullptr;
    while(pNode!=nullptr)//修改复制节点的random指针；
    {
        pCopyNode=pNode->next;
        if(pNode->random!=nullptr)
        pCopyNode->random=pNode->random->next;
        else 
        pCopyNode->random=nullptr;
        pNode=pCopyNode->next;
    }
    pNode=pHead;
    RandomListNode* res=nullptr;//将链表分裂为两个链表。
    if(pNode!=nullptr)
    {
        pCopyNode=pNode->next;
        res=pNode->next;
        pNode->next=pCopyNode->next;
        pNode=pNode->next;
    }
 
    while(pNode!=nullptr)
    {
        pCopyNode->next=pNode->next;
        pCopyNode=pCopyNode->next;
        pNode->next=pCopyNode->next;
        pNode=pNode->next;
    }
    return res;
}