/*
题目描述
输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，
则删除之后的第一个字符串变成”Thy r stdnts.”
输入描述:
每个测试输入包含2个字符串
输出描述:
输出删除后的字符串
示例1
输入

They are students. aeiou
输出

Thy r stdnts.
*/
/*
使用哈希：
将第二个字符串哈希存储。
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
       string str1,str2;
        getline(cin,str1);//----这里主要注意输入的格式：两个字符串如何正确的输入
        getline(cin,str2);
        int hash[256];
        memset(hash,0,sizeof(hash));
        for(int i=0;i<str2.size();i++)
        {
            hash[str2[i]]=1;
        }
        string res;
        for(int i=0;i<str1.size();i++)
        {
            if(hash[str1[i]]==0)
            res+=str1[i];
        }
        cout<<res;
   
    return 0;
}