/************************
题目描述：
  给定一个字符串，要求将字符串前面的若干个字符移到字符串的尾部。
  例如：将字符串"abcdef"的前3哥字符'a','b','c'移到字符串的尾部，那么原字符串将变为"defabc"。
  请写一个函数实现此功能。
****************************/
#include<iostream>
#include<string>
using namespace std;
//字符串循环左移一位。
void LeftShiftOne(char *s,int n)
{
	char t = s[0];
	for (int i = 1; i < n; i++)
	{
		s[i - 1] = s[i];
	}
	s[n-1] = t;

}
//循环左移m位。（解法一：蛮力方法）
void LeftRotateString1(char *s,int n,int m)
{
	while (m--)
	{
		LeftShiftOne(s, n);
	}
}

void ReverseString(char * s, int from, int to)//实现字符串的翻转
{
	while (from < to)
	{
		char t = s[from];
		s[from++] = s[to];
		s[to--] = t;
	}
}
void LeftRotateString2(char *s, int n, int m)//解法二：三步反转
{
	ReverseString(s, 0, m - 1);
	ReverseString(s, m, n - 1);
	ReverseString(s, 0, n - 1);
}

/*
void main()//在对字符数组进行操作时要注意字符数组的初始化和输出。
{
	char s[6] = {'a','b','c','d','e','f'};
	cout << "原串为：";
	for (int i = 0; i < 6; i++)
		cout << s[i];
	cout << endl;
	int n = 6;
	int m = 4;

	LeftRotateString1(s, n, m);
	cout << "解法一结果串为：";
	for (int i = 0; i < 6; i++)
		cout << s[i];
	cout << endl;

	char t[6] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	LeftRotateString2(t, n, m);
	cout << "解法二结果串为：";
	for (int i = 0; i < 6; i++)
		cout << t[i];
	cout << endl;
}*/
