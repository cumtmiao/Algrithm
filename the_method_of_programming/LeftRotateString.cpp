/************************
��Ŀ������
  ����һ���ַ�����Ҫ���ַ���ǰ������ɸ��ַ��Ƶ��ַ�����β����
  ���磺���ַ���"abcdef"��ǰ3���ַ�'a','b','c'�Ƶ��ַ�����β������ôԭ�ַ�������Ϊ"defabc"��
  ��дһ������ʵ�ִ˹��ܡ�
****************************/
#include<iostream>
#include<string>
using namespace std;
//�ַ���ѭ������һλ��
void LeftShiftOne(char *s,int n)
{
	char t = s[0];
	for (int i = 1; i < n; i++)
	{
		s[i - 1] = s[i];
	}
	s[n-1] = t;

}
//ѭ������mλ�����ⷨһ������������
void LeftRotateString1(char *s,int n,int m)
{
	while (m--)
	{
		LeftShiftOne(s, n);
	}
}

void ReverseString(char * s, int from, int to)//ʵ���ַ����ķ�ת
{
	while (from < to)
	{
		char t = s[from];
		s[from++] = s[to];
		s[to--] = t;
	}
}
void LeftRotateString2(char *s, int n, int m)//�ⷨ����������ת
{
	ReverseString(s, 0, m - 1);
	ReverseString(s, m, n - 1);
	ReverseString(s, 0, n - 1);
}

/*
void main()//�ڶ��ַ�������в���ʱҪע���ַ�����ĳ�ʼ���������
{
	char s[6] = {'a','b','c','d','e','f'};
	cout << "ԭ��Ϊ��";
	for (int i = 0; i < 6; i++)
		cout << s[i];
	cout << endl;
	int n = 6;
	int m = 4;

	LeftRotateString1(s, n, m);
	cout << "�ⷨһ�����Ϊ��";
	for (int i = 0; i < 6; i++)
		cout << s[i];
	cout << endl;

	char t[6] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	LeftRotateString2(t, n, m);
	cout << "�ⷨ�������Ϊ��";
	for (int i = 0; i < 6; i++)
		cout << t[i];
	cout << endl;
}*/
