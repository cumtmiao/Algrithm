/*
题目描述
请实现一个算法，确定一个字符串的所有字符是否全都不同。这里我们要求不允许使用额外的存储结构。
给定一个string iniString，请返回一个bool值,True代表所有字符全都不同，False代表存在相同的字符。
保证字符串中的字符为ASCII字符。字符串的长度小于等于3000。
测试样例：
"aeiou"
返回：True
"BarackObama"
返回：False
*/
#include<bits/stdc++.h>
using namespace std;
bool checkDifferent(string iniString) {
    // write code here
    int length=iniString.size();
    if(length==0)
    return true;
    map<char,int> m;
    m.clear();

    for(int i=0;i<length;i++)
    {
        m[iniString[i]]++;
    }
    map<char,int>::iterator it=m.begin();
    for(;it!=m.end();it++)
    {
        if(it->second>1)
        return false;
    }
    return true;
}
int main()
{
    cout<<checkDifferent("fbcdbea");
    getchar();
    return 0;
}