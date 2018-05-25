/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
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
递归建立BST树。
*/
TreeNode* sortedArrayToBSTCore(vector<int>& nums,int start,int end)
{
    TreeNode* root=new TreeNode(0);
    if(start==end)
    root->val=nums[start];
    else
    {
        int position=(start+end)/2;
        root->val=nums[position];
        if(position-1>=start)
        root->left=sortedArrayToBSTCore(nums,start,position-1);
        if(position+1<=end)
        root->right=sortedArrayToBSTCore(nums,position+1,end);
    }
    return root;

}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    int n=nums.size();
    if(n==0)
    return nullptr;
    TreeNode* root=sortedArrayToBSTCore(nums,0,n-1);
    return root;
}