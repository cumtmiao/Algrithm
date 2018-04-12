/*
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
*/
//利用队列实现，并且设置flag标志，标志着一行的结束。
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

vector<vector<int> > Print(TreeNode* pRoot)
{
    vector<vector<int>> res;
    queue<TreeNode*> qe;
    vector<int> cur;
    TreeNode* flag=nullptr;
    if(pRoot==nullptr)
    return res;
    qe.push(pRoot);
    qe.push(flag);
    while(!qe.empty())
    {
        TreeNode* temp=qe.front();
        if(temp==flag)
        {
            qe.pop();
            if(!qe.empty())
            qe.push(flag);
            res.push_back(cur);
            cur.clear();
        }
        else{
            qe.pop();
            cur.push_back(temp->val);
            if(temp->left!=nullptr)
            {
                qe.push(temp->left);
            }
            if(temp->right!=nullptr)
            {
                qe.push(temp->right);
            }
        }
    }
return res;
}