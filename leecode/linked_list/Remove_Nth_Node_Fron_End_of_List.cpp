/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/
#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode*next;
	ListNode(int x) :val(x), next(NULL){}
};

//首先找到链表的长度，然后再正向寻找第L-n个元素，然后将L-n的next指向第L-n+2个节点。
ListNode* removeNthFromEnd1(ListNode* head, int n) {
	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	int length = 0;
	ListNode* first = head;
	while (first != NULL)
	{
		length++;
		first = first->next;
	}
	length = length - n;
	first = dummy;
	while (length != 0)
	{
		length--;
		first = first->next;
	}
	first->next = first->next->next;	
	return dummy->next;
}

//定义两个指针：先让第二个指针领先第一个指针n个位置，然后再同时移动，直到第二个指针到达链表的末尾。
ListNode* removeNthFromEnd2(ListNode* head, int n) {
	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	ListNode* first = dummy;
	ListNode*second = dummy;
	for (int i = 0; i < n ; i++)
	{
		second = second->next;
	}
	while (second->next != NULL)
	{
		first = first->next;
		second = second->next;
	}
	first ->next = first->next->next;
	return dummy->next;

}