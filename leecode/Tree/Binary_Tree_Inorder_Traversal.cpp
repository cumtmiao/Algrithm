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
//����һ���ݹ�
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
//������������ ͬ��������ջ���е���
/*
˼·��
����һ���p
1.�������Ӳ�Ϊ�գ���p��ջ����p��������Ϊ��ǰ��p��Ȼ��Ե�ǰ���p�ٽ�����ͬ�Ĵ���
2.��������Ϊ�գ���ȡջ��Ԫ�ز����г�ջ���������ʸ�ջ����㣬Ȼ��ջ�������Һ�����Ϊ��ǰ��p
3.ֱ��pΪnull��ջΪ�����������
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