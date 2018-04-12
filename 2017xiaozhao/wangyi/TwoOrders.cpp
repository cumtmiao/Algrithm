/*
题目描述
考拉有n个字符串，任意两个字符串长度都是不同的。考拉最近学习到有两种字符串的排序方法： 
1.根据字符串的字典序排序。例如：
"car" < "carriage" < "cats" < "doggies < "koala"
2.根据字符串的长度排序。例如：
"car" < "cats" < "koala" < "doggies" < "carriage"
考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验证。
输入描述:
输入第一行为字符串个数n(n ≤ 100)
接下来的n行,每行一个字符串,字符串长度均小于100，均由小写字母组成
输出描述:
如果这些字符串是根据字典序排列而不是根据长度排列输出"lexicographically",

如果根据长度排列而不是字典序排列输出"lengths",

如果两种方式都符合输出"both"，否则输出"none"
示例1
输入

3
a
aa
bbb
输出

both
*/

#include<bits/stdc++.h>
using namespace std;
bool isdictionaryorder(string s1,string s2)//判断两个字符串是不是相对字典序排列
{
    int i;
    for(i=0;i<s1.size()&&i<s2.size();)
    {
        if(s1[i]<s2[i])
        return true;
        else if (s1[i]==s2[i])
        {
            i++;
        }
        else
        return false;
    }
    if(i==s1.size())
    return true;
    else
    return false;
}
bool isfirstorder(vector<string> str)//判断一个字符串数组是不是字典序排列
{
    for(int i=0;i<str.size()-1;i++)
    {
        if(!isdictionaryorder(str[i],str[i+1]))
        return false;
    }
    return true;
}
bool issecondorder(vector<string> str)//判断一个字符串是不是按照字符串的长短排列
{
    for(int i=0;i<str.size()-1;i++)
    {
        if(str[i].size()>str[i+1].size())
        return false;
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    vector<string> str;
    for(int i=0;i<n;i++)//初始化字符串数组
    {
        string tempstr;
        cin>>tempstr;
        str.push_back(tempstr);
    }
    if(isfirstorder(str)&&issecondorder(str))
    cout<<"both";
    else if (isfirstorder(str))
    {
        cout<<"lexicographically";
    }
    else if (issecondorder(str))
    {
        cout<<"lengths";
    }
    else
    cout<<"none";
    return 0;

}