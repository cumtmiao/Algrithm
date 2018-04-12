/*
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
则重建二叉树并返回。
*/
/*
递归的思路来解决；
关键是递归的时候准确找到每一段的开始和结束位置。
*/
#include<iostream>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


  class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
       int l_pre=pre.size();
       int l_vin=vin.size();
       if(l_pre<=0||l_vin<=0||l_pre!=l_vin)
       return nullptr;
     return reConstructCore(pre,0,l_pre-1,vin,0,l_vin-1);

    }
    TreeNode* reConstructCore(vector<int> pre, int start1,int end1,vector<int> vin,int start2,int end2)
    {
        TreeNode* root=new TreeNode(0);
        int rootint=pre[start1];
        root->val=rootint;
        root->left=root->right=nullptr;
        if(start1==end1)
        {
            if(start2==end2&&pre[start1]==vin[start2])
            return root;
            /*else
            throw std::exception("invalid input");*/
        }
        int i=start2;
        for(;i<=end2&&vin[i]!=rootint;i++);//找根节点在中序数组中的位置
       /* if(i>end2)
          throw std::exception("invalid input");*/
        int length_left=i-start2;//左半部分长度
        int left_end1=start1+length_left;//左子树的结束位置
        if(length_left>0)
        root->left=reConstructCore(pre,start1+1,left_end1,vin,start2,i-1);//递归左子树
        if(end1-start1-length_left>0)
        root->right=reConstructCore(pre,left_end1+1,end1,vin,i+1,end2);//递归右子树
        return root;
    }
};
 
