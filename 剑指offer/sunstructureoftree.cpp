/*
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
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
//解决思路主要分为两步：
//第一步：找与B树相同的根节点R；
//第二部：判断以R开始的子树是否包含B树。
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool has=false;
        if(pRoot1==nullptr||pRoot2==nullptr)
        return false;
        if(pRoot1->val==pRoot2->val)//如果当前节点相等，则判断B是不是当前节点的子结构。
        {
            has= isStructrue(pRoot1,pRoot2);
        } 
        if(!has)
        {
           has= HasSubtree(pRoot1->left,pRoot2);
        }
        if(!has)
        {
            has= HasSubtree(pRoot1->right,pRoot2);
        }
            return has;
    }
    bool isStructrue(TreeNode* node1,TreeNode* node2)
    {
        if(node2==nullptr)
        return true;
        if(node1==nullptr)
        return false;
        if(node1->val!=node2->val)
        return false;
        return isStructrue(node1->left,node2->left)&&isStructrue(node1->right,node2->right);
  
    }
};