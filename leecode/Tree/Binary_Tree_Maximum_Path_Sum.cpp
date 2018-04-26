/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the 
tree along the parent-child connections. The path must contain at least one node and does not need to go 
through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
*/
#include<bits/stdc++.h>
using namespace std;
/*
递归解法。
*/
int res=INT_MIN;
int PathSum(TreeNode* root)
{
    if(root==nullptr)
    return 0;
    int left=max(PathSum(root->left),0);
    int right=max(PathSum(root->right),0);
    res=max(res,left+right+root->val);
    return max(left,right)+root->val;

}
int maxPathSum(TreeNode* root) {
    PathSum(root);
    return res;
}