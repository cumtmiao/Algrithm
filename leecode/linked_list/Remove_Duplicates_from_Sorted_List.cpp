/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
*/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* deleteDuplicates(ListNode* head) {
    if(head==nullptr||head->next==nullptr)
    return head;
    ListNode* copy=head;
    while(copy->next!=nullptr&&copy->val==copy->next->val)//找到头结点开始的位置
        copy=copy->next;
    head=copy;//找到头结点的位置（跳过开始相等的头结点）
    if(copy->next==nullptr)
    return head;
    else
    {
        ListNode* copy2=copy->next;
        while(true)
        {
            while(copy2->next!=nullptr&&copy2->val==copy2->next->val)//递归的找下一个不相等的节点
            copy2=copy2->next;
            copy->next=copy2;//前一个不相等的节点和当前节点连接起来
            copy=copy2;
            if(copy2->next==nullptr)
            break;
            else
            copy2=copy2->next;
        }
    }
    return head;
}