/*
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。
输入描述:
输入一个字符串,包括数字字母符号,可以为空
输出描述:
如果是合法的数值表达则返回该数字，否则返回0
*/
/*
考虑字符串是否有效：
考虑一个个字符有可能是+,-,；
考虑到字符串中非数字的出现；
考虑到只有可能是一个+,-的情况。
考虑到超过边界的情况----本实现方案中没实现---正整数的最大值0x7FFFFFFF；负整数的最小值0x80000000
*/
#include<bits/stdc++.h>
using namespace std;
bool isValid(char * str)//判断输入的字符串是否有效
{
    if(*str!='+'&&*str!='-'&&((*str)>'9'||(*str)<'0'))
    return false;
    if((*str=='+'||*str=='-')&&(*(str+1)=='\0'))//判断是不是只有一个"+"或"-”
    return false;
    str++;
    while(*str!='\0')
    {
        if((*str)>'9'||(*str)<'0')
        return false;
        
        str++;
    }
    return true;
}
int convert(char * str)//将字符串转换为int,在转换的过程中没有考虑超过整数边界的情况，如果考虑则需要修改代码。仍可以AC
{
    int sum=0;
    while(*str!='\0')
    {
        sum=(sum*10)+(*str-'0');
        str++;
    }
    return sum;
}
int StrToInt(string str) {
    char *s=(char*)str.c_str();
    if(!isValid(s))
    {
        return 0;
    }
    //string * s=&str;
    int res=0;
    if(*s=='+')
    {
        res= convert(++s);
    }
    else if (*s=='-')
    {
        res=-1*convert(++s);
    }
    else
    {
        res=convert(s);
    }
    return res;
}

int main()
{
    string s="123";
    cout<<StrToInt(s);
    getchar();
    return 0;
}