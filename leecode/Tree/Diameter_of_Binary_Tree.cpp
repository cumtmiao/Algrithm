/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary 
tree is the length of the longest path between any two nodes in a tree. This path may or may not pass 
through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
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
使用递归，时间复杂度有点大
*/
int depthoftree(TreeNode* root)//判断树的深度
{
    if(root==nullptr)
    return 0;
    return max(depthoftree(root->left),depthoftree(root->right))+1;
}
int diameterOfBinaryTree(TreeNode* root) {
    if(root==nullptr)
    return 0;
    if(root->left==nullptr&&root->right==nullptr)
    return 0;
    int val=depthoftree(root->left)+depthoftree(root->right);
    int val2= max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right));
    return max(val,val2);
}

/*
可以在求树的深度的同时计算路径的最大长度。
*/
int ans;//使用ans记录最长路径上的节点数
int diameterOfBinaryTree(TreeNode* root)
{
    ans=1;
    depth(root);
    return ans-1;
}
int depth(TreeNode* root)
{
    if(root==nullptr)
    return 0;
    int l=depth(root->left);
    int r=depth(root->right);
    ans=max(ans,l+r+1);
    return max(l,r)+1;
}
