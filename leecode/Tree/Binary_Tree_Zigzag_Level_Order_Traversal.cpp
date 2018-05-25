/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, 
then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
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
/*
使用两个栈。
*/
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(root==nullptr)
    return res;
    stack<TreeNode*> current[2];
    current[0].push(root);
    int flag=0;//栈之间切换访问
    vector<int> tempres;
    while(!current[flag].empty()||!current[1-flag].empty())
    {
        TreeNode* temp=current[flag].top();
        tempres.push_back(temp->val);
        current[flag].pop();
        if(flag==0)
        {
            if(temp->left)
            current[1-flag].push(temp->left);
            if(temp->right)
            current[1-flag].push(temp->right);
        }
        else
        {
            if(temp->right)
            current[1-flag].push(temp->right);
            if(temp->left)
            current[1-flag].push(temp->left);
        }
        if(current[flag].empty())
        {
            flag=1-flag;
            res.push_back(tempres);
            tempres.clear();
        }

    }
    return res;
}