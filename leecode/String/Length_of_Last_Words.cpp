/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.
*/
#include<iostream>
#include<string>
using namespace std;
int lengthOfLastWord(string s) {
	int n = s.size();
	if (n == 0)return 0;
	int flag = 0;
	int count = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] == ' '&&flag==0)continue;
		while (s[i] != ' '&&i >= 0)//从后往前找到第一个Word，并计数
		{
			flag = 1;
			count++;
			i--;
		}
		if (flag == 1)break;
	}
	return count;
}