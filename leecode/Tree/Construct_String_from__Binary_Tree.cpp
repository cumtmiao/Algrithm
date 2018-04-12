/*
You need to construct a string consists of parenthesis and integers from a binary tree 
with the preorder traversing way.

The null node needs to be represented by empty parenthesis pair "()". 
And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping 
relationship between the string and the original binary tree.

Example 1:
Input: Binary tree: [1,2,3,4]
			  1
			/   \
		   2     3
	      /
		 4

Output: "1(2(4))(3)"

Explanation: Originallay it needs to be "1(2(4)())(3()())",
but you need to omit all the unnecessary empty parenthesis pairs.
And it will be "1(2(4))(3)".

Example 2:
Input: Binary tree: [1,2,3,null,4]
			  1
			/   \
		   2     3
			\
			 4

Output: "1(2()(4))(3)"

Explanation: Almost the same as the first example,
except we can't omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
*/
#include<iostream>
#include<string>
#include<stack>
#include<set>
using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
//����һ��ʹ�õݹ�ķ���
string res = "";
string tree2str(TreeNode *t){
	//if (t == NULL)return res;
	if (t != NULL)
	{
		res = res+to_string(t->val);
		if (t->left != NULL)
		{
			res += '(';
			tree2str(t->left);
			res += ')';
		}
		if (t->left != NULL&&t->right != NULL)
		{
			res = res + "(";
			tree2str(t->right);
			res += ')';
		}
		if (t->left == NULL&&t->right != NULL)
		{
			res = res + "()(";
			tree2str(t->right);
			res += ')';
		}
		
	}
	return res;
}
//��������ʹ�õ����ķ���
string tree2str(TreeNode *t){
	string res = "";
	stack<TreeNode *>s;
	set<TreeNode *> visited;//��¼�ýڵ��Ƿ񱻷��ʹ�
	if (t == NULL)return res;
	s.push(t);
	while (!s.empty())
	{
		TreeNode *p = s.top();
		if (visited.find(p) != visited.end())//����ýڵ㱻���ʹ�����ջ����������
		{
			s.pop();	
			res += ')';
		}
		else//����ýڵ�δ�����ʹ���������ӵ����ʼ����У���������������
		{
			visited.insert(p);
			res = res+'('+to_string(p->val);

			if (p->right&&p->left)//���Ҷ��Ӷ���Ϊ�գ�ѹ�Һ�����ջ
			{
				
				s.push(p->right);				
			}
			if (p->right&&!p->left)//����ӿգ��Ҷ��Ӳ��գ���ӿ����ź�ѹ�Һ�����ջ
			{
				res += "()";
				s.push(p->right);				
			}
			if (p->left)//���Ӳ�Ϊ�գ���ջ
			{
				
				s.push(p->left);
			}

		}
		
	}
	return res.substr(1,res.size()-2);
}