/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be 
larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/
#include<bits/stdc++.h>
using namespace std;
/*
方法一：暴力解法
*/
vector<int> findAnagrams(string s, string p)
{
    int ns=s.size();
    int np=p.size();
    vector<int> res;
    if(np==0||ns==0||ns<np)
    return res;
    int i=0;
    vector<int> m(256,0);
    for(int k=0;k<np;k++)
    {
        m[p[k]]++;
    }
    while(i<=ns-np)
    {
        bool success=true;
        vector<int> temp=m;

        for(int j=i;j<i+np;j++)
        {
            if(--temp[s[j]]<0)
            {
                success=false;
                break;
            } 
        }
        if(success==true)
        res.push_back(i);
        i++;
    }
    return res;
}
/*
滑动窗口的办法。
*/
// vector<int> findAnagrams(string s, string p) {
//     int ns=s.size();
//     int np=p.size();
//     vector<int> res;
//     if(np==0||ns==0||ns<np)
//     return res;
//     int count=np;//count表示还有多少个字符需要匹配  
//     vector<int> m(256,0);//定义一个哈希表，存放p中的字符与数量的映射
//     for(int i=0;i<np;i++)//将串p映射到hash表。
//     {
//         m[p[i]]++;
//     }
//     int left=0,right=0;//定义一个滑动窗口left,right分别表示滑动窗口的左边界和右边界
//     //当右边界访问到字符串s的一个字符时，它的哈希值减一，当左边界访问到一个字符时，哈希值加1.
//     //如果右边界访问的当前字符串在原始p串中出现过，则count--;
//     //如果count变为0，则表示当前滑动窗口内的字符串与p完全匹配。此时将left放入结果集
//     //如果right-left==np并且当前滑动窗口的左边界指向的字符在p中出现过，则count++
//     while(right<ns)
//     {
//         if(m[s[right++]]-->=1)count--;
//         if(count==0)res.push_back(left);
//         if(right-left==np&&m[s[left++]]++>=0)count++;
//     }
//     return res;
// }
int  main()
{
    string s1;
    string s2;
    while(cin>>s1>>s2)
    {
        vector<int> res;
        res=findAnagrams(s1,s2);
        for(int i=0;i<res.size();i++)
        {
            cout<<res[i]<<' ';
        }
    }
}