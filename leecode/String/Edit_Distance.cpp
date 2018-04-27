/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/
#include<bits/stdc++.h>
using namespace std;
/*
使用动态规划，dp[i][j]:表示字符串word1前i个字符和字符串word2前j个字符的最短编辑距离。
考察word1的第i位变为word2的第j位有以下3中情况：
1.空格->字符：(相当于word1插入一个字符变为word2)dp[i][j]=dp[i][j-1]+1;
2.字符->空格：（相当于word1删除一个字符变为word2）dp[i][j]=dp[i-1][j]+1;
3.字符->字符：（相当于word1替换一个字符变为word2）dp[i][j]=dp[i-1][j-1]+(字符A==字符B?0:1);
*/
int minDistance(string word1, string word2) {
    int length1=word1.size();
    int length2=word2.size();
    vector< vector<int> > dp(length1+1,vector<int>(length2+1,0));
    for(int i=0;i<=length1;i++)//初始化第0行和第0列
    {
        dp[i][0]=i;
    }
    for(int i=0;i<=length2;i++)
    {
        dp[0][i]=i;
    }
    for(int i=1;i<=length1;i++)
    {
        for(int j=1;j<=length2;j++)
        {
            if(word1[i-1]==word2[j-1])//判断第i个字符是不是相等
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
            }
        }
    }
    return dp[length1][length2];
}