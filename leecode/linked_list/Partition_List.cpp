/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater
 than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
*/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* partition(ListNode* head, int x) {
    if(head==nullptr)
    return head;
    vector<ListNode*> small;
    vector<ListNode*> big;
    ListNode* cur=head;
    while(cur!=nullptr)
    {
        if(cur->val<x)
        {
            small.push_back(cur);
        }
        else
        {
            big.push_back(cur);
        }
        cur=cur->next;
    }
    for(int i=0;i<big.size();i++)
    {
        if(i==big.size()-1)
        {
            big[i]->next=nullptr;
        }
        else
        {
            big[i]->next=big[i+1];
        }
    }
    for(int i=0;i<small.size();i++)
    {
        if(i==small.size()-1)
        {
            if(big.size()==0)//考虑big是否为空
            {
                small[i]->next=nullptr;
            }
            else
                small[i]->next=big[0];
        }
        else
        {
            small[i]->next=small[i+1];
        }
    }
    return small.size()==0?big[0]:small[0];//考虑small是否为空
}