/*
题目描述
有一个X*Y的网格，小团要在此网格上从左上角到右下角，只能走格点且只能向右或向下走。
请设计一个算法，计算小团有多少种走法。给定两个正整数int x,int y，请返回小团的走法数目。
输入描述:
输入包括一行，逗号隔开的两个正整数x和y，取值范围[1,10]。
输出描述:
输出包括一行，为走法的数目。
示例1
输入

3 2
输出

10
*/
/*
简单的动态规划
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    int y;
    while(cin>>x>>y)
    {
        int data[x+1][y+1];
        for(int i=0;i<=x;i++)
        {
            data[i][y]=1;
        }
        for(int j=0;j<=y;j++)
        {
            data[0][j]=1;
        }
        for(int i=1;i<=x;i++)
        {
            for(int j=y-1;j>=0;j--)
            {
                data[i][j]=data[i][j+1]+data[i-1][j];
            }
        }
        cout<<data[x][0];
    }
    return 0;
}