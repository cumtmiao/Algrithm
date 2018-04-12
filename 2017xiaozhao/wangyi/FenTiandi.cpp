/*
题目描述
牛牛和 15 个朋友来玩打土豪分田地的游戏，牛牛决定让你来分田地，地主的田地可以看成是一个矩形，每个位置有一个价值。
分割田地的方法是横竖各切三刀，分成 16 份，作为领导干部，牛牛总是会选择其中总价值最小的一份田地， 
作为牛牛最好的朋友，你希望牛牛取得的田地的价值和尽可能大，你知道这个值最大可以是多少吗？
输入描述:
每个输入包含 1 个测试用例。每个测试用例的第一行包含两个整数 n 和 m（1 <= n, m <= 75），
表示田地的大小，接下来的 n 行，每行包含 m 个 0-9 之间的数字，表示每块位置的价值。
输出描述:
输出一行表示牛牛所能取得的最大的价值。
示例1
输入

4 4
3332
3233
3332
2323
输出

2
*/
/*
注意实现过程中的几个细节：
1.数组data[][]和数组su[][]存储数据的时候都是从[1][1]往后存的，data[][]和sum[][]的第一行和第一列都初始化为0.
2.计算矩阵的部分和时，包含右下角元素所在的行和列，但是不包含左上角元素所在的行和列。
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=80;
int data[maxn][maxn];
int sum[maxn][maxn];
int n,m;
int sumofmatrix(int i,int j,int x,int y)//左上角为（i，j）,右下角为（x,y）的矩形区域的面积。
{
    int sum1=sum[x][y]-sum[x][j]-sum[i][y]+sum[i][j];
    return sum1;
}
bool check(int mid)//检查是不是16个部分每个部分都大于mid,如果是当前二分要找的值在mid的右边
{
    for(int i=1;i<m-2;i++)
    {
        for(int j=i+1;j<m-1;j++)
        {
            for(int k=j+1;k<m;k++)
            {
                int count=0;
                int last=0;
                for(int r=1;r<=n;r++)
                {
                    if((sumofmatrix(last,0,r,i)>mid)&&
                       (sumofmatrix(last,i,r,j)>mid)&&
                       (sumofmatrix(last,j,r,k)>mid)&&
                       (sumofmatrix(last,k,r,m)>mid))
                       {
                           last=r;
                           count++;
                       }
                }
                if(count>=4)
                return true;
            }
        }
    }
    return false;
}
int main()
{
    cin>>n>>m;
    string temp;
    memset(data,0,sizeof(data));
    for(int i=1;i<=n;i++)//构建data数组---存储的是数据
    {
        cin>>temp;
        for(int j=1;j<=m;j++)
        {
            data[i][j]=temp[j-1]-'0';
        }
    }
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++)//构建部分和数组，存储的是以当前元素为右下角，（0,0）为左上角的矩阵的部分和
    {
        for(int j=1;j<=m;j++)
        {
            sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+data[i][j];
        }
    }
    int average=sum[n][m]/16;
    int left=0;
    int right=average;//牛牛可能获得的最大值不会超过avarage
    while(left<right)
    {
        int mid=(left+right)>>1;
        if(check(mid))
        {
            left=mid+1;
        }
        else
        {
            right=mid;
        }
    }
    cout<<right;
    return 0;
}