/*
输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
*/
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
//本题目本质上还是对递归的考察--前序遍历
/*
1.当前序遍历的方式访问到某节点时，我们把该节点添加到路径上，并累加该节点的值；
2.如果该节点为叶节点并且路径中节点值的和刚好等于输入的整数，则将该路径输入到结果集中；
3.如果该节点为非叶节点，继续访问他的子节点。
4.当前节点访问结束后，递归函数将访问他的父亲节点，因此我们需要在函数退出前在路径中删除当前节点，并减去当前节点的值。
*/
void FindPathCore(TreeNode* root,int expectNumber,vector<vector<int>> &res,vector<int> &path,int sum)
{
    sum+=root->val;
    path.push_back(root->val);
    if(root->left==nullptr&&root->right==nullptr&&sum==expectNumber)
    {
        vector<int> temp;
        vector<int>::iterator it=path.begin();
        for(;it!=path.end();it++)
        {
           temp.push_back(*it);
        }
        res.push_back(temp);
    }
    if(root->left!=nullptr)
    {
        FindPathCore(root->left,expectNumber,res,path,sum);
    }
       if(root->right!=nullptr)
    {
        FindPathCore(root->right,expectNumber,res,path,sum);
    }
    path.pop_back();
}
vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
    vector<vector<int>> res;
    if(root==nullptr)
    return res;
    vector<int> path;
    int sum=0;
    FindPathCore(root,expectNumber,res,path,sum);
    return res;
}