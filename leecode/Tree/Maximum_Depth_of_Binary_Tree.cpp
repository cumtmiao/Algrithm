/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest 
leaf node.

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
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
解法一：递归
*/
int maxDepthCore(TreeNode* root, int depth)//递归
{
    if(root==nullptr)
    return depth;
    return max(maxDepthCore(root->left,depth+1),maxDepthCore(root->right,depth+1));
}
int maxDepth(TreeNode* root) {
    return maxDepthCore(root,0);
}
/*
解法二：层序遍历，统计深度。利用队列
*/
int maxDepth(TreeNode* root) 
{
    if(root==nullptr)
    return 0;
    queue<TreeNode*> q;
    q.push(root);
    int depth=0;
    while(!q.empty())
    {
        depth++;
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left!=nullptr)
            q.push(temp->left);
            if(temp->right!=nullptr)
            q.push(temp->right);
        }
    }
    return depth;
}
    
