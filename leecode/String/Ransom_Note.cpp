/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
大致题意：能否从字符串magazine的字母中构建字符串ransomNote，其中magazine中每个字符只能用一次
*/

#include<iostream>
#include<string>
#include<map>
using namespace std;
//可以采用哈希的思想
bool canConstruct(string ransomNote, string magazine) {
	int n = magazine.size();
	map<char, int> hashmap;
	for (int i = 0; i < n; i++)//将magazine做哈希处理
	{
		hashmap[magazine[i]]++;
	}
	int m = ransomNote.size();
	for (int i = 0; i < m; i++)//看ransomNote中的某个元素是否能在magazine中找到，如果找到hash值减一，继续找下一个元素；否则返回false 
	{
		if (hashmap.find(ransomNote[i]) == hashmap.end())
			return false;
		else
		{
			hashmap[ransomNote[i]] = hashmap[ransomNote[i]] - 1;
		}
	}
	for (int i = 0; i < n; i++)//hash值中不能存在负值，存在即返回false.否则返回true
	{
		if (hashmap[magazine[i]] < 0)
			return false;
	}
	return true;
}