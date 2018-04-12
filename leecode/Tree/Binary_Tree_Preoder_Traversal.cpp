/*
Given a binary tree, return the preorder traversal of its nodes’ values.
For example: Given binary tree {1,#,2,3},
		1
		\
		2
		/
		3
return [1,2,3].
Note: Recursive solution is trivial, could you do it iteratively?
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
//方法一：递归

vector<int> res;
vector<int> preorderTraversal(TreeNode *root) {	
	if (root != nullptr)
	{
		res.push_back(root->val);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
	return res;

}

//方法二：迭代法。利用栈进行迭代
vector<int> preorderTraversal2(TreeNode *root){
	vector<int>res2;
	stack<TreeNode *> s;
	if (root == NULL)return res2;
	s.push(root);
	while (!s.empty())
	{
		TreeNode *p = s.top();
		res2.push_back(p->val);
		s.pop();
		if (p->right)
		{
			s.push(p->right);
		}
		if (p->left)
		{
			s.push(p->left);
		}
	}
	return res2;
}