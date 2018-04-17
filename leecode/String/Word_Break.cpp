/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if
s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the 
dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

UPDATE (2017/1/4):
The wordDict parameter had been changed to a list of strings (instead of a set of strings). 
Please reload the code definition to get the latest changes.
*/
#include<bits/stdc++.h>
using namespace std;
/*
本题目使用动态规划的方法。
dp[i]代表：string[0,i-1] 是否可被字典中的单词分割。是的话为1，否的话为0
状态转移方程：
dp[i] = {dp[j]&&string[j,i-1]在字典中，0=<j<i}
*/
bool wordBreak(string s, vector<string>& wordDict) {
    const int length=s.size();
    int dp[length+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=length;i++)
    {
        for(int j=0;j<i;j++)
        {
            //注意这里find是STL函数，vector中查找直接用STL中的find函数即可。
            if(dp[j]==1&&find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))!=wordDict.end())
            {
                dp[i]=1;
                break;
            }
        }
    }
    return dp[length]==1;
}