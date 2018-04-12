/*
给定一个长字符串a和一个短字符串b。
请问，如何快速的判断出短字符串b中的所有字符是否都在长字符串a中?
请编写bool StringContain(string &a,string &b)实现此功能。
*/
#include<iostream>
#include <string>
#include<algorithm>
using namespace std;
//解法一：蛮力轮询
bool StringContain1(string &a, string &b)
{
	for (int i = 0; i < b.length(); i++)
	{
		int j;
		for (j = 0; (j < a.length()) && a[j] != b[i]; j++);
		if (j >= a.length()){ return false; }
	}
	return true;
	
}
//解法二：排序后轮询
bool StringContain2(string & a, string& b)
{
	sort(a.begin(), a.end());//直接include<algorithm>，即可利用其中提供的排序算法。
	sort(b.begin(), b.end());
	for (int pa = 0,pb=0; pb < b.length();)
	{
		while ((pa < a.length()) && (a[pa] < b[pb]))
		{
			pa++;
		}
		if ((pa >= a.length()) || a[pa]>b[pb])
		{
			return false;
		}
		++pb;
	}
	return true;
}
//解法三：位运算法。算法控件复杂度O(1)，时间复杂度O(m+n)
bool StringContain3(string &a, string &b)
{
	int hash = 0;
	for (int i = 0; i < a.length(); i++)
	{
		hash |= (1 << (a[i] - 'A'));
	}
	for (int j = 0; j < b.length(); j++)
	{
		if ((hash&(1 << (b[j] - 'A'))) == 0)
			return false;
	}
	return true;
}
/*void main()
{
	string a = "ABCD";
	string b = "ABBBB";
	cout<<StringContain2(a, b);
}*/