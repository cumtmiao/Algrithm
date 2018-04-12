/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

		   1         3     3      2      1
			\       /     /      / \      \
			 3     2     1      1   3      2
			/     /       \                 \
		   2     1         2                 3
*/
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
//DFS递归
vector<TreeNode*> creatTree(int start, int end)
{
	vector<TreeNode*> res;
	if (start > end)
	{
		res.push_back(NULL);
		return res;
	}
	for (int k = start; k <= end; k++)
	{
		vector<TreeNode*> left = creatTree(start, k - 1);//创建左子树
		vector<TreeNode*> right = creatTree(k + 1, end);//创建右子树
		for (int i = 0; i < left.size(); i++)
		{
			for (int j = 0; j < right.size(); j++)
			{
				TreeNode *root = new TreeNode(k);
				root->left = left[i];
				root->right = right[j];
				res.push_back(root);
			}
		}
	}
	return res;
}

vector<TreeNode*> generateTrees(int n) {
	if (n == 0)return{};
	return creatTree(1, n);
}