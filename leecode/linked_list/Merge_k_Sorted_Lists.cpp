/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// ListNode* buildlist(vector<int> data,int index)//通过了大多数测试用例，最后一个测试用例超过限制内存
// {
//     if(index==data.size())
//     return nullptr;
//     ListNode *res= new ListNode(0);
//     res->val=data[index];
//     res->next=buildlist(data,index+1);
//     return res;
// }
// ListNode* mergeKLists(vector<ListNode*>& lists) {
//     vector<int> res;
//     int length=lists.size();
//     while(true)
//     {
//         int tempvalue=INT_MAX;
//         int index=INT_MAX;
//         for(int i=0;i<length;i++)
//         {
//             if(lists[i]!=nullptr)
//             {
//                 if(lists[i]->val<tempvalue)
//                 {
//                     tempvalue=lists[i]->val;
//                     index=i;
//                 }   
//             }
//         }
//         if(index!=INT_MAX)
//         {
//             res.push_back(tempvalue);
//             lists[index]=lists[index]->next;
//         }
//         else
//         break;
//     }
//     return buildlist(res,0);
// }

ListNode* mergeKLists(vector<ListNode*>& lists) {//递归的方法。
    int length=lists.size();
    int tempvalue=INT_MAX;
    int index=INT_MAX;
    for(int i=0;i<length;i++)
    {
        if(lists[i]!=nullptr)
        {
            if(lists[i]->val<tempvalue)
            {
                tempvalue=lists[i]->val;
                index=i;
            }   
        }
    }
    if(index!=INT_MAX)
    {
        ListNode* res= new ListNode(0);
        res->val=tempvalue;
        lists[index]=lists[index]->next;
        res->next=mergeKLists(lists);
        return res;
    }
    else
    return nullptr;
}