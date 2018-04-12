/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/
#include<iostream>
using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
//思想：采用递归来做
bool isSameTree(TreeNode* p, TreeNode* q) {
	if (!p&&!q)
		return true;
	if ((p&&!q) || (!p&&q))
		return false;
	if (p&&q)
	{
		if (p->val != q->val)
			return false;
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
}