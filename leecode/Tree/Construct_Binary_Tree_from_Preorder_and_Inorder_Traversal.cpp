/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
根据先序遍历结果和后序遍历结果构建二叉树的思路比较简单：
1.在前序序列里找到根节点。
2.在中序序列里找到根节点。
3.递归构建左子树
4.递归构建右子树
*/
TreeNode* buildTreeCore(vector<int> preorder,int startpre,int endpre, vector<int> inorder,int startin,int endin)
{
    if(endpre<startpre||endin<startin)
    return nullptr;
    TreeNode* root=new TreeNode(0);
    root->val=preorder[startpre];
    int rootposinorder;//根节点在中序序列中的位置
    for(int i=startin;i<=endin;i++)
    {
        if(inorder[i]==root->val)
        {
            rootposinorder=i;
            break;
        }
    }
    //if(rootposinorder-startin>0)//左子树节点个数大于0，递归
    root->left=buildTreeCore(preorder,startpre+1,startpre+rootposinorder-startin,inorder,startin,rootposinorder-1);
    //if(endpre-startpre-(rootposinorder-startin)>0)//右子树节点个数大于0，递归
    root->right=buildTreeCore(preorder,startpre+rootposinorder-startin+1,endpre,inorder,rootposinorder+1,endin);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.size()==0||inorder.size()==0||preorder.size()!=inorder.size())
    return nullptr;
    return buildTreeCore(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);

}