/*
Given a singly linked list, return a random node's value from the linked list. Each node must have the 
same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this 
efficiently without using extra space?

Example:

// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();
*/
#include<bits/stdc++.h>
using namespace std;
/*
水塘抽样算法。
位置i的节点被选中的概率：
p(i)=1/i*(1-(1/(i+1)))*...*(1-1/n);
*/
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        myhead=head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* cur=myhead;
        int res=cur->val;
        cur=cur->next;
        int i=2;
        while(cur)
        {
            if(rand()%i==0)
            res=cur->val;
            cur=cur->next;
            i++;
        }
        return res;
    }
    ListNode* myhead;
};
