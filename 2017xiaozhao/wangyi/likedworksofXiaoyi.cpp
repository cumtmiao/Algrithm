/*
题目描述
小易喜欢的单词具有以下特性：
1.单词每个字母都是大写字母
2.单词没有连续相等的字母
3.单词没有形如“xyxy”(这里的x，y指的都是字母，并且可以相同)这样的子序列，子序列可能不连续。
例如：
小易不喜欢"ABBA"，因为这里有两个连续的'B'
小易不喜欢"THETXH"，因为这里包含子序列"THTH"
小易不喜欢"ABACADA"，因为这里包含子序列"AAAA"
小易喜欢"A","ABA"和"ABCBA"这些单词
给你一个单词，你要回答小易是否会喜欢这个单词。
输入描述:
输入为一个字符串，都由大写字母组成，长度小于100
输出描述:
如果小易喜欢输出"Likes",不喜欢输出"Dislikes"
示例1
输入

AAA
输出

Dislikes
*/
#include<bits/stdc++.h>
using namespace std;
bool isupper(string s1)//全是大写返回true
{
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]-'A'<0||s1[i]-'Z'>0)
        return false;
    }
    return true;
}
bool notwoequle(string s1)//如果没有两个连续的字符相等，返回true,否则返回false
{
    for(int i=0;i<s1.size()-1;i++)
    {
        if(s1[i]==s1[i+1])
        return false;
    }
    return true;
}
bool subsequece(string s1)//存在这样的子序列返回true，否则返回false--暴力查找
{
    if(s1.size()<4)
    return false;
    for(int i=0;i<s1.size()-3;i++)
    {
        for(int  j=i+1;j<s1.size()-2;j++)
        {
            for(int k=j+1;k<s1.size()-1;k++)
            {
                if(s1[k]==s1[i])
                {
                    for(int l=k+1;l<s1.size();l++)
                    {
                        if(s1[l]==s1[j])
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
int main()
{
    string str;
    cin>>str;
    if(isupper(str)&&notwoequle(str)&&!subsequece(str))
    cout<<"Likes";
    else
    cout<<"Dislikes";
    return 0;
}