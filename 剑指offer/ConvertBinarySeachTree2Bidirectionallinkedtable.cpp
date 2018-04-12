/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
*/
#include<bits/stdc++.h>
usinag namespace std;
//中序遍历--需要维护一个指针pLastNode，指向中序遍历的上一个节点。
void ConvertCore(TreeNode* pRoot,TreeNode** pLastNode)
{
    if(pRoot==nullptr)
    return;
    if(pRoot->left!=nullptr)//递归访问左子树。
    ConvertCore(pRoot->left,pLastNode);
    pRoot->left=*pLastNode;//当前节点的左指针指向中序遍历的上一个节点
    if((*pLastNode)!=nullptr)//如果上一个节点不为空，则它的右子节点指向当前节点。
    (*pLastNode)->right=pRoot;
    *pLastNode=pRoot;//更新上一个节点指针，使其指向当前节点。
    if(pRoot->right!=nullptr)//递归访问右子树。
    ConvertCore(pRoot->right,pLastNode);
}
TreeNode* Convert(TreeNode* pRootOfTree)
{
    TreeNode* pLastNode=nullptr;
    ConvertCore(pRootOfTree,&pLastNode);
    TreeNode* head=pLastNode;
    while(head!=nullptr&&head->left!=nullptr)//找到双向链表的头结点。
    {   
        head=head->left;
    }
    return head;
}