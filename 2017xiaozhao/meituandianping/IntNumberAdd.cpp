/*
题目描述
请设计一个算法能够完成两个用字符串存储的整数进行相加操作，对非法的输入则返回error
输入描述:
输入为一行，包含两个字符串，字符串的长度在[1,100]。
输出描述:
输出为一行。合法情况输出相加结果，非法情况输出error
示例1
输入

123 123
abd 123
输出

246
Error
*/
#include<bits/stdc++.h>
using namespace std;
bool isValid(string str)//判断一个字符串是不是整数。
{
    for(int i=0;i<str.size();i++)
    {
        if(str[i]>'9'||str[i]<'0')
        return false;
    }
    return true;
}
void traverse(char * start,char* end)//翻转一个字符串
{
    while(start<end)
    {
        char temp;
        temp=*start;
        *start=*end;
        *end=temp;
        start++;
        end--;
    }
}
string add(string str1,string str2)//实现两个字符串的相加
{
    int carray=0;
    traverse(&str1[0],&str1[str1.size()-1]);
    traverse(&str2[0],&str2[str2.size()-1]);
    string res;
    int i;
    for(i=0;i<str1.size()||i<str2.size();i++)//i没有超过任意一个字符串的长度
    {
        if(i<str1.size()&&i<str2.size())
        {
            int temp=(str1[i]-'0')+(str2[i]-'0')+carray;
            if(temp>9)
            {
                carray=1;
                res+='0'+(temp-10);
            }
            else
            {
                carray=0;
                res+='0'+temp;
            }
        }
        else if (i<str1.size())
        {
            int temp=(str1[i]-'0')+carray;
            if(temp>9)
            {
                carray=1;
                res+='0'+(temp-10);
            }
            else
            {
                carray=0;
                res+='0'+temp;
            }
        }
        else{
            int temp=(str2[i]-'0')+carray;
            if(temp>9)
            {
                carray=1;
                res+='0'+(temp-10);
            }
            else
            {
                carray=0;
                res+='0'+temp;
            }
        } 

    }
    if(carray==1)//最后判断有没有进位，有的话，记得加上
    res+='0'+1;
    traverse(&res[0],&res[res.size()-1]);
    return res;
}
int main()
{
    string str1,str2;
    while(cin>>str1>>str2)
    {
        if(isValid(str1)&&isValid(str2))
        {
            cout<<add(str1,str2);
        }
        else
        cout<<"error";
    }
    return 0;
}