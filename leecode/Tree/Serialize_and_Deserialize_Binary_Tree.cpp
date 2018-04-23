/*
Serialization is the process of converting a data structure or object into a sequence of bits so 
that it can be stored in a file or memory buffer, or transmitted across a network connection link 
to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your 
serialization/deserialization algorithm should work. You just need to ensure that a binary tree can 
be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. 
You do not necessarily need to follow this format, so please be creative and come up with different 
approaches yourself.
*/
#include<bits/stdc++.h>
#include<string>
#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
我的方法时间超时。AC：45/48
*/
void serializecore(TreeNode* root,vector<string>& v)
{
    if(root==NULL)
    {
        v.push_back("null");
        return;
    }
    //v.push_back(to_string(root->val));
    ostringstream out;
    out<<root->val;
    v.push_back(out.str());
    serializecore(root->left,v);
    serializecore(root->right,v);
}
// Encodes a tree to a single string.
string serialize(TreeNode* root) {//依据DFS来序列化
    vector<string> res;
    string str;
    serializecore(root,res);
    for(int i=0;i<res.size();i++)
    {
        if(i==res.size()-1)
        {
            str+=res[i];
        }
        else
        {
            str+=res[i]+',';
        }
    }
    return str;
}

TreeNode* deserializecore(vector<string> res,int & index)
{
    if(res[index].compare("null")==0)
    return NULL;
    TreeNode* root=new TreeNode(atoi(res[index].c_str()));
    index=index+1;
    root->left=deserializecore(res,index);
    index=index+1;
    root->right=deserializecore(res,index);
    return root;
}
// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    cout<<data;
    vector<string> res;
    int l=0;
    int r=0;
    while(data[r]!='\0')
    {
        if(data[r]==',')
        {
            res.push_back(data.substr(l,r-l));
            r++;
            l=r;
        }
        else
        {
            r++;
        }
    }
    res.push_back(data.substr(l,r-l));
    int index=0;
    for(int i=0;i<res.size();i++)
    {cout<<res[i]<<' ';}
    return deserializecore(res,index);
}   

TreeNode* CreateBiTree(TreeNode* &T){  
 //按先序输入二叉树中结点的值（一个字符），空格字符代表空树，  
 //构造二叉树表表示二叉树T。  
 int ch;  
 cin>>ch;
 if(ch==-1)//其中getchar（）为逐个读入标准库函数  
 {
     T=NULL;
 }
 else{  
  T=new TreeNode(0);//产生新的子树  
  T->val=ch;//由getchar（）逐个读入来  
  T->left=CreateBiTree(T->left);//递归创建左子树  
  T->right=CreateBiTree(T->right);//递归创建右子树  
 }  
 return T;
}
int main()
{
    TreeNode* T;
    T=CreateBiTree(T);
    string res=serialize(T);
    cout<<res;
    deserialize(res);

    return 0;
}


// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    ostringstream out;
    serialize(root, out);
    return out.str();
}
// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    istringstream in(data);
    return deserialize(in);
}

void serialize(TreeNode *root, ostringstream &out) {
    if (root) {
        out << root->val << ' ';
        serialize(root->left, out);
        serialize(root->right, out);
    } else {
        out << "# ";
    }
}
TreeNode* deserialize(istringstream &in) {
    string val;
    in >> val;
    if (val == "#") return nullptr;
    TreeNode *root = new TreeNode(stoi(val));
    root->left = deserialize(in);
    root->right = deserialize(in);
    return root;
}