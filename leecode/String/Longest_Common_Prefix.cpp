/*
Write a function to find the longest common prefix string amongst an array of strings.
�ҵ�һ��string�������ǰ׺��
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//����һ��(Vertical scanning)
//�����������ÿһ��Ԫ�أ�Ȼ��������һ�У�ֱ������strs[0]��ĩβ��
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