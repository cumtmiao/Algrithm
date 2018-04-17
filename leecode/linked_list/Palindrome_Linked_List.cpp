/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
基本思路是：找到链表的中点，翻转链表的后半部分。然后比较前半部分和后半部分，查看是否是回文串。
*/
ListNode* traverse(ListNode *list)//翻转链表
{
    if(list==nullptr||list->next==nullptr)
    return list;
    ListNode* first=list;//first指针在前，second指针在后
    ListNode* second=nullptr;
    while(first!=nullptr)
    {
        ListNode* temp=second;//暂存第二个指针。
        second=first;
        first=first->next;
        second->next=temp;
    }
    return second;
}
bool isPalindrome(ListNode* head) {
    if(head==nullptr||head->next==nullptr)
    return true;
    ListNode* fast=head, *slow=head;
    while(fast->next&&fast->next->next)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    ListNode* list2=nullptr;
    if(fast->next==nullptr)//链表长度为奇数
    {
        list2=traverse(slow);
    }
    else//链表长度为偶数
    {
        list2=traverse(slow->next);
    }
    slow->next=nullptr;
    ListNode* list1=head;
    while(list1!=nullptr&&list2!=nullptr)
    {
        if(list1->val!=list2->val)
        break;
        list1=list1->next;
        list2=list2->next;
    }
    if(list1!=nullptr)
    return false;
    else
    {
        return true;
    }
}