/*
Sort a linked list in O(n log n) time using constant space complexity.
*/
/*
本题目可以使用归并排序。
*/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* merge(ListNode* list1,ListNode* list2)//利用归并排序合并两个有序的链表
{
    if(list1==nullptr)
    return list2;
    if(list2==nullptr)
    return list1;
    ListNode* head=nullptr;
    if(list1->val<list2->val)
    {
        head=list1;
        list1=list1->next;
    }
    else
    {
        head=list2;
        list2=list2->next;
    }
    head->next=merge(list1,list2);
    return head;
}
ListNode* merge(ListNode* head)//将链表拆分成单个节点，再用归并排序合并之。
{
    if(head==nullptr||head->next==nullptr)
    return head;
    ListNode* fast=head;
    ListNode* slow=head;
    while(fast->next!=nullptr&&fast->next->next!=nullptr)//将链表分成两段，找到中点
    {
        fast=fast->next;
        fast=fast->next;
        slow=slow->next;
    }
    ListNode* mid=slow->next;
    slow->next=nullptr;
    ListNode* list1=merge(head);//递归拆分
    ListNode* list2=merge(mid);//递归拆分
    ListNode* res=merge(list1,list2);//进行链表的归并排序
    return res;
}
ListNode* sortList(ListNode* head) {
   return merge(head);
}