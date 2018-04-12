/*
Given a string S and a string T, find the minimum window in S which will contain all the 
characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique 
minimum window in S.
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//ע��ʵ�ֵ�ϸ��
string minWindow(string s, string t) {
	if (s.size() == 0 || t.size() == 0 || s.size() < t.size())
		return "";
	vector<int> tmap(256,0);//��ϣ�����t�����ַ����ֵĴ���
	vector<int> smap(256, 0);//��ϣ�����s�����ַ����ֵĴ���
	for (int i = 0; i < t.size(); i++)
	{
		tmap[t[i]]++;
	}
	int start = 0;
	int end = 0;
	int minstart = 0;//��С���ڿ�ʼλ��
	int minend = 0;//��С���ڽ���λ��
	int minwindow = INT_MAX;//��С���ڴ�С
	int count = 0;//������ǰs���г��ֵ�t���ַ��ĸ�����
	for (end = 0; end < s.size(); end++)//ɨ��s����endָ�벻�Ϻ��ơ�
	{ 
		if (tmap[s[end]]>0)//�����ǰ�ַ���t�д���
		{
			smap[s[end]]++;
			if (smap[s[end]] <= tmap[s[end]])//��ǰs���г��ֵ��Ѿ�������t�е��ַ�����û�ﵽt�ĳ���
				count++;
		}
		if (count == t.size())//�ҵ��Ѿ�����t�������ַ��Ĵ���
		{
			while (start<end && (smap[s[start]] > tmap[s[start]] || tmap[s[start]] == 0))//��������ͷָ�룬���Ż����ڴ�С
			{
				smap[s[start]]--;
				start++;
			}
			if (minwindow > (end - start + 1))//���´��ڴ�С����¼��С����
			{
				minwindow = end - start + 1;
				minstart = start;
				minend = end;
			}
		}

	}
	if (minwindow == INT_MAX)
		return "";
	else
		return s.substr(minstart, minwindow);
}