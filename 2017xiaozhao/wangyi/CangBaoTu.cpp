/*
题目描述
牛牛拿到了一个藏宝图，顺着藏宝图的指示，牛牛发现了一个藏宝盒，藏宝盒上有一个机关，机关每次会显示两个字符串 s 和 t，
根据古老的传说，牛牛需要每次都回答 t 是否是 s 的子序列。注意，子序列不要求在原字符串中是连续的，
例如串 abc，它的子序列就有 {空串, a, b, c, ab, ac, bc, abc} 8 种。
输入描述:
每个输入包含一个测试用例。每个测试用例包含两行长度不超过 10 的不包含空格的可见 ASCII 字符串。
输出描述:
输出一行 “Yes” 或者 “No” 表示结果。
示例1
输入

x.nowcoder.com
ooo
输出

Yes
*/
/*
利用递归的思路来求解
*/
#include<bits/stdc++.h>
using namespace std;

bool issubsequnce(char* c1,char*c2)
{
    if(*c2=='\0')
    return true;
    while(*c1!='\0'&&*c1!=*c2)
    {
        c1++;
    }
    if(*c1=='\0')
    return false;
    else
    {
        c1++;
        c2++;
        return issubsequnce(c1,c2);
    }
}
int main()
{
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    char* c1=(char*)s1.c_str();
    char* c2=(char*)s2.c_str();
    if(issubsequnce(c1,c2)==true)
    cout<<"Yes";
    else
    cout<<"No";
//getchar();
    return 0;
}