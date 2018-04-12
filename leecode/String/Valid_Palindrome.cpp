/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring
cases.
For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
Note: Have you consider that the string might be empty? This is a good question to ask during an
interview.
For the purpose of this problem, we define empty string as valid palindrome.
*/
#include<iostream>
#include<string>
using namespace std;
//��Ҫ��
//1.�Լ�дһ����д��ĸתСд��ĸ�ĺ�����
//2.��Ҫ�Լ�дһ���ж��Ƿ�Ϊ��Ч�ַ��ĺ���
bool isAlphaNum(char t)
{
	if (t >= 'a'&&t <= 'z')
		return true;
	if (t >= 'A'&&t <= 'Z')
		return true;
	if (t >= '0'&&t <= '9')
		return true;
	return false;
}
char toLower(char c)
{
	if (c >= 'A'&&c <= 'Z')
		return 'a' + c - 'A';
	return c;
}
bool isPalindrome(string s)
{
	int n = s.size();
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		if (!isAlphaNum(s[left]))
			left++;
		else if (!isAlphaNum(s[right]))
			right--;
		else if (toLower(s[left]) != toLower(s[right]))
			return false;
		else
		{
			left++;
			right--;
		}
	}
	return true;
}