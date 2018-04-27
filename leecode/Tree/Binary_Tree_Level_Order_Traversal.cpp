/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//利用队列实现层序遍历
vector<vector<int>> levelOrder(TreeNode* root) {
    vector< vector<int> > res;
    queue<TreeNode*> q;
    if(root==nullptr)
    return res;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        vector<int> tempv;
        for(int i=0;i<n;i++)
        {
            TreeNode* temp=q.front();
            q.pop();
            tempv.push_back(temp->val);
            if(temp->left!=nullptr)
            q.push(temp->left);
            if(temp->right!=nullptr)
            q.push(temp->right);
        }
        res.push_back(tempv);
    } 
    return res;
}
