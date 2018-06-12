/*
有一个1*n的棋盘，上面有若干个棋子，一个格子上可能有多个棋子。
    你每次操作是先选择一个棋子，然后选择以下两个操作中的一个：
    (1) 若该棋子不在 (1,1)，让这个棋子往左走一格，即从 (1,x) 走到 (1,x-1)； 
    (2) 若该棋子不在 (1,n)，且这个棋子曾经到达过(1,1)，让这个格子往右走一格，即从 (1,x) 走到 (1,x+1)。
    给定一开始每个格子上有几个棋子，再给定目标局面每个格子上需要几个棋子，求最少需要多少次操作。

输入描述:
第一行一个正整数n表示棋盘大小。
第二行n个非负整数a_1, a_2, …, a_n 表示一开始 (1,i) 上有几个棋子。
第三行n个非负整数b_1, b_2, …, b_n 表示目标局面里 (1,i) 上有几个棋子。
保证 1 ≤ n ≤ 100,000，

输出描述:
输出一个非负整数，表示最少需要几次操作。
示例1
输入
5
0 0 1 1 0
1 0 0 0 1
输出
9
说明
先把(1,3)上的棋子走到(1,1)，花费了2次操作。
然后把(1,4)上的棋子走到(1,1)，再往右走到(1,5)，花费了3+4=7次操作。
所以一共花了9次操作。
*/
#include <bits/stdc++.h>
using namespace std;
long long A[100009], B[100009];
long long sumofA[100009], sumofB[100009];

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i ++) 
    {
        long long temp1;
        cin>>temp1;
        A[i]=temp1;
    }
    for(int i = 0; i < n; i ++)
    {
        long long temp2;
        cin>>temp2;
        B[i]=temp2;
    }
    for(int i = 0; i < n; i ++)
    {
        if(A[i] >= B[i])
        {
            A[i] = A[i]-B[i];
            B[i] = 0;
        }
        else
        {
            B[i] =B[i]-A[i];
            A[i] = 0;
        }
    }
    sumofA[n]=0;
    sumofB[n]=0;
    for(int i = n-1; i >= 0; i--)
    {
        sumofA[i] = A[i] + sumofA[i+1];
        sumofB[i] = B[i] + sumofB[i+1];
    }
    long long res = 0;
    long long temp = 0;
    for(int i = n-1; i >= 0; i--)
    {
        long long  shengyu=sumofB[i]-temp-sumofA[i];
        if(shengyu>0)
        {
            res += i*shengyu;
            temp = sumofB[i] - sumofA[i];
        }
        else
        {
            if(i != 0)
            res += sumofA[i]-(sumofB[i]-temp);
        }
    }
    cout << res << endl;
    return 0;
}
