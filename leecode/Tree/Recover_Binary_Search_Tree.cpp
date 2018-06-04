/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?
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
一种空间复杂度为O(n)的方法。
*/
void inorder(TreeNode* root,vector<TreeNode*>& pointer,vector<int>& value)
{
    if(root==nullptr)
    return;
    if(root->left!=nullptr)
    inorder(root->left,pointer,value);
    pointer.push_back(root);
    value.push_back(root->val);
    if(root->right!=nullptr)
    inorder(root->right,pointer,value);
}
void recoverTree(TreeNode* root) {
    vector<TreeNode*> pointer;
    vector<int> value;
    inorder(root,pointer,value); 
    sort(value.begin(),value.end());
    for(int i=0;i<pointer.size();i++)
    {
        pointer[i]->val=value[i];
    }  
}
/*
O(1)空间复杂度的代码
*/
void swap(TreeNode* first,TreeNode* second)
{
    int temp;
    temp=first->val;
    first->val=second->val;
    second->val=temp;
}
void recoverTree(TreeNode* root) {
    TreeNode* first=nullptr,*second=nullptr,*parent=nullptr;//panrent指针指向的是中序遍历时当前节点之前的那个节点
    TreeNode* pre, *cur;
    cur=root;
    while(cur)
    {
        if(!cur->left)
        {
            if(parent&&parent->val>cur->val)
            {
                if(!first)
                {
                    first=parent;
                }
                second=cur;
            }
            parent=cur;//之前的节点记为parent
            cur=cur->right;//当前节点走到右节点
        }
        else{
            pre=cur->left;
            while(pre->right&&pre->right!=cur)
            pre=pre->right;
            if(!pre->right)//表示当前节点cur与之前节点parent之间的联系还没有建立
            {
                pre->right=cur;//记录当前节点cur之前的节点连接
                cur=cur->left;
            }
            else//表示回溯的过程，当前子树已经访问完，准备回溯到上一级节点
            {
                pre->right=nullptr;//将之前建立好的联系恢复原状态
                if(parent&&parent->val>cur->val)//记录结果指针的位置。
                {
                    if(!first)
                    first=parent;
                    second=cur;
                }
                parent=cur;
                cur=cur->right;
            }
        }
    }
    swap(first,second);
}