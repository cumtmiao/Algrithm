/*
题目描述
输入一个正整数n,求n!(即阶乘)末尾有多少个0？ 比如: n = 10; n! = 3628800,所以答案为2
输入描述:
输入为一行，n(1 ≤ n ≤ 1000)
输出描述:
输出一个整数,即题目所求
示例1
输入

10
输出

2
*/
/*
本题目的实质是统计2-->n的数中：2和5的个数的最小值。
也即统计5的个数。因为5个个数远比2的个数少
*/
#include<bits/stdc++.h>
using namespace std;
int numberof5(int number)
{
    int count=0;
    while(number%5==0)
    {
        count++;
        number=number/5;
    }
    return count;
}
int main()
{
    int n;
    while(cin>>n)
    {
        int count=0;
        for(int i=2;i<=n;i++)
        {
            count+=numberof5(i);
        }
        cout<<count;
    }
    return 0;
}