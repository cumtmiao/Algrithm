/*
给定一颗二叉搜索树，请找出其中的第k大的结点。
例如:
      5
     / \
     3 7 
    /\ /\
   2 4 6 8 ，
   按结点数值大小顺序第三个结点的值为4。
*/
//实际上考察的是树的中序遍历。
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

TreeNode* KthNodeCore(TreeNode* root,int &k)//注意此处是k的引用。
{
    TreeNode* target=nullptr;
    if(root->left!=nullptr)//左子树不为空，在左子树中查找第k大的节点。
    {
        target=KthNodeCore(root->left,k);
    }
    if(target==nullptr)//如果左子树中没找到，则当前节点k--;
    {
        if(k==1)
        target=root;
        k--;
    }
    if(target==nullptr&&root->right!=nullptr)//，如果左子树和根节点都没找到，则在右子树中查找
    {
        target=KthNodeCore(root->right,k);
    }
    return target;
}
TreeNode* KthNode(TreeNode* pRoot, int k)
{
    if(pRoot==nullptr||k<1)
    return nullptr;
    return KthNodeCore(pRoot,k);
}