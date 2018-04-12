/*
题目描述
输入两个整数 n 和 m，从数列1，2，3.......n 中随意取几个数,使其和等于 m ,要求将其中所有的可能组合列出来
输入描述:
每个测试输入包含2个整数,n和m
输出描述:
按每个组合的字典序排列输出,每行输出一种组合
示例1
输入

5 5
输出

1 4
2 3
5
*/
#include<bits/stdc++.h>
using namespace std;
/*
递归的思路求解：DFS
可以画出一颗树，思路会稍微清楚一些。
*/
void dfs(int n,int sum,int index,vector<int>& temp)
{
    if(sum<0)
    return ;
    if(sum==0)
    {
        for(int i=0;i<temp.size();i++)
        {
            if(i!=temp.size()-1)
            cout<<temp[i]<<' ';
            else
            cout<<temp[i];
        }
        cout<<endl;
    }
    for(int i=index;i<=n;i++)
    {
        temp.push_back(i);
        dfs(n,sum-i,i+1,temp);
        temp.pop_back();
    }
    return ;
}
int main()
{
    int n,m;
    vector<int> temp;
    while(cin>>n>>m)
    {
        dfs(n,m,1,temp);
    }
    return 0;
}


