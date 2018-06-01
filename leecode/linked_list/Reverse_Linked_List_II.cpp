/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void reverse(ListNode** begin,ListNode** end)//翻转一个链表，开始位置为begin，结束位置为end
{
    ListNode* second=nullptr;
    ListNode* first=*begin;
    while(first!=nullptr)
    {
        ListNode* temp=second;
        second=first;
        first=(first)->next;
        second->next=temp;
    }
    *end=*begin;
    *begin=second;
}
ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode* cur=head;
    ListNode* begin=nullptr;//中间链表的开始位置
    ListNode* end=nullptr;//中间链表的结束位置
    ListNode* front=nullptr;///前半段最后一个指针的位置
    ListNode* after=nullptr;//后半段开始的位置
    int num=0;
    while(cur!=nullptr)
    {
        num++;
        if(num==m-1)
        {
            front=cur;
        }
        if (num==m)
        {
            begin=cur;
        }
        if(num==n)
        {
            end=cur;
        }
        if(num==n+1)
        {
            after=cur;
        }
        cur=cur->next;
    }
    if(front!=nullptr)
    front->next=nullptr;
    end->next=nullptr;
    reverse(&begin,&end);
    if(front!=nullptr)
    {
        front->next=begin;
        end->next=after;
        return head;
    }
    else
    {
        end->next=after;
        return begin;
    }
}