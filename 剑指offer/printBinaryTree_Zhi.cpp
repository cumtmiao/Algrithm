/*
请实现一个函数按照之字形打印二叉树，
即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，
第三行按照从左到右的顺序打印，其他行以此类推。
*/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
/*本题目的思路1：
利用一个栈，一个队列，当目前访问节点深度奇偶不同时，其孩子节点入栈的顺序不同，同时需要定义一个flag标志来表示当前行的结束。
有一个小坑：注意二维的vector是如何输入元素的，必须先输入内层的vector元素，然后再整体输入外层。

思路二：
利用两个栈。
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        stack<TreeNode*> sta;
        queue<TreeNode*> que;
        int curentdeep=0;
        TreeNode* flag=nullptr;
        if(pRoot==nullptr)
            return res;
        que.push(pRoot);
        que.push(flag);
        vector<int> vecres;
        vecres.push_back(pRoot->val);
        res.push_back(vecres);
        vecres.clear();
        while(!que.empty())
        {
            while(que.front()!=nullptr)
            {
                if(curentdeep%2==0)//当前是偶数行。    
                {
                    TreeNode* temp=que.front();
                    que.pop();
                    if(temp->left!=nullptr)
                    {
                        sta.push(temp->left);
                    }
                    if(temp->right!=nullptr)
                    {
                        sta.push(temp->right);
                    }
                }
                else//当前是奇数行。
                {
                    TreeNode* temp=que.front();
                    que.pop();
                     if(temp->right!=nullptr)
                    {
                        sta.push(temp->right);
                    }
                    if(temp->left!=nullptr)
                    {
                        sta.push(temp->left);
                    }                 
                } 
            }
            if(que.front()==nullptr)//当前队列到达当前行末
            {
                 
                 que.pop();
                 curentdeep++;
                 vecres.clear();
                 while(!sta.empty())
                 {
                     TreeNode* temp=sta.top();
                     sta.pop();
                     que.push(temp);
                     vecres.push_back(temp->val);
                     res.push_back(veres);
                 }
                 if(vecres.size()!=0)
                 res.push_back(vecres);
                 if(!que.empty())
                 {
                       que.push(nullptr);
                 }
             
  
            }
           
          
        }
        return res;
    }
//思路二：利用两个栈来实现。
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        stack<TreeNode*> sta[2];
        int cur=0;
        int next=1;
        vector<int> curres;
        if(pRoot==nullptr)
        {
            return res;
        }
        sta[cur].push(pRoot);
       
        while(!sta[cur].empty()||!sta[next].empty())
        {
           
            TreeNode* temp=sta[cur].top();
            curres.push_back(temp->val);
            sta[cur].pop();
            if(cur==0)
            {
                if(temp->left!=nullptr)
                {
                 sta[next].push(temp->left);
               
                }
                if(temp->right!=nullptr)
                {
                    sta[next].push(temp->right);
               
                }
                
            }
            else
            {
                if(temp->right!=nullptr)
                {
                    sta[next].push(temp->right);
                   
                }
                if(temp->left!=nullptr)
                {
                    sta[next].push(temp->left);
                  
                }

            }
            if(sta[cur].empty())
            {
                if(curres.size()!=0)
                   res.push_back(curres);
                curres.clear();
                cur=1-cur;
                next=1-next;
            }

        }
        return res;
    }
    
};