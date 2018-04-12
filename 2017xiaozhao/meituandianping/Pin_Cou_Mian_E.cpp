/*
题目描述
给你六种面额1、5、10、20、50、100元的纸币，假设每种币值的数量都足够多，编写程序求组成N员（N为0-10000的非负整数）
的不同组合的个数。
输入描述:
输入为一个数字N，即需要拼凑的面额
输出描述:
输出也是一个数字，为组成N的组合个数。
示例1
输入

5
输出

2
*/
#include<bits/stdc++.h>
using namespace std;
// int dfs(int N,int* data,int index)//递归方方法时间复杂度过大，只能通过70%的实例。
// {
//     if(N<0)
//     return 0;
//     if(N==0)
//     return 1;
//     int num=0;
//     for(int i=index;i<6;i++)
//     {
//         num+=dfs(N-data[i],data,i);
//     }
//     return num;
// }
// int main()
// {
//     int N;
//     int data[6]={1,5,10,20,50,100};
//     while(cin>>N)
//     {
//         cout<<dfs(N,data,0);
//     }
//     return 0;
// }
/*
关键是定义最优子结构：
A(n,m):最大面值为m，所构成的值为n的方法数。
递归转移方程：
A(n,m)=A(n-m,m)+A(n,m-);其中m-表示比m小的下一个最大面值。
边界值：A(0,i)和A(i,0)都为1
*/
int main()//动态规划的方法
{
    int N;
    int data[6]={1,5,10,20,50,100};
    
    while(cin>>N)
    {
        //int data1[6][N+1];//data[i][j]表示j元钱由最大面值不超过data[i]，构成的方法数
        vector<long> dp(N+1,1);
        for(int i=1;i<6;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(j>=data[i])
                dp[j]+=dp[j-data[i]];
            }
        }
        cout<<dp[N];
    }
    return 0;
}

