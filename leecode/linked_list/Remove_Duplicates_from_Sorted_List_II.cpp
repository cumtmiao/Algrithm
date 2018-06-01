/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers 
from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
*/
#include<bits/stdc++.h>
using namespace std;
/*
前驱指针指向上一个不重复的元素
*/
ListNode* deleteDuplicates(ListNode* head) {
    if(head==nullptr)
    return head;
    ListNode* helper=new ListNode(0);
    helper->next=head;
    ListNode* pre=helper;
    ListNode* cur=head;
    while(cur!=nullptr)
    {
        while(cur->next!=nullptr&&cur->next->val==pre->next->val)
        {
            cur=cur->next;
        }
        if(pre->next==cur)
        {
            pre=pre->next;
        }
        else
        {
            pre->next=cur->next;
        }
        cur=cur->next;
    }
    return helper->next;
}