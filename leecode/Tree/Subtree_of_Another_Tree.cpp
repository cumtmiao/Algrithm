/*
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node 
values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's 
descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
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
递归
*/
bool equals(TreeNode* s,TreeNode* t)//判断两个树是否相等
{
    if(s==nullptr&&t==nullptr)
    return true;
    if(t!=nullptr&&s==nullptr)
    return false;
    if(t==nullptr&&s!=nullptr)
    return false;
    if(t->val!=s->val)
    return false;
    else
    return equals(s->left,t->left)&&equals(s->right,t->right);
}
bool isSubtree(TreeNode* s, TreeNode* t) {
    if(s==nullptr&&t==nullptr)
    return true;
    if(t!=nullptr&&s==nullptr)
    return false;
    if(t==nullptr&&s!=nullptr)
    return false;
    if(t->val!=s->val)
    return isSubtree(s->left,t)||isSubtree(s->right,t);
    else
    return (equals(s->left,t->left)&&equals(s->right,t->right))||(isSubtree(s->left,t)||isSubtree(s->right,t));
}