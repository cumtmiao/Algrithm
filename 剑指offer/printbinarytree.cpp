/*
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
     queue<TreeNode*> qu;
     vector<int> res;
     if(root==nullptr)
     return res;
     qu.push(root);
     while(!qu.empty())
     {
         TreeNode* temp=qu.front();
         res.push_back(temp->val);
         qu.pop();
         if(temp->left!=nullptr)
         qu.push(temp->left);
         if(temp->right!=nullptr)
         qu.push(temp->right);
     }
     return res;
    }
};