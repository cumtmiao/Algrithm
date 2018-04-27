/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

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
定义了额外的存储空间。不符合题意，
题目要求在原始树的基础上直接转换。
*/
// vector<int> res;
// void preordertraverse(TreeNode* root)
// {
//     if(root==nullptr)
//     return ;
//     res.push_back(root->val);
//     preordertraverse(root->left);
//     preordertraverse(root->right);
// }
// TreeNode* reconstruct(vector<int> res,int &index)
// {
//     if(index==res.size())
//     return nullptr;
//     TreeNode* root=new TreeNode(0);
//     root->val=res[index];
//     index=index+1;
//     root->right=reconstruct(res,index);
//     return root;
// }
// void flatten(TreeNode* root) {
//     preordertraverse(root);
//     int index=0;    
//     root=reconstruct(res,index);
// }
/*
使用先序遍历。先访问到最左子节点，递归将左子树移动到当前节点的右子树，同时将左子树赋值为nullptr；
之后再将原来右子树接到现右子树的末端。
*/
void flatten(TreeNode* root) {
    if(root==nullptr)
    return ;
    if(root->left)
    flatten(root->left);
    if(root->right)
    flatten(root->right);
    TreeNode *temp=root->right;
    root->right=root->left;
    root->left=nullptr;
    while(root->right)
    root=root->right;
    root->right=temp;
    return ;
}