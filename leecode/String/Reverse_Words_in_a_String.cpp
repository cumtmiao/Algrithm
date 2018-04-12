/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.
*/
#include<iostream>
#include<string>
using namespace std;
//实现一个word的翻转
void reverseWord(string &s, int i, int j)
{
	while (i < j)
	{
		char c = s[i];
		s[i++] = s[j];
		s[j--] = c;
	}

}
//注意细节的实现关键是对空格的处理
//开头和结尾多余空格的去除；
//中间多余空格的去除
void reverseWords(string &s) {
	int i = 0;//标注原字符串的当前位置
	int j = 0;//标注去除空格后新串的当前位置
	int l = 0;//标注当前word 的起始位置
	int wordcount = 0;//标记词数，当词数为1时，新字符串前不加空格，否则加空格
	int n = s.size();
	while (true)
	{
		while (s[i] == ' '&&i < n)i++;
		if (i == n)break;
		if (wordcount)s[j++] = ' ';
		l = j;
		
		while (i < n&&s[i] != ' ')
		{
			s[j] = s[i];
			i++;
			j++;
		}
		reverseWord(s, l, j - 1);
		wordcount++;
	}
	s.resize(j);//重新调整字符串的大小。
	reverseWord(s, 0, j - 1);//翻转整个字符串
}