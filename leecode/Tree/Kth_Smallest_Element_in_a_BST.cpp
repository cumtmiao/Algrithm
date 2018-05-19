/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth 
smallest frequently? How would you optimize the kthSmallest routine?
*/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int num=0;
void KthSmallestCore(TreeNode* root,int k,TreeNode** mem)//中序遍历二叉树，如果访问到第k个节点，则记录下位置，返回
{
    if(root->left!=nullptr)
    KthSmallestCore(root->left,k,mem);
    num++;
    if(num==k)
    *mem=root;
    if(num>k)
    return;
    if(root->right!=nullptr)
    KthSmallestCore(root->right,k,mem);
}
int kthSmallest(TreeNode* root, int k) {
    TreeNode* mem=root;
    KthSmallestCore(root,k,&mem);
    return mem->val;
}