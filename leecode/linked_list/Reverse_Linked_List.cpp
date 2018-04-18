/*
Reverse a singly linked list.
*/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
需要新建立一个为nullptr的节点存放反转后的最后一个节点的next空指针。然后再同时往后移动first指针和Second指针。

*/
ListNode* reverseList(ListNode* head) {
    ListNode* first=head;
    ListNode* second=nullptr;
    while(first!=nullptr)
    {
        ListNode* temp=second;
        second=first;
        first=first->next;
        second->next=temp;
    }
    return second;
}