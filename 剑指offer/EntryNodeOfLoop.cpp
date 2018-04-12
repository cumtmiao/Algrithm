/*
一个链表中包含环，请找出该链表的环的入口结点。
*/
/*
求环的入口节点主要有以下3步：
1.判断当前链表是否有环--定义两个指针，一前一后，当两个指针相遇的时候说明有环。
2.求当前链表环中的节点数。从“1”中相遇的节点开始绕环一周即可统计环中的节点数。
3.求环的入口节点--先让快的指针在链表上前进n步（n为环中节点数），快慢指针同时走直到两指针相遇即可得到环的入口节点。
*/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
bool haveLoop(ListNode* pHead,ListNode** meet)//判断当前链表是否存在环，如果存在则返回true,否则，返回false，这个meet用来记录相遇时的指针
{
    ListNode* first=pHead;
    ListNode* second=pHead;
    while(first!=nullptr)
    {
        second=second->next;
        first=first->next;
        if(first!=nullptr)
        {
            first=first->next;
        }
        else
        {
            break;
        }
        if(first==second)
        {
            *meet=first;
            break;
        }
    }
    if(first==nullptr)
    return false;
    return true;
}
int numberofNodes(ListNode* pHead,ListNode**meet)//求环中的节点数。
{
    int number=1;
    ListNode* pNode=*meet;
    pNode=pNode->next;
    while(pNode!=*meet)
    {
        pNode=pNode->next;
        number++;
    }
    return number;
}
ListNode* EntryNodeOfLoop(ListNode* pHead)//求环的入口节点
{
    if(pHead==nullptr)
    return nullptr;
    ListNode* meet=nullptr;
    bool hasloop=haveLoop(pHead,&meet);
    if(!hasloop)
    return nullptr;
    int numberofNode=numberofNodes(pHead,&meet);
    ListNode* first=pHead;
    ListNode*second=pHead;
    for(int i=0;i<numberofNode;i++)
    {
        first=first->next;
    }
    while(first!=second)
    {
        first=first->next;
        second=second->next;
    }
    return first;
}