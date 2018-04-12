/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".
*/
#include<iostream>
#include<string>
using namespace std;
//判断给定的一个字母是不是元音字母
bool isVowels(char c)
{
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
		|| c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}
string reverseVowels(string s) {
	int n = s.size();
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		if (isVowels(s[left]) && isVowels(s[right]))
		{
			char temp = s[left];
			s[left] = s[right];
			s[right] = temp;
			left++;
			right--;
		}
		else if (isVowels(s[left]))
		{
			right--;
		}
		else if (isVowels(s[right]))
		{
			left++;
		}
		else
		{
			left++;
			right--;
		}
	}
	return s;
}