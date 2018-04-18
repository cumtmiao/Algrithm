/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes 
v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a 
descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 
and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
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
相当于先序遍历二叉树，查找二叉树中节点的位置；
如果p,q是在当前节点的左右两侧，则当前节点是最近的公共祖先，
如果p,q在当前节点的同一分支，则递归调用。
*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==nullptr)
    return nullptr;
    if(root==p||root==q)
    return root;
    TreeNode* left=lowestCommonAncestor(root->left,p,q);
    TreeNode* right=lowestCommonAncestor(root->right,p,q);
    if(left&&right)
    return root;
    return left!=nullptr?left:right;
}

/*
思路二：先遍历找到到节点p和q的路径，再查找最近公共节点。
假设到p和q的path一定存在
*/
bool findpath(TreeNode* root,TreeNode* p,vector<TreeNode*>& path)//找到到节点的路径
{
    path.push_back(root);
    if(root==p)
    return true;
    bool found=false;
    if(!found&&root->left!=nullptr)
    found=findpath(root->left,p,path);
    if(!found&&root->right!=nullptr)
    found=findpath(root->right,p,path);
    if(!found)
    path.pop_back();
    return found;
}
TreeNode* commonansester(vector<TreeNode*> path1,vector<TreeNode*> path2)//找到两条路径的公共祖先
{
    if(path1.size()==0||path2.size()==0)
    return nullptr;
    TreeNode* res=nullptr;
    for(int i=0;i<path1.size()&&i<path2.size();i++)
    {
        if(path1[i]==path2[i])
        res=path1[i];
    }
    return res;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==nullptr||p==nullptr||q==nullptr)
    return nullptr;
    vector<TreeNode*> path1;
    findpath(root,p,path1);//找到到节点p的路径
    vector<TreeNode*> path2;
    findpath(root,q,path2);//找到到节点q的路径
    return commonansester(path1,path2);//找到两条路径的最近公共祖先
}