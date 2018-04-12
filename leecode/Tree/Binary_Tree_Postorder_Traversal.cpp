/*
Given a binary tree, return the postorder traversal of its nodes' values.
	1
	\
	2
	/
	3
return [3,2,1].
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
vector<int> postoderTraversal(TreeNode *root)
{	
	if (root != NULL)
	{
		postoderTraversal(root->left);
		postoderTraversal(root->right);
		res.push_back(root->val);
	}
	return res;
}
//方法二：迭代
/*
思路：
一个结点需要两种情况下才能够输出：
第一，它已经是叶子结点；
第二，它不是叶子结点，但是它的儿子已经输出过。
那么基于此我们只需要记录一下当前输出的结点即可。
对于一个新的结点，如果它不是叶子结点，儿子也没有访问，那么就需要将它的右儿子，左儿子压入。
如果它满足输出条件，则输出它，并记录下当前输出结点。输出在stack为空时结束。
*/
vector<int> postorderTraversal(TreeNode *root)
{
	vector<int> res;
	if (root == NULL)return res;
	stack<TreeNode*>s;
	TreeNode *head = root;
	s.push(root);
	while (!s.empty())
	{
		TreeNode *top = s.top();
		//当前访问的节点为叶子节点或者子节点已经访问过，则可以输出该节点的值
		if ((top->left == NULL&&top->right == NULL) || top->left == head || top->right == head)
		{
			res.push_back(top->val);
			s.pop();
			head = top;//记录上一次访问的节点
		}
		//否则，将其儿子几点压入栈中。
		else
		{
			if (top->right)s.push(top->right);
			if (top->left)s.push(top->left);
		}
	}
	return res;
}