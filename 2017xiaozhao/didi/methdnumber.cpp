/*
题目描述
给定一个有n个正整数的数组A和一个整数sum,求选择数组A中部分数字和为sum的方案数。
当两种选取方案有一个数字的下标不一样,我们就认为是不同的组成方案。
输入描述:
输入为两行:
 第一行为两个正整数n(1 ≤ n ≤ 1000)，sum(1 ≤ sum ≤ 1000)
 第二行为n个正整数A[i](32位整数)，以空格隔开。
输出描述:
输出所求的方案数
示例1
输入

5 15 5 5 10 2 3
输出

4
*/
#include<bits/stdc++.h>
using namespace std;

int numberofmethod(vector<int> data,int index,int sum)//递归的方法，世家复杂度过大。只有大概50%样例通过
{
    if(index==data.size())
    {
        if(sum>0||sum<0)
        return 0;
        if(sum==0)
        return 1;
    }
    if(sum<0)
    return 0;
    else if(sum==0)
    return 1;
    else
    return numberofmethod(data,index+1,sum)+numberofmethod(data,index+1,sum-data[index]);
}
int main()
{
    int n,sum;
    while(cin>>n>>sum)
    {
        vector<int> data;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            data.push_back(temp);
        }
        cout<<numberofmethod(data,0,sum);
    }
    return 0;
}

/*
思路二：
动态规划的方法：
关键是如何定义dp:
dp[i][j]：前i个元素和为j的方法数
*/
long long dp[1001][1001];
int main()
{
    int n,sum;
    while(cin>>n>>sum)
    {
        int data[n+1];
        for(int i=1;i<=n;i++)
        {
            int temp;
            cin>>temp;
            data[i]=temp;
        }
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        for(int j=1;j<=n;j++)
        {
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(j>=data[i])
                dp[i][j]=dp[i-1][j]+dp[i-1][j-data[i]];
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        cout<<dp[n][sum];
    }
    return 0;
}