/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//动态规划的方法
bool isMatch(string s, string p) {
	int m = s.size();
	int n = p.size();
	vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
	dp[0][0] = true;
	for (int i = 1; i <= n; i++)
	{
		if (p[i-1] == '*')
			dp[0][i] = dp[0][i - 1];
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (p[j - 1] != '*')
			{
				dp[i][j] = dp[i - 1][j - 1] && (s[i-1] == p[j-1] || p[j-1] == '?');
			}
			else
			{
				dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
			}
		}
	}
	return dp[m][n];
}
//贪婪的算法.
/*
思路
假设我们用两个指针分别指向s和p字符串中要匹配的位置，
首先分析下通配符匹配过程中会有哪些情况是成功：

1.s的字符和p的字符相等
2.p中的字符是?，这时无论s的字符是什么都可以匹配一个
3.p中遇到了一个*，这时无论s的字符是什么都没关系
4.之前的都不符合，但是p在之前的位置有一个*，我们可以从上一个*后面开始匹配
5.s已经匹配完，但是p后面还有很多连续的`*
*/
bool isMatch(string s, string p)
{
	int m = s.size();
	int n = p.size();
	int i = 0, j = 0, sstar = 0, pstar = -1;
	while (i < m)
	{
		if (j<n && (s[i] == p[j] || p[j] == '?'))//第一种情况
		{
			i++;
			j++;
		}
		else if (j<n&&p[j] == '*')
		{
			pstar = j++;
			sstar = i;
		}
		else if (pstar >= 0)
		{
			j = pstar + 1;
			i = ++sstar;
		}
		else return false;
	}
	while (j<n&&p[j] == '*')j++;
	return j == n;
}