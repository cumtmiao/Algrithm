/*
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,
则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
*/
/*
本题目自己实现的时候比较僵硬，是典型的递归问题。
原问题可以分为两步来解决：
1.求所有可能出现在第一个位置的字符，相当于遍历字符长度，交换字符；
2.固定第一个字符，求后面所有字符的全排列--这一步相当于递归操作。
3.当递归到字符的末尾时结束，将当前字符串插入到结果集当中。
需要注意：当递归结束后，再把交换了顺序的字符交换回来。
*/
#include<bits/stdc++.h>
using namespace std;
void PermutationCore(string str,vector<string> &res,int step)
{
    if(step==str.size())
    {
        res.push_back(str);
        return;
    }
    for(int i=step;i<str.size();i++)
    {
        if(i!=step&&str[step]==str[i])
        {
            continue;
        }
        swap(str[step],str[i]);
        PermutationCore(str,res,step+1);
        swap(str[step],str[i]);
    }
   
}
vector<string> Permutation(string str) {
    int length=str.size();
    vector<string> res;
    if(length==0)
    return res;
    PermutationCore(str,res,0);
    sort(res.begin(),res.end());
    return res;
}