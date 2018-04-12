/*
题目描述
现在有一棵合法的二叉树，树的节点都是用数字表示，现在给定这棵树上所有的父子关系，求这棵树的高度
输入描述:
输入的第一行表示节点的个数n（1 ≤ n ≤ 1000，节点的编号为0到n-1）组成，
下面是n-1行，每行有两个整数，第一个数表示父节点的编号，第二个数表示子节点的编号
输出描述:
输出树的高度，为一个整数
示例1
输入

5
0 1
0 2
1 3
1 4
输出

3
*/
#include<bits/stdc++.h>
using namespace std;
int main()//只能AC50%,但是我认为这个思路更清晰，相当于求多叉树的深度
{
    int n;
    while(cin>>n)
    {
        vector<vector<int>> data;
        int res=INT_MIN;

        for(int i=1;i<=n-1;i++)//构建二维数组
        {
            vector<int> temp;
            int left,right;
            cin>>left>>right;
            temp.push_back(left);
            temp.push_back(right);
            data.push_back(temp);
        }
        int hight[1000]={1};
        sort(data.begin(),data.end());
        for(int i=0;i<n-1;i++)
        {
            
            hight[data[i][1]]=hight[data[i][0]]+1;
            if(hight[data[i][1]]>res)
            res=hight[data[i][1]];               
        }
        cout<<res;
    }
    return 0;

}

/*
思路二：居然通过了。。。如果当前节点的儿子节点超过3个，则跳过
*/
int main()
{
    int n;
    while(cin>>n)
    {
        vector<vector<int>> data;
        int res=INT_MIN;
        int hash[1000];//存储每个父节点有几个孩子
        memset(hash,0,sizeof(hash));
        int hight[1000]={1};
        for(int i=0;i<n-1;i++)//构建二维数组
        {
            vector<int> temp;
            int left,right;
            cin>>left>>right;
            temp.push_back(left);
            hash[left]++;
            temp.push_back(right);
            data.push_back(temp);
            if(hash[left]<3)
            {
                 hight[data[i][1]]=hight[data[i][0]]+1;
                if(hight[data[i][1]]>res)
                res=hight[data[i][1]];  
            }
        }
        
 
        cout<<res;
    }
    return 0;
}