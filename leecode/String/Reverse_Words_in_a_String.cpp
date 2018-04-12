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
//ʵ��һ��word�ķ�ת
void reverseWord(string &s, int i, int j)
{
	while (i < j)
	{
		char c = s[i];
		s[i++] = s[j];
		s[j--] = c;
	}

}
//ע��ϸ�ڵ�ʵ�ֹؼ��ǶԿո�Ĵ���
//��ͷ�ͽ�β����ո��ȥ����
//�м����ո��ȥ��
void reverseWords(string &s) {
	int i = 0;//��עԭ�ַ����ĵ�ǰλ��
	int j = 0;//��עȥ���ո���´��ĵ�ǰλ��
	int l = 0;//��ע��ǰword ����ʼλ��
	int wordcount = 0;//��Ǵ�����������Ϊ1ʱ�����ַ���ǰ���ӿո񣬷���ӿո�
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
	s.resize(j);//���µ����ַ����Ĵ�С��
	reverseWord(s, 0, j - 1);//��ת�����ַ���
}