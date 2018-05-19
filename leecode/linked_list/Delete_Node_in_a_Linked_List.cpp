/*
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list 
should become 1 -> 2 -> 4 after calling your function.
*/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//这里删除节点的方法：
//先交换当前节点与当前节点后一个节点的值，删除后一个节点。
void deleteNode(ListNode* node) {
    ListNode* first=node;
    ListNode* second=first->next;
    int temp;
    temp=first->val;
    first->val=second->val;
    second->val=temp;
    first->next=second->next;
}