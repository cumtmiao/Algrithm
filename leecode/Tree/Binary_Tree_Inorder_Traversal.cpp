/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
	1
	 \
	  2
	 /
    3
return [1,3,2].

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
vector<int>res;
vector<int> inorderTraversal(TreeNode *root)
{
	
	if (root != NULL)
	{
		inorderTraversal(root->left);
		res.push_back(root->val);
		inorderTraversal(root->right);
	}
	return res;
}
//方法二：迭代 同样利用了栈进行迭代
/*
思路：
对任一结点p
1.若其左孩子不为空，则将p入栈并将p的左孩子置为当前的p，然后对当前结点p再进行相同的处理；
2.若其左孩子为空，则取栈顶元素并进行出栈操作，访问该栈顶结点，然后将栈顶结点的右孩子置为当前的p
3.直到p为null且栈为空则结束遍历
*/
vector<int> inorderTravesal2(TreeNode *root)
{
	vector<int>res;
	if (root == NULL)
		return res;
	stack<TreeNode *>s;
	TreeNode* p = root;
	while (p||!s.empty())
	{
		while (p)
		{
			s.push(p);
			p=p->left;
		}
		p=s.top();
		s.pop();
		res.push_back(p->val);
		p = p->right;
	}
	return res;
}