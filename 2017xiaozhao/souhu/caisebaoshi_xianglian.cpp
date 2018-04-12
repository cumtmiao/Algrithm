/*
题目描述
有一条彩色宝石项链，是由很多种不同的宝石组成的，包括红宝石，蓝宝石，钻石，翡翠，珍珠等。
有一天国王把项链赏赐给了一个学者，并跟他说，你可以带走这条项链，但是王后很喜欢红宝石，蓝宝石，紫水晶，
翡翠和钻石这五种，我要你从项链中截取连续的一小段还给我，这一段中必须包含所有的这五种宝石，剩下的部分你可以带走。
如果无法找到则一个也无法带走。请帮助学者找出如何切分项链才能够拿到最多的宝石。
输入描述:
我们用每种字符代表一种宝石，A表示红宝石，B表示蓝宝石，C代表紫水晶，D代表翡翠，E代表钻石，F代表玉石，G代表玻璃等等，
我们用一个全部为大写字母的字符序列表示项链的宝石序列，注意项链是首尾相接的。每行代表一种情况。
输出描述:
输出学者能够拿到的最多的宝石数量。每行一个
示例1
输入

ABCYDYE
ATTMBQECPD
输出

1
3
*/
#include<bits/stdc++.h>
using namespace std;
bool istargetchar(char c)//判断一个字符是不是包含的目标字符
{
    if(c=='A'||c=='B'||c=='C'||c=='D'||c=='E')
    return true;
    else
    return false;
}
int lengthofcontainstr( int i,string str,int length)//求包含所有目标字符的子串的长度
{
    int num=0;
    int start=i;
    char hash[5];
    memset(hash,0,sizeof(hash));
    while(hash[0]==0||hash[1]==0||hash[2]==0||hash[3]==0||hash[4]==0)
    {
        if(i-start==length)
        return 0;
        if(istargetchar(str[i]))
        hash[str[i]-'A']++;
        i++;
        num++;
    }
    return num;
    
}
int main()
{
    string str;
    while(cin>>str)
    {
        int length=str.size();
        str+=str;
        int minvalue=INT_MAX;
        for(int i=0;i<length;i++)
        {
            if(istargetchar(str[i]))
            {
            if(lengthofcontainstr(i,str,length)<minvalue)
            minvalue=lengthofcontainstr(i,str,length);
            }

        }
        cout<< length-minvalue;
    }
    return 0;
}