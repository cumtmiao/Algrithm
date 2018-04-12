/*
����һ�����ַ���a��һ�����ַ���b��
���ʣ���ο��ٵ��жϳ����ַ���b�е������ַ��Ƿ��ڳ��ַ���a��?
���дbool StringContain(string &a,string &b)ʵ�ִ˹��ܡ�
*/
#include<iostream>
#include <string>
#include<algorithm>
using namespace std;
//�ⷨһ��������ѯ
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
//�ⷨ�����������ѯ
bool StringContain2(string & a, string& b)
{
	sort(a.begin(), a.end());//ֱ��include<algorithm>���������������ṩ�������㷨��
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
//�ⷨ����λ���㷨���㷨�ؼ����Ӷ�O(1)��ʱ�临�Ӷ�O(m+n)
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