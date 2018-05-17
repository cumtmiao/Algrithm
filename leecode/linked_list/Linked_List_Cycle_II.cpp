/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
*/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
bool hasCycle(ListNode *head,ListNode** meet)//判断是否有环，并且记录first指针和secood指针相遇的位置
{
    ListNode* first=head;
    ListNode* second=head;
    while(second!=nullptr)
    {
        first=first->next;
        second=second->next;
        if(second==nullptr)
        return false;
        second=second->next;
        if(first==second)
        {
            *meet=first;
            return true;
        }
    }
    return false;
}
int numofnodesinCycle(ListNode* meet)//计算环中节点的数量
{
    ListNode* traverse=meet->next;
    int num=1;
    while(traverse!=meet)
    {
        traverse=traverse->next;
        num++;
    }
    return num;
}
ListNode *detectCycle(ListNode *head) {
    if(head==nullptr)
    return nullptr;
    ListNode* copy=head;
    ListNode** meet=&copy;//注意此处要记录环中两指针相交的节点位置，则应该使用ListNode**类型
    if(!hasCycle(head,meet))//如果链表不存在环，则返回一个null指针，否则记录下first指针与second指针相交的位置
    return nullptr;
    int numberofnodes_in_cycle=numofnodesinCycle(*meet);//计算环中节点的数目
    ListNode* front=head;
    ListNode* end=head;
    while(numberofnodes_in_cycle!=0)//front指针在链上先前进numberofnodes_in_cycle步
    {
        front=front->next;
        numberofnodes_in_cycle--;
    }
    while(front!=end)//直到front指针和second指针相等，就找到环的入口节点。
    {
        front=front->next;
        end=end->next;
    }
    return front;
}