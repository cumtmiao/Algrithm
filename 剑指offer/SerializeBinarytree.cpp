/*
请实现两个函数，分别用来序列化和反序列化二叉树
*/
//比较坑的地方就是char* string 的转换与应用。
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


void SerializeCore(TreeNode* root,string& c)//具体序列化的代码，利用前序遍历
{
    if(root==nullptr)
    {
        c+='$';
        return ;
    }
    string r=to_string(root->val);
    c+=r;
    c+=','; 
    SerializeCore(root->left,c);
    SerializeCore(root->right,c);
    return;
}
char* Serialize(TreeNode *root) {    
    string c="";
    SerializeCore(root,c);
    //char* res=(char*)c.c_str();
    char* res=new char[c.size()+1];
    int i;
    for(i=0;i<c.size();i++)
    {
        res[i]=c[i];
    }
    res[i]='\0';
    return res;
}




TreeNode* DeserializeCore(char** c)//具体反序列化的代码，利用递归。
{
    if(**c=='$')
    {
          (*c)++;
          return nullptr;
    }
  
    int num=0;
    while((**c)!='\0'&&(**c)!=',')
    {
        num=num*10+((**c)-'0');
        (*c)++;
    }
    TreeNode* node=new TreeNode(num);

    if((**c)=='\0')
    {
        return node;
    }
    else 
    {
        (*c)++;      
    }
    node->left=DeserializeCore(c);
    node->right=DeserializeCore(c);
    return node;

}
TreeNode* Deserialize(char *str) {
    if(str==nullptr)
    return nullptr;

    return DeserializeCore(&str);//指针str在递归的过程中是有可能变化的，所以传参数的时候要传str的地址。
}