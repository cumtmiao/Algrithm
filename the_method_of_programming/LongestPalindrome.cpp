/*
给定一个字符串，求出它的最长回文子串的长度
*/
#include <iostream>
#include<algorithm>
using namespace std;
//方法一：中心扩展法
int LongestPalindrome1(const char *s, int n)
{
	int i, j,c,max=0;
	//i为回文中心的位置
	for (i = 0; i < n; i++)
	{
		//会问长度为奇数
		for (j = 0; i - j >= 0 && i + j <= n; j++)
		{
			if (s[i - j] != s[i + j])break;
			c = 2 * j + 1;
		}
		if (c>max)max = c;
		//回文长度为偶数
		for (j = 0; i - j >= 0 && i + j + 1 <= n; j++)
		{
			if (s[i - j] != s[i + j + 1])break;
			c = 2*j + 2;
		}
		if (c > max)max = c;
	}
	return max;
}
//解法二：Manacher算法!!!!!!!!!存在问题 ！！！！！
int CalPi( char *S, int n)
{
	int i;
	int mx = 0;
	int id;
	int *p=new int [n];
	for (i = 0; i < n; i++)
	{
		if (mx>i)
		{
			p[i] = min(p[2 * id - i], mx - i);
		}
		else
		{
			p[i] = 1;
		}
		while (S[i + p[i]] == S[i - p[i]])p[i]++;
		if (p[i] + i > mx)
		{
			mx = p[i] + i;
			id = i;
		}
	}
	int max = 0;
	for (i = 0; i < n; i++)
	{
		if (p[i]>max)max = p[i];
	}
	delete[] p;
	return max - 1;

}
int Longestpalindrome2( char *s, int n)
{
	 char *S=new char[2*n+1];
	for (int i = 0,j=0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			S[i] = '#';
		}

		else
		{
			S[i] = s[j];
			j++;
		}
	}
	int x = CalPi(S, 2 * n + 1);
	delete[] S;
	return x;

}

void main()
{
	char a[] = "abcddcba";
	cout<<LongestPalindrome1(a, 8);
	cout << Longestpalindrome2(a,8);//存在问题。
}