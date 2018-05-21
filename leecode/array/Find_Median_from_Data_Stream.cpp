/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no 
middle value. So the median is the mean of the two middle value.

For example,
[2,3,4] , the median is 3 

[2,3], the median is (2 + 3) / 2 = 2.5 

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
*/
/*
思路一：
此处数据结构我使用的是：BST树。插入一个节点O(lgn),查找一个节点O(n)或者O(lgn)--查找时间复杂度较大 。
AC通过，不过时间复杂度略大。
*/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode1{
    int val;
    int num;//表示当前节点存储的个数
    TreeNode1* left;
    TreeNode1* right;
    TreeNode1(int x):val(x),num(1),left(NULL),right(NULL){}
};
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        number=0;
        root=NULL;
    }
    void insert(TreeNode1* root,TreeNode1* temp)
    {
        if(root->val==temp->val)
        {
            root->num=root->num+1;
        }
        else if (root->val<temp->val)
        {
            if(root->right!=NULL)
            insert(root->right,temp);
            else
            root->right=temp;
        }
        else
        {
            if(root->left!=NULL)
            insert(root->left,temp);
            else
            root->left=temp;
        }
    }
    void addNum(int num) {//增加一个数
        number++;
        if(root==NULL)//如果根还没有建立，赋值为根
        root=new TreeNode1(num);
        else//否则，将这个数插入树中
        {
        TreeNode1* temp=new TreeNode1(num);
        insert(root,temp);
        }
    }
    void KthSmallestCore(TreeNode1* root,int k,TreeNode1** mem,int& num,bool& flag)//中序遍历二叉树，如果访问到第k个节点，则记录下位置，返回
    {
        if(root->left!=NULL)
        KthSmallestCore(root->left,k,mem,num,flag);
        num=num+root->num;
        if(num<k)
        {
            if(root->right!=NULL)
            KthSmallestCore(root->right,k,mem,num,flag);//此处，flag记录是否已经记录过mem
        }
        else
        {
            if(flag==false)
            {
                *mem=root;
                flag=true;
            }
            return;
        }
    }
    int kthSmallest(TreeNode1* root, int k) {
        TreeNode1* mem=root;
        int num=0;
        bool flag=false;
        KthSmallestCore(root,k,&mem,num,flag);
        return mem->val;
    }
    double findMedian() {//查找中位数
        double ret;
        if(number%2==1)
        {
            int find=number/2+1;//找第find大的数
            ret=1.0*kthSmallest(root,find);
        }
        else
        {
            int find1=number/2;
            int find2=find1+1;
            int res1=kthSmallest(root,find1);
            int res2=kthSmallest(root,find2);
            ret=(res1+res2)*1.0/2;
        }
        return ret;
    }
    int number;//表示数据结构中有几个数
    TreeNode1 *root;//BST树的根节点。
};
int main()
{
    MedianFinder obj;
    obj.addNum(-1);
    double find1 = obj.findMedian();
    cout<<find1<<endl;

    obj.addNum(-2);
    double find2 = obj.findMedian();
    cout<<find2<<endl;
    
    obj.addNum(-3);
    double find3 = obj.findMedian();
    cout<<find3<<endl;
    
    getchar();
    return 0;
}

/*
思路二：参考网上的思路：用两个堆来实现。
当前数目为偶数的时候数字加入最小堆。
当前数目为奇数的时候数字加入最大堆。
插入一个数O(logn),
查找一个数O(1)
*/
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if((min.size()+max.size())%2==0)
        {
            if(max.size()!=0&&num<max[0])
            {
                max.push_back(num);
                push_heap(max.begin(),max.end(),less<int>());
                num=max[0];
                pop_heap(max.begin(),max.end(),less<int>());
                max.pop_back();
            }
            min.push_back(num);
            push_heap(min.begin(),min.end(),greater<int>());
        }
        else
        {
            if(!min.empty()&&num>min[0])
            {
                min.push_back(num);
                push_heap(min.begin(),min.end(),greater<int>());
                num=min[0];
                pop_heap(min.begin(),min.end(),greater<int>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(),max.end(),less<int>());
        }
    }
    double findMedian() {
        if((min.size()+max.size())%2==0)
        {
            return (min[0]+max[0])*1.0/2;
        }
        else
        return min[0];
    }
    vector<int> min;//最小堆，存放比较大的一半数
    vector<int> max;//最大堆，存放比较小的一半数
};