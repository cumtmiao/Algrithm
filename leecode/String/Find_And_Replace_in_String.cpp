/*
To some string S, we will perform some replacement operations that replace groups of letters with new ones (not necessarily the same size).

Each replacement operation has 3 parameters: a starting index i, a source word x and a target word y.  The rule is that if x starts at position i in the original string S, then we will replace that occurrence of x with y.  If not, we do nothing.

For example, if we have S = "abcd" and we have some replacement operation i = 2, x = "cd", y = "ffff", then because "cd" starts at position 2 in the original string S, we will replace it with "ffff".

Using another example on S = "abcd", if we have both the replacement operation i = 0, x = "ab", y = "eee", as well as another replacement operation i = 2, x = "ec", y = "ffff", this second operation does nothing because in the original string S[2] = 'c', which doesn't match x[0] = 'e'.

All these operations occur simultaneously.  It's guaranteed that there won't be any overlap in replacement: for example, S = "abc", indexes = [0, 1], sources = ["ab","bc"] is not a valid test case.

Example 1:

Input: S = "abcd", indexes = [0,2], sources = ["a","cd"], targets = ["eee","ffff"]
Output: "eeebffff"
Explanation: "a" starts at index 0 in S, so it's replaced by "eee".
"cd" starts at index 2 in S, so it's replaced by "ffff".
Example 2:

Input: S = "abcd", indexes = [0,2], sources = ["ab","ec"], targets = ["eee","ffff"]
Output: "eeecd"
Explanation: "ab" starts at index 0 in S, so it's replaced by "eee". 
"ec" doesn't starts at index 2 in the original S, so we do nothing.
Notes:

0 <= indexes.length = sources.length = targets.length <= 100
0 < indexes[i] < S.length <= 1000
All characters in given inputs are lowercase letters.
*/
#include<bits/stdc++.h>
using namespace std;
bool canreplace(string s1,int p, string s2)
{
    int j=0;
    while(p<s1.size()&&j<s2.size())
    {
        if(s1[p]!=s2[j])
        return false;
        p++;
        j++;
    }
    if(j==s2.size())
    return true;
    return false;
}
string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
    string res="";
    int n=indexes.size();
    vector<bool> mem(S.size(),0);//记录字符串的每个位置是否可以置换
    map<int,string> m1;//记录字符串位置与目标串的映射
    map<int,string> m2;//记录字符串位置与原串的映射
    for(int i=0;i<n;i++)
    {
        bool tempres=canreplace(S,indexes[i],sources[i]);
        mem[indexes[i]]=tempres;
        if(tempres==true)
        {
            m1[indexes[i]]=targets[i];
            m2[indexes[i]]=sources[i];
        }
    }
    for(int i=0;i<S.size();)
    {
        if(mem[i]==false)
        {
            res+=S[i];
            i++;
        }
        else
        {
            res+=m1[i];
            i+=m2[i].size();
        }
    }
    return res;
}
int main()
{
    string s;
    while(cin>>s)
    {
        vector<int> index;
        vector<string> source;
        vector<string> target;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            index.push_back(temp);
        }
        for(int i=0;i<n;i++)
        {
            string str;
            cin>>str;
            source.push_back(str);
        }
        for(int i=0;i<n;i++)
        {
            string str;
            cin>>str;
            target.push_back(str);
        }
        cout<<findReplaceString(s,index,source,target);
    }
    return 0;
}