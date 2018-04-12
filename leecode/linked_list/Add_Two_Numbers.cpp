/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
#include<iostream>
using namespace std;

class Add_Two_Numbers{
public:
	struct ListNode
	{
		int val;
		ListNode *next;
		ListNode(int x) :val(x), next(NULL){}
	};
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* dummyhead = new ListNode(0);
		ListNode* p = l1, *q = l2, *cur = dummyhead;
		int carry = 0;
		while (p != NULL || q != NULL)
		{
			int x = (p != NULL) ? p->val : 0;
			int y = (q != NULL) ? q->val : 0;
			int sum = x + y + carry;
			carry = sum / 10;
			//cur->next->val = sum % 10;
			cur->next = new ListNode(sum % 10);
			cur = cur->next;
			if(p!=NULL)p = p->next;
			if (q != NULL)q = q->next;
		}
		if (carry > 0)//ºÜÈÝÒ×Íü£¡£¡
		{
			cur->next = new ListNode(1);
		}
		return dummyhead->next;

	}
};
