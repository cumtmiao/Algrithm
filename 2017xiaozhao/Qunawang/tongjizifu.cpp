/*
题目描述
给定一个英文字符串,请写一段代码找出这个字符串中首先出现三次的那个英文字符。
输入描述:
输入数据一个字符串，包括字母,数字等。
输出描述:
输出首先出现三次的那个英文字符
示例1
输入

Have you ever gone shopping and
输出

e
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    while(getline(cin,str))
    {
        map<char,int> m;
        for(int i=0;i<str.size();i++)
        {
           if(isalpha(str[i]))//判断一个字符是不是字母
           {
                m[str[i]]++;
                if(m[str[i]]==3)
                {
                    cout<<str[i];
                    break;
                }
           }
        }
    }
    return 0;
}