/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
["ate", "eat","tea"],
["nat","tan"],
["bat"]
]
*/
/*
�Ƚϵ��͵Ĳ��ù�ϣ˼�����Ŀ��
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
//���ù�ϣ��˼�롣����string  -> ������ͬ�ַ���vector<string>��ӳ��
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	int n = strs.size();
	vector<vector<string>> res;
	map<string, vector<string>> hash;
	for (int i = 0; i < n; i++)
	{
		string tempstr = strs[i];
		sort(tempstr.begin(), tempstr.end());
		hash[tempstr].push_back(strs[i]);//��������ͬ�ַ���ɵ��ַ�������vector��
	}
	map<string, vector<string>>::iterator it;
	for (it = hash.begin(); it != hash.end(); it++)
	{
		res.push_back(it->second);
	}
	return res;
}