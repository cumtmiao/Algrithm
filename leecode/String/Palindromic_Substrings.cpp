/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
Note:
The input string length won't exceed 1000.
*/
#include<string>
using namespace std;
bool isPalindromic(string s)//判断一个给定字符串是否为回文串
{
	int n = s.size();
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		if (s[left] != s[right])
		{
			return false;
		}
		left++;
		right--;
	}
	return true;
}
int countSubstrings(string s) {
	int n = s.size();
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n - i; j++)
		{
			if (isPalindromic(s.substr(i, j)))//遍历所有子串，如果是回文串，则计数加一。
			{
				num++;
			}
		}
	}
	return num;
}