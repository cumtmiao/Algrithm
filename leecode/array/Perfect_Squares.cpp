/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) 
which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/
#include<bits/stdc++.h>
using namespace std;
int numSquares(int n) {//解法一：递归，时间超时。
    int sqrtn=sqrt(n);
    if(sqrtn*sqrtn==n)
    return 1;
    int res=INT_MAX;
    for(int i=1;i<=n/2;i++)
    {
        res=min(res,numSquares(i)+numSquares(n-i));
    }
    return res;
}
/*
解法二:动态规划
*/
int numSquares(int n)//时间仍然超时，
{
    if(n==0||n==1)
    return n;
    int data[n+1];
    data[1]=1;
    for(int i=2;i<=n;i++)
    {
        int sqrtn=sqrt(i);
        if(sqrtn*sqrtn==i)
        data[i]=1;
        else
        {
            data[i]=INT_MAX;
            for(int j=1;j<=i/2;j++)
            {
                data[i]=min(data[i],data[j]+data[i-j]);
            }
        }
    }
    return data[n];
}

/*
优化后的动态规划算法。AC
优化的动态规划算法状态转移方程很巧妙
*/
int numSquares(int n)//
{
    int data[n+1];
    for(int i=0;i<=n;i++)
    {
        data[i]=INT_MAX;
    }
    for(int i=1;i*i<=n;i++)//先更新平方数为1；
    {
        data[i*i]=1;
    }
    for(int i=1;i<=n;i++)//针对每个小于等于n的数更新比它大“平方数”的数
    {
        for(int j=1;i+j*j<=n;j++)
        {
            data[i+j*j]=min(data[i]+1,data[i+j*j]);
        }   
    }
    return data[n];
}