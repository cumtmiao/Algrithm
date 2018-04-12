/*
操作给定的二叉树，将其变换为源二叉树的镜像。
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
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
  /* void Mirror(TreeNode *pRoot) { //该递归没通过测试用例，但是没看出程序问题所在
       if(!pRoot)
       return;
       if(!pRoot->left&&!pRoot->right)
       return ;
       exchange(pRoot->left,pRoot->right);
    }
    void exchange(TreeNode *left1,TreeNode* right1)
    {
        if(left1==nullptr&&right1==nullptr)
        return ;     
            TreeNode* temp;
            temp=left1;
            left1=right1;
            right1=temp;       
        if(left1!=nullptr)
        exchange(left1->left,left1->right);
        if(right1!=nullptr)
        exchange(right1->left,right1->right);
    }*/
    void Mirror(TreeNode *pRoot) { //递归的思路。正确通过
        if(!pRoot)
        return;
        if(!pRoot->left&&!pRoot->right)
        return;
        TreeNode* temp;
        temp=pRoot->left;
        pRoot->left=pRoot->right;
        pRoot->right=temp;
        if(pRoot->left)
        {
            Mirror(pRoot->left);
        }
        if(pRoot->right)
        {
            Mirror(pRoot->right);
        }

    }
    };