/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:

Input:
    2
   / \
  1   3
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.
*/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> res;
//二叉树的中序遍历。
void inordertraverse(TreeNode* root)
{
    if(root==nullptr)
    return ;
    inordertraverse(root->left);
    res.push_back(root->val);
    inordertraverse(root->right);
}
//判断二叉树中序遍历结束后是否是增序。
bool isValidBST(TreeNode* root) {
    inordertraverse(root);
    if(res.size()==0||res.size()==1)
    return true;

    for(int i=1;i<res.size();i++)
    {
        if(res[i]<=res[i-1])
        return false;
    }
    return true;
}