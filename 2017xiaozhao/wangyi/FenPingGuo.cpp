/*
题目描述
n 只奶牛坐在一排，每个奶牛拥有 ai 个苹果，现在你要在它们之间转移苹果，使得最后所有奶牛拥有的苹果数都相同，每一次，你只能从一只奶牛身上拿走恰好两个苹果到另一个奶牛上，问最少需要移动多少次可以平分苹果，如果方案不存在输出 -1。
输入描述:
每个输入包含一个测试用例。每个测试用例的第一行包含一个整数 n（1 <= n <= 100），接下来的一行包含 n 个整数 ai（1 <= ai <= 100）。
输出描述:
输出一行表示最少需要移动多少次可以平分苹果，如果方案不存在则输出 -1。
示例1
输入

4
7 15 9 5
输出
3
*/
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int asignment(int number, vector<int> apple)
{
    int sum=0;
    for(int i=0;i<number;i++)//计算和
    {
        sum+=apple[i];
    }
    if(sum%number!=0)//如果不能整除number的话则不能平均分配
    return -1;
    int average=sum/number;
    int res=0;
    for(int i=0;i<number;i++)
    {
        if(abs(apple[i]-average)%2!=0)//如果存在一个数它与average的距离是奇数的话不能分配
        return -1;
        else
        {
            if(apple[i]-average>0)//只统计比average大的
            {
                res+=(apple[i]-average)/2;
            }
        }
    }
    return res;
}
int main()
{
    int number;
    cin>>number;
    vector<int> apple;
    int temp;
    for(int i=0;i<number;i++)
    {
        cin>>temp;
        apple.push_back(temp);
    }
    cout<<asignment(number,apple);
    return 0;
}