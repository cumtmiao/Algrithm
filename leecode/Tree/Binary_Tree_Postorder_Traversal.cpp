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
//����һ���ݹ�
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
//������������
/*
˼·��
һ�������Ҫ��������²��ܹ������
��һ�����Ѿ���Ҷ�ӽ�㣻
�ڶ���������Ҷ�ӽ�㣬�������Ķ����Ѿ��������
��ô���ڴ�����ֻ��Ҫ��¼һ�µ�ǰ����Ľ�㼴�ɡ�
����һ���µĽ�㣬���������Ҷ�ӽ�㣬����Ҳû�з��ʣ���ô����Ҫ�������Ҷ��ӣ������ѹ�롣
�������������������������������¼�µ�ǰ�����㡣�����stackΪ��ʱ������
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
		//��ǰ���ʵĽڵ�ΪҶ�ӽڵ�����ӽڵ��Ѿ����ʹ������������ýڵ��ֵ
		if ((top->left == NULL&&top->right == NULL) || top->left == head || top->right == head)
		{
			res.push_back(top->val);
			s.pop();
			head = top;//��¼��һ�η��ʵĽڵ�
		}
		//���򣬽�����Ӽ���ѹ��ջ�С�
		else
		{
			if (top->right)s.push(top->right);
			if (top->left)s.push(top->left);
		}
	}
	return res;
}