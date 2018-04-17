/*
Given a linked list, determine if it has a cycle in it.

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
 /*
 思想：定义两个指针：first指针每次前进一步，second指针每次前进两步，当两个指针能够相遇的情况下有环，否则无环
 */
bool hasCycle(ListNode *head) {
    if(head==nullptr)
    return false;
    ListNode *first=head;
    ListNode *second=head;
    while(first&&second)
    {
        first=first->next;
        second=second->next;
        if(second==nullptr)
        return false;
        else
        second=second->next;
        if(first==second)
        return true;
    }
    return false;
}