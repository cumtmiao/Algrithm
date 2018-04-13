/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of
 s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
 

Example:

Input: "cbbd"

Output: "bb"
*/
#include<bits/stdc++.h>
using namespace std;
/*
思路一：时间复杂度为O（n^2），相当于暴力的解法。（中心扩展法）
*/
int maxlength=INT_MIN;//定义最大回文子串的长度
int low=0;//定义最大回文串的起始位置。
void extendhuiwen(string s,int start,int end)
{
    while(start>=0&&end<s.size()&&s[start]==s[end])
    {
        start--;
        end++;
    }
    if(end-start-1>maxlength)
    {
        maxlength=end-start-1;
        low=start+1;
    }
}
string longestPalindrome(string s) {
    int length=s.size();
    string res="";
    if(length<2)
    return s;
    for(int i=0;i<length;i++)
    {
        extendhuiwen(s,i,i);//当回文是奇数时，计算回文的最长长度
        extendhuiwen(s,i,i+1);//当回文是偶数时，计算回文的最长长度。
    }
    return s.substr(low,maxlength);
}