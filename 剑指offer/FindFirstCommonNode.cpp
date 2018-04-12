/*
输入两个链表，找出它们的第一个公共结点。
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
//第一种解法需要使用到栈的数据结构。
ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {//时间复杂度为O（m+n），空间复杂度为O(m+n)
    stack<ListNode*> s1;
    stack<ListNode*> s2;
    ListNode* pNode1=pHead1;
    ListNode* pNode2=pHead2;
    while(pNode1!=nullptr)
    {
        s1.push(pNode1);
        pNode1=pNode1->next;
    }
     while(pNode2!=nullptr)
    {
        s2.push(pNode2);
        pNode2=pNode2->next;
    }
    ListNode* common=nullptr;
    while(!s1.empty()&&!s2.empty())
    {
        ListNode *node1=s1.top();
        ListNode *node2=s2.top();
        if(node1==node2)
        {
            s1.pop();
            s2.pop();
            common=node1;
        }
        else
        break;
    }
    return common;
}
//第二种解法：首先遍历两个链表得到每个链表的长度；使较长的链表先走x步，使得剩余的部分与短的链表长度相同，此时，两个链表再一起走，直到找到第一个相同的节点。
int GetLengthOfLinktable(ListNode* pHead)
{
    int num=0;
    while(pHead!=nullptr)
    {
        num++;
        pHead=pHead->next;
    }
    return num;
}
ListNode* FindFirstCommonNode2( ListNode* pHead1, ListNode* pHead2) 
{
    int length1=GetLengthOfLinktable(pHead1);
    int length2=GetLengthOfLinktable(pHead2);
    int distance=abs(length1-length2);
    ListNode* pNode1=pHead1;
    ListNode* pNode2=pHead2;
    if(length1>length2)
    {
        for(int i=0;i<distance;i++)
        {
            pNode1=pNode1->next;
        }
    }
    else if(length1<length2)
    { 
        for(int i=0;i<distance;i++)
        {
            pNode2=pNode2->next;
        }
    }
    
    while(pNode1&&pNode2&&pNode1!=pNode2)
    {
        pNode1=pNode1->next;
        pNode2=pNode2->next;
    }
    return pNode1;  
}