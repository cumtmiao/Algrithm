/*
题目描述
Fibonacci数列是这样定义的：
F[0] = 0
F[1] = 1
for each i ≥ 2: F[i] = F[i-1] + F[i-2]
因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。
给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X-1或者X+1，
现在给你一个数N求最少需要多少步可以变为Fibonacci数。
输入描述:
输入为一个正整数N(1 ≤ N ≤ 1,000,000)
输出描述:
输出一个最小的步数变为Fibonacci数"
示例1
输入

15
输出

2
*/
#include<bits/stdc++.h>
using namespace std;
int main()//解法一：占用更多的空间
{
    int n;
    cin>>n;
    vector<int> ve;
    int i=0;
    ve.push_back(0);
    ve.push_back(1);
    for(int i=2;ve[i-1]+ve[i-2]<=2000000;i++)
    {
        ve.push_back(ve[i-1]+ve[i-2]);
    }
    int res=INT_MAX;
    for(int i=0;i<ve.size();i++)
    {
        ve[i]=abs(ve[i]-n);
        if(ve[i]<res)
        res=ve[i];
    }
    cout<<res;
    return 0;
}
/*
一个更低时间复杂度的方法
*/

int main()
{
    int n;
    cin>>n;
    int res;
    if(n<=3)
        res=0;
    else
    {
        int temp0=0;
        int temp1=1;
        int temp2;
        for(int i=0;temp1<=n;i++)
        {
            temp2=temp0+temp1;
            temp0=temp1;
            temp1=temp2;
        }
        res=abs(temp1-n)<abs(temp0-n)?abs(temp1-n):abs(temp0-n);
    }
    
    cout<<res;
    return 0;
}