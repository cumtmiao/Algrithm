/*
题目描述
给定一个正整数，编写程序计算有多少对质数的和等于输入的这个正整数，并输出结果。输入值小于1000。
如，输入为10, 程序应该输出结果为2。（共有两对质数的和为10,分别为(5,5),(3,7)）
输入描述:
输入包括一个整数n,(3 ≤ n < 1000)
输出描述:
输出对数
示例1
输入

10
输出

2
*/
#include<bits/stdc++.h>
using namespace std;
bool issushu(int number)//判断一个数字是不是素数
{
    if(number==1)
    return false;
    if(number==2)
    return true;
    if(number%2==0)
    return false;
    for(int i=3;i<=sqrt(number);)
    {
        if(number%i==0)
        return false;
        i+=2;
    }
    return true;
}
int main()
{
    int n;
    int num=0;
    while(cin>>n)
    {
        for(int i=3;i<=n/2;)
        {
            if(issushu(i)&&issushu(n-i))
            num++;
            i+=2;
        }
        if(issushu(n-2))num++;
        cout<<num;
    }
    return 0;
}