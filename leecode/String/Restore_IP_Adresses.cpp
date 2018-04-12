/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
//判断字符串是否有效
bool isvalid(string s)
{
	if (s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0'))
		return false;
	int res = stoi(s)-stoi("0");
	if (res >= 0 && res <= 255)
		return true;
	else return false;
}
//回溯法。深度优先搜索遍历 
void DFStraceback(string s, int k, vector<string>& res, string curstring)
{
	int n = s.size();
	if (k == 0)
	{
		if (s.empty())
		res.push_back(curstring);
		
	}		
	else
	for (int i = 1; i <= 3; i++)
	{
		if (isvalid(s.substr(0, i)) &&s.size()>=i)
		{
			string s1 = s.substr(i);
				if(k==1)
					DFStraceback(s1, k - 1, res, curstring + s.substr(0, i) );
				else
					DFStraceback(s1, k - 1, res, curstring + s.substr(0, i) + ".");
		}
		
	}
}
vector<string> restoreIpAddresses(string s) {
	vector<string> res;
	string curstring = "";
	DFStraceback(s, 4, res, curstring);
	return res;
}
/*
void main()
{
	vector<string> res;
	res = restoreIpAddresses("010010");
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << ' ' << endl;
	}
}
*/