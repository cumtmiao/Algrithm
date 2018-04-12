/*
请实现一个函数，用来判断一颗二叉树是不是对称的。
注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
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

bool issymmetrical(TreeNode* pRoot1,TreeNode* pRoot2)
{
    if(pRoot1==nullptr&&pRoot2==nullptr)
    {
        return true;
    }
    if(pRoot1==nullptr||pRoot2==nullptr)
    {
        return false;
    }
    if(pRoot1->val!=pRoot2->val)
    {
        return false;
    }
    return issymmetrical(pRoot1->left,pRoot2->right)&&issymmetrical(pRoot1->right,pRoot2->left);
}
 bool isSymmetrical(TreeNode* pRoot)
 {
     return issymmetrical(pRoot,pRoot);
 }