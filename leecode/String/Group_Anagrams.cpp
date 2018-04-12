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
比较典型的采用哈希思想的题目！
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
//采用哈希的思想。建立string  -> 具有相同字符的vector<string>的映射
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	int n = strs.size();
	vector<vector<string>> res;
	map<string, vector<string>> hash;
	for (int i = 0; i < n; i++)
	{
		string tempstr = strs[i];
		sort(tempstr.begin(), tempstr.end());
		hash[tempstr].push_back(strs[i]);//将具有相同字符组成的字符串放入vector中
	}
	map<string, vector<string>>::iterator it;
	for (it = hash.begin(); it != hash.end(); it++)
	{
		res.push_back(it->second);
	}
	return res;
}