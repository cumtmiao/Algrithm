/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
*/
#include<iostream>
using namespace std;
//
struct ListNode{
	int val;
	ListNode*next;
	ListNode(int x) :val(x), next(NULL){}
};
//新建节点
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode *dummy = new ListNode(INT_MIN);
	ListNode *l3 = dummy;
	if (l1 == NULL)return l2;
	if (l2 == NULL)return l1;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val < l2->val)
		{
			ListNode*temp=new ListNode(l1->val);
			l3->next = temp;
			l3 = l3->next;
			l1 = l1->next;
		}
		else if (l2->val < l1->val)
		{
			ListNode*temp = new ListNode(l2->val);
			l3->next = temp;
			l3 = l3->next;
			l2 = l2->next;
		}
		else
		{
			ListNode*temp1 = new ListNode(l2->val);
			l3->next = temp1;
			l3 = l3->next;
			ListNode*temp2 = new ListNode(l2->val);
			l3->next = temp2;
			l3 = l3->next;
			l2 = l2->next;
			l1 = l1->next;
		}
	}
	if (l1 == NULL)
	{
		l3->next = l2;
	}
	if (l2 == NULL)
	{
		l3->next = l1;
	}
	return dummy->next;
}
//不需要新建节点  直接指针指向l1或者是l2 即可。
ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
	ListNode* dummy = new ListNode(INT_MIN);
	ListNode *l3 = dummy;
	while (l1&&l2)
	{
		if (l1->val < l2->val)
		{
			l3->next = l1;
			l1 = l1->next;
		}
		else{
			l3->next = l2;
			l2 = l2->next;
		}
		l3 = l3->next;
	}
	l3->next = l1 ? l1 : l2;
	return dummy->next;
}
/*
void main()
{
	ListNode *l1 = new ListNode(2);
	ListNode *l2 = new ListNode(1);
	 mergeTwoLists(l1, l2);
}
*/