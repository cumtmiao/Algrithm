/*
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is 
changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
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
相当于变形的中序遍历，先遍历右子树，再访问当前节点，再遍历左子树。
*/
int sum=0;
TreeNode* convertBST(TreeNode* root) {
    if(root==nullptr)
    return root;
    TreeNode * root1=new TreeNode(0);
    root1->right=convertBST(root->right);
    sum+=root->val;
    root1->val=sum;
    root1->left=convertBST(root->left);
    return root1;
}