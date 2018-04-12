/*
����һ���ַ������������������Ӵ��ĳ���
*/
#include <iostream>
#include<algorithm>
using namespace std;
//����һ��������չ��
int LongestPalindrome1(const char *s, int n)
{
	int i, j,c,max=0;
	//iΪ�������ĵ�λ��
	for (i = 0; i < n; i++)
	{
		//���ʳ���Ϊ����
		for (j = 0; i - j >= 0 && i + j <= n; j++)
		{
			if (s[i - j] != s[i + j])break;
			c = 2 * j + 1;
		}
		if (c>max)max = c;
		//���ĳ���Ϊż��
		for (j = 0; i - j >= 0 && i + j + 1 <= n; j++)
		{
			if (s[i - j] != s[i + j + 1])break;
			c = 2*j + 2;
		}
		if (c > max)max = c;
	}
	return max;
}
//�ⷨ����Manacher�㷨!!!!!!!!!�������� ����������
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
	cout << Longestpalindrome2(a,8);//�������⡣
}