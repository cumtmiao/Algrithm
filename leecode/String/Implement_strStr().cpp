/*
Implement strStr().
Returns the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.
�������⣺�����Ӵ���һ�γ��ֵ�λ�ã�������������
*/
#include<iostream>
#include<string>
using namespace std;

int strStr(string haystack, string needle) {
	int n = haystack.size();
	int m = needle.size();
	if (m == 0)return 0;
	if (m > n)return -1;
	for (int i = 0; i <= n - m; i++)
	{
		int j = i;
		for (; j < i + m; j++)
		{
			if (haystack[j] != needle[j - i])
				break;
		}
		if (j == i + m)
			return i;
	}
	return -1;
}