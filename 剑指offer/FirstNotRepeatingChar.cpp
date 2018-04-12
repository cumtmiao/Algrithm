/*
在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置。
*/
#include<bits/stdc++.h>
using namespace std;
int FirstNotRepeatingChar(string str) {//两次扫描字符串。
    int length=str.size();
    if(length==0)
    return -1;
    map<char,int> m;
    for(int i=0;i<length;i++)//第一次扫描字符串，记录每个字符出现的次数
    {
        m[str[i]]++;
    }
    int i;
    for(i=0;i<length&&m[str[i]]!=1;i++);//第二次扫描字符串，找到第一个出现一次的字符。
    if(i==length)
    return -1;
    return i;
}