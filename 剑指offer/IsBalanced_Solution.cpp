/*
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
如果某二叉树中任意节点的左，右子树的深度相差不超过1，那么它就是一颗平衡二叉树。
*/
//后序遍历--在遍历的同时求树的深度，每个树节点只需要遍历一次。
bool IsBalanced(TreeNode* pRoot,int *depth)
{
    if(pRoot==nullptr)
    {
        *depth=0;
        return true;
    }
    int left,right;
    if(IsBalanced(pRoot->left,&left)&&IsBalanced(pRoot->right,&right))
    {
        int diff=left-right;
        if(diff>1||diff<-1)
        return false;
        else
        {
            *depth=1+(left>right?left:right);
            return true;
        }
        
    }
    return false;

    
}
bool IsBalanced_Solution(TreeNode* pRoot) {
    int depth=0;
    return IsBalanced(pRoot,&depth);
}