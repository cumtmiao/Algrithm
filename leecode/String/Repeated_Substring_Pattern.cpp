/*
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/
#include<string>
using namespace std;

/*
基本思路：
如果原串能够由几个子串重复构成，那么子串的长度一定小于等于n/2并且大于等于1，
现在假定子串的长度为i，且原串可以分为c个子串，如果c个子串连在一起与原串相等，则返回true;
否则，返回false。
*/
bool repeatedSubstringPattern(string s) {
	int n = s.size();
	for (int i = n / 2; i >= 1; i--)
	{
		if (n%i == 0)
		{
			int c = n / i;//表示原串被分为了多少段。
			string temp = "";
			for (int j = 0; j < c; j++)
			{
				temp += s.substr(0, i);
			}
			if (temp == s)return true;
		}
	}
	return false;
}