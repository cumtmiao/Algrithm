/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.
*/
#include<bits/stdc++.h>
using namespace std;
//使用两个hash来存储两个字符串，再判断两个hash是否相等。
/*
或者使用一个hash,：
当s中的字符出现时，对应的hash值加1；
当t中的字符出现时，对应的hash值减1.
最后判断是否每一个hash都为0；
*/
bool isAnagram(string s, string t) {
    map<char,int> m;
    map<char,int> n;
    if(s.size()!=t.size())
    return false;
    for(int i=0;i<s.size();i++)
    m[s[i]]++;
    for(int i=0;i<t.size();i++)
    n[t[i]]++;
    map<char, int>::iterator it1=m.begin();
    map<char, int>::iterator it2=n.begin();
    for(;it1!=m.end()&&it2!=n.end();it1++,it2++)
    {
        if(*it1!=*it2)
        return false;
    }
    return true;
}