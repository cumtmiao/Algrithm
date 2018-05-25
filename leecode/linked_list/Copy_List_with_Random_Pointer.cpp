/*
A linked list is given such that each node contains an additional random pointer 
which could point to any node in the list or null.
Return a deep copy of the list.
*/
#include<bits/stdc++.h>
using namespace std;
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
map<RandomListNode*,RandomListNode*> m;
//建立复制的链表（初始化值和next指针，并且建立原链表和复制链表的对应关系）
RandomListNode* copyRandomListCore(RandomListNode* head)
{
    if(head==nullptr)
    return nullptr;
    RandomListNode* copy=new RandomListNode(0);
    copy->label=head->label;
    copy->next=copyRandomListCore(head->next);
    m.insert(pair<RandomListNode*,RandomListNode*>(head,copy));
    return copy;
}
RandomListNode *copyRandomList(RandomListNode *head) {
    RandomListNode* copy=copyRandomListCore(head);
    RandomListNode* head1=head;
    RandomListNode* copy1=copy;
    while(copy1!=nullptr)//给复制链表的random指针赋值
    {
        copy1->random=m[head1->random];
        copy1=copy1->next;
        head1=head1->next;
    }
    return copy;
}