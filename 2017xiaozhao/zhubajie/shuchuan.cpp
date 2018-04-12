/*
题目描述
设有n个正整数，将他们连接成一排，组成一个最大的多位整数。
如:n=3时，3个整数13,312,343,连成的最大整数为34331213。
如:n=4时,4个整数7,13,4,246连接成的最大整数为7424613。
输入描述:
有多组测试样例，每组测试样例包含两行，第一行为一个整数N（N<=100），第二行包含N个数(每个数不超过1000，空格分开)。
输出描述:
每组数据输出一个表示最大的整数。
示例1
输入

2
12 123
4
7 13 4 246
输出

12312
7424613
*/
#include<bits/stdc++.h>
using namespace std;
bool compare(string a,string b)//定义一种新的比较关系。两个比较的元素是字符串，排序规则是两个字符串连接起来后比较大的字符串排在前面
{
    return (a+b)>(b+a);
}

int main()
{
    int n;
    while(cin>>n)
    {
        vector<string> res;
        for(int i=0;i<n;i++)
        {
            string temp;
            cin>>temp;
            res.push_back(temp);
        }
        sort(res.begin(),res.end(),compare);
        for(int i=0;i<n;i++)
        {
            cout<<res[i];
        }
    }
    return 0;
}