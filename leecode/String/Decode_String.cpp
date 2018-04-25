/*
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated 
exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for 
those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/
#include<bits/stdc++.h>
using namespace std;
/*
递归的方法求解。
*/
bool isnumber(char c)//判断一个字符是不是数字
{
    return (c-'0')>=0&&(c-'0')<=9;
}
string decodeStringCore(string s,int &i)
{
    string res="";
    int length=s.size();
    while(i<length&&s[i]!=']')
    {
        if(!isnumber(s[i]))//如果是字符，则添加进结果。
        {
            res+=s[i];
            i++;
        }
        else
        {
            int temp=0;
            while(isnumber(s[i]))//解析出‘[’之前的数字
            {
                temp=temp*10+(s[i]-'0');
                i++;
            }
            i++;//跳过‘[’
            string t=decodeStringCore(s,i);//递归找string
            i++;//跳出右括号
            while(temp-->0)
            res+=t;
        }
    }
    return res;
}
string decodeString(string s) {
    int i=0;
    return decodeStringCore(s,i);
}
