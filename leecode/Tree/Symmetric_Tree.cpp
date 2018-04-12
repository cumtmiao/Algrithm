/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

			   	 1
				/ \
			   2   2
			  / \ / \
			 3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
				1
			   / \
			  2   2
			   \   \
			   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/
#include<iostream>
#include<stack>
using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
//方法一：可以使用递归的方法。
bool helper(TreeNode *p1, TreeNode *p2)
{
	if (!p1&&!p2)
	{
		return true;
	}
	if (p1&&!p2 || (!p1&&p2))
		return false;
	if (p1&&p2)
	{
		if (p1->val == p2->val)
			return helper(p1->left, p2->right) && helper(p1->right, p2->left);
		else return false;
	}
}
bool isSymmetric(TreeNode* root) {
	if (root == NULL)return true;
	return helper(root->left, root->right);
}
//方法二：使用迭代的方法。利用栈
bool isSymmetric2(TreeNode* root)
{
	stack<TreeNode *>s;
	if (!root)return true;
	if (!root->left&&!root->right)return true;
	if ((root->left&&!root->right) || (!root->left&&root->right))return false;
	s.push(root->right);
	s.push(root->left);
	while (!s.empty())
	{
		TreeNode *p1 = s.top();
		s.pop();
		TreeNode *p2 = s.top();
		s.pop();
		if (p1->val != p2->val)return false;
		if ((!p1->left&&p2->right) || (p1->left&&!p2->right))
			return false;
		if ((!p1->right&&p2->left) || (p1->right&&!p2->left))
			return false;
		if (p1->left&&p2->right)
		{
			s.push(p2->right);
			s.push(p1->left);		
		}
		if (p1->right&&p2->left)
		{
			s.push(p2->left);
			s.push(p1->right);
		}
	}
	return true;
}