/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
*/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void rotateOnce(ListNode** head,ListNode** end)//链表右移一位
{
    ListNode* copyhead=(*head);
    (*head)=(*head)->next;//头指针前移一位
    (*end)->next=copyhead;
    copyhead->next=nullptr;
    (*end)=(*end)->next;//尾指针移动一位

}
ListNode* rotateRight(ListNode* head, int k) {
    if(head==nullptr||k==0)
    return head;
    int length=1;
    ListNode* copy=head;
    while(copy->next!=nullptr)
    {
        length++;
        copy=copy->next;
    }//结束之后copy正好指向链表的末尾
    if(length==1)
    return head;
    k=k%length;
    for(int i=0;i<length-k;i++)
    {
        rotateOnce(&head,&copy);
    }
    return head;
}