/*
Write a function to find the longest common prefix string amongst an array of strings.
找到一组string的最长公共前缀。
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//方法一：(Vertical scanning)
//首先纵向检索每一个元素，然后再右移一列，直到到达strs[0]的末尾。
string longestCommonPrefix(vector<string>& strs) {
	int n = strs.size();
	string res = "";
	if (n == 0)return res;
	for (int i = 0; i < strs[0].size(); i++)
	{		
		for (int j = 0; j < n; j++)
		{
			if (i == strs[j].size() || strs[j][i] != strs[0][i])
				return res;
		}
		res = res + strs[0][i];		
	}
	return res;
}
/*
void main()
{
	vector<string> strs;
	strs.push_back("c");
	strs.push_back("c");
	cout<<longestCommonPrefix(strs);
}
*/