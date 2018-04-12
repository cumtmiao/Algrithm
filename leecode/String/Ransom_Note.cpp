/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
�������⣺�ܷ���ַ���magazine����ĸ�й����ַ���ransomNote������magazine��ÿ���ַ�ֻ����һ��
*/

#include<iostream>
#include<string>
#include<map>
using namespace std;
//���Բ��ù�ϣ��˼��
bool canConstruct(string ransomNote, string magazine) {
	int n = magazine.size();
	map<char, int> hashmap;
	for (int i = 0; i < n; i++)//��magazine����ϣ����
	{
		hashmap[magazine[i]]++;
	}
	int m = ransomNote.size();
	for (int i = 0; i < m; i++)//��ransomNote�е�ĳ��Ԫ���Ƿ�����magazine���ҵ�������ҵ�hashֵ��һ����������һ��Ԫ�أ����򷵻�false 
	{
		if (hashmap.find(ransomNote[i]) == hashmap.end())
			return false;
		else
		{
			hashmap[ransomNote[i]] = hashmap[ransomNote[i]] - 1;
		}
	}
	for (int i = 0; i < n; i++)//hashֵ�в��ܴ��ڸ�ֵ�����ڼ�����false.���򷵻�true
	{
		if (hashmap[magazine[i]] < 0)
			return false;
	}
	return true;
}