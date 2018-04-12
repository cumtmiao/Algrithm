/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. 
You may not modify the values in the list, only nodes itself can be changed.
*/
#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode*next;
	ListNode(int x) :val(x), next(NULL){}
};
//麻痹 看的劳资懵逼。。。雪崩。。关键弄清楚指针之间的赋值是怎么进行的。
ListNode* swapPairs(ListNode* head) {
	ListNode*dummy = new ListNode(0);
	dummy->next = head;
	ListNode* pre = dummy;
	ListNode* cur = head;
	while (cur&&cur->next)
	{
		ListNode* next = cur->next->next;
		cur->next->next = cur;
		pre->next = cur->next;
		if (next&&next->next)
			cur->next = next->next;
		else
			cur->next = next;
		pre = cur;
		cur = next;
	}
	return dummy->next;
}