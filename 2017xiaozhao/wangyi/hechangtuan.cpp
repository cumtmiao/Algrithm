/*
题目描述
有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，
要求相邻两个学生的位置编号的差不超过 d，使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？
输入描述:
每个输入包含 1 个测试用例。每个测试数据的第一行包含一个整数 n (1 <= n <= 50)，表示学生的个数，接下来的一行，
包含 n 个整数，按顺序表示每个学生的能力值 ai（-50 <= ai <= 50）。接下来的一行包含两个整数，k 和 d 
(1 <= k <= 10, 1 <= d <= 50)。
输出描述:
输出一行表示最大的乘积。
示例1
输入

3
7 4 7
2 50
输出

49
*/
#include<bits/stdc++.h>
using namespace std;
int k,d,n;
long long maxvalue=INT_MIN;

void dfs(vector<int> a,int index,long long  multi,int num)//采用DFS的思想只能通过80%的测试用例
{
    if(num==k)
    {
        if(multi>maxvalue)
        maxvalue=multi;
        return ;
    }
    if(index==0)
    {
        for(int i=index;i<n-k+1;i++)
        {
            if(a[i]!=0)
            {
                multi*=a[i];
                num++;
                dfs(a,i+1,multi,num);
                num--;
                multi/=a[i];
            }

        }
    }
    else
    {
        for(int i=index;i<index+d&&i<n;i++)
        {
            if(a[i]!=0)
            {
                multi*=a[i];
                num++;
                dfs(a,i+1,multi,num);
                num--;
                multi/=a[i];
            }
        }
    }

    return ;
}
int main()
{
    while(cin>>n)
    {
        vector<int> a;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            a.push_back(temp);
        }
        cin>>k>>d;
        long long multi=1;
        dfs(a,0,multi,0);
        cout<<maxvalue;
    }
    return 0;
}

/*
思路二：
采用动态规划的思想：
f[k][n]:表示选出k个学生，其中第k个学生以n为结束位置的最大值;
g[k][n]:表示选出k个学生，其中第k个学生以n为结束位置的最小值;
*/
int main()
{
    int n;
    while(cin>>n)
    {
        int student[n+1];
        for(int i=0;i<n;i++)//数据输入
        {
            int temp;
            cin>>temp;
            student[i+1]=temp;
        }
        int k,d;
        cin>>k>>d;
        long f[k+1][n+1];//表示选出k个学生，其中第k个学生以n为结束位置的最大值。
        long g[k+1][n+1];//表示选出k个学生，其中第k个学生以n为结束位置的最小值。
        for(int i=1;i<=n;i++)//选出一个学生，以i结尾的最大值和最小值
        {
            f[1][i]=student[i];
            g[1][i]=student[i];
        }
        for(int i=2;i<=k;i++)//选出i个学生
        {
            for(int j=i;j<=n;j++)//第i个学生的结束位置
            {
                long tempmax=LONG_MIN;
                long tempmin=LONG_MAX;
                for(int l=max(i-1,j-d);l<=j-1;l++)//这个for循环是为了找出f[i][j]和g[i][j]
                {
                    if(tempmax<max(f[i-1][l]*student[j],g[i-1][l]*student[j]))
                    {
                        tempmax=max(f[i-1][l]*student[j],g[i-1][l]*student[j]);
                    }
                    if(tempmin>min(f[i-1][l]*student[j],g[i-1][l]*student[j]))
                    {
                        tempmin=min(f[i-1][l]*student[j],g[i-1][l]*student[j]);
                    }
                }
                f[i][j]=tempmax;
                g[i][j]=tempmin;
            }
        }
        long res=LONG_MIN;
        for(int i=k;i<=n;i++)
        {
            if(res<f[k][i])
            res=f[k][i];
        }
        cout<<res;
    }
    return 0;
}