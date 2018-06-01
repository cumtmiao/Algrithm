/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
*/
#include<bits/stdc++.h>
using namespace std;
/*
使用动态规划
dp[i][j]：表示s1的前i个字符和s2的前j个字符能否匹配s2的前i+j个字符.
动态规划方程：
if(dp[i-1][j]&&s1[i-1]==s3[i+j-1])||(dp[i][j-1]&&s2[j-1]==s3[i+j-1])
dp[i][j]=1;
*/
bool isInterleave(string s1, string s2, string s3) {
    int n1=s1.size();
    int n2=s2.size();
    int n3=s3.size();
    if(n1+n2!=n3)
    return false;
    vector<vector<bool>> dp(n1+1,vector<bool>(n2+1,0));
    dp[0][0]=1;
    for(int i=1;i<=n2;i++)
    {
        if(s2[i-1]==s3[i-1])
        dp[0][i]=1;
        else
        break;
    }
    for(int i=1;i<=n1;i++)
    {
        if(s1[i-1]==s3[i-1])
        dp[i][0]=1;
        else
        break;
    }
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            if((dp[i-1][j]&&s1[i-1]==s3[i+j-1])||(dp[i][j-1]&&s2[j-1]==s3[i+j-1]))
            dp[i][j]=1;
        }
    }
    return dp[n1][n2];
}