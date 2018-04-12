/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") �� false
isMatch("aa","aa") �� true
isMatch("aaa","aa") �� false
isMatch("aa", "*") �� true
isMatch("aa", "a*") �� true
isMatch("ab", "?*") �� true
isMatch("aab", "c*a*b") �� false
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//��̬�滮�ķ���
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
//̰�����㷨.
/*
˼·
��������������ָ��ֱ�ָ��s��p�ַ�����Ҫƥ���λ�ã�
���ȷ�����ͨ���ƥ������л�����Щ����ǳɹ���

1.s���ַ���p���ַ����
2.p�е��ַ���?����ʱ����s���ַ���ʲô������ƥ��һ��
3.p��������һ��*����ʱ����s���ַ���ʲô��û��ϵ
4.֮ǰ�Ķ������ϣ�����p��֮ǰ��λ����һ��*�����ǿ��Դ���һ��*���濪ʼƥ��
5.s�Ѿ�ƥ���꣬����p���滹�кܶ�������`*
*/
bool isMatch(string s, string p)
{
	int m = s.size();
	int n = p.size();
	int i = 0, j = 0, sstar = 0, pstar = -1;
	while (i < m)
	{
		if (j<n && (s[i] == p[j] || p[j] == '?'))//��һ�����
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