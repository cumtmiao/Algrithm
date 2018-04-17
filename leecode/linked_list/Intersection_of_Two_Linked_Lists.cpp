/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/
/*
注意题目要求O(n)的时间复杂度和O(1)的空间复杂度，所以我们不能用栈的方法来做。
思路：先找出两个链表之间长度的差值，然后长的链表先前进这个“差值”步，之后两个链表同时前进，知道找到交叉的节点。
*/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA==nullptr||headB==nullptr)
    return nullptr;
    ListNode* tempA=headA;
    ListNode* tempB=headB;
    while(tempA&&tempB)
    {
        tempA=tempA->next;
        tempB=tempB->next;
    }
    int cha=0;
    if(tempA==nullptr)
    {
        while(tempB!=nullptr)
        {
            tempB=tempB->next;
            cha++;
        }
        tempB=headB;
        tempA=headA;
        for(int i=0;i<cha;i++)
        {
             tempB=tempB->next;  
        }
    }
    else
    {
        while(tempA!=nullptr)
        {
            tempA=tempA->next;
            cha++;
        }
        tempA=headA;
        tempB=headB;
        for(int i=0;i<cha;i++)
        {
             tempA=tempA->next;  
        }
    }
    while(tempA&&tempB)
    {
        if(tempA==tempB)
        return tempA;
        tempA=tempA->next;
        tempB=tempB->next;
    }
    return nullptr;
}