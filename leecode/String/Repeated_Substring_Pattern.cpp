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
����˼·��
���ԭ���ܹ��ɼ����Ӵ��ظ����ɣ���ô�Ӵ��ĳ���һ��С�ڵ���n/2���Ҵ��ڵ���1��
���ڼٶ��Ӵ��ĳ���Ϊi����ԭ�����Է�Ϊc���Ӵ������c���Ӵ�����һ����ԭ����ȣ��򷵻�true;
���򣬷���false��
*/
bool repeatedSubstringPattern(string s) {
	int n = s.size();
	for (int i = n / 2; i >= 1; i--)
	{
		if (n%i == 0)
		{
			int c = n / i;//��ʾԭ������Ϊ�˶��ٶΡ�
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