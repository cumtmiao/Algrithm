/*
输入一棵二叉树，求该树的深度。
从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
*/
//简单的递归：当前树的深度等于左子树深度和右子树深度的最大值加一。
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

int TreeDepth(TreeNode* pRoot)
{
    if(pRoot==nullptr)
    return 0;
    int depth=0;
    if(pRoot->left!=nullptr)//左子树不空，返回左子树的深度
    {
        depth=TreeDepth(pRoot->left);
    }
    if(pRoot->right!=nullptr)//右子树不空，返回左子树，右子树深度的最大值。
    {
        depth=max(depth,TreeDepth(pRoot->right));
    }
    return depth+1;//根节点开始的树的深度为左子树，右子树深度的最大值+1.
}