/*
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/
//这道题目有点难。需要综合考虑各种情况。
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

ListNode* deleteDuplication(ListNode* pHead)
{
    if(pHead==nullptr)
    return nullptr;
    ListNode* pre=new ListNode(-1);//定义一个节点pre指向当前节点cur的前一个节点
    pre->next=pHead;
    ListNode* cur=pHead;//cur指向当前节点
    ListNode* nex=pHead->next;//nex指向当前节点的下一个节点
    while(nex!=nullptr)
    {
        if(cur->val!=nex->val)//如果当前节点与下一个节点的值不相等，则pre，cur，nex，三个指针各前进一步
        {
            pre=cur;
            cur=nex;
            nex=nex->next;
        }
        else//如果当前节点与下一个节点的值相等，则要删除所有与当前节点值相等的节点。
        {
            ListNode* todelete=cur;
            int val=todelete->val;//当前节点值。
            while(todelete!=nullptr&&todelete->val==val)//删除所有与当前节点值相等的节点。
            {
                nex=todelete->next;
                delete todelete;
                todelete=nullptr;
                todelete=nex;
            }                       
                if(nex!=nullptr)//如果nex节点不为空，更新pre,cur和nex.
                {                    
                    cur=nex;
                    nex=nex->next;
                    pre->next=cur;  
                }  
                else//nex为空时更新pre,cur
                {
                    cur=nex;
                    pre->next=cur;
                }    
                if(pre->val==-1)//特殊情况，记录链表的开始指针，即pHead.
                {
                    pHead=cur;
                }      
        }
       
    }
    if(pre->val==-1)
    return pre->next;
    return pHead;
}