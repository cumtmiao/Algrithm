/**************************************************************************************
***************************************************************************************
Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.

1       2(abc)  3(def)
4(ghi)  5(jkl)  6(mno)
7(pqrs) 8(tuv)  9(wxyz)
*       0       #

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Although the above answer is in lexicographical order, your answer could be in any order you want.
*****************************************************************************************
*****************************************************************************************/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//ʹ�õ����ķ�����
vector<string> letterCombinations(string digits) {
	vector<string> mapping = { " ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	int n = digits.size();
	vector<string> res1;
	if (n == 0)return res1;
	vector<string> res({""});
	for (int i = 0; i < n; i++)//��ǰdigits�ĵ�i��λ��
	{
		vector<string> temp;
		for (int k = 0; k < res.size(); k++)//��ǰ�����
		{
			for (int j = 0; j < mapping[digits[i] - '0'].size(); j++)//��ǰ��������Ӧ���ַ����
			{
				temp.push_back(res[k] + mapping[digits[i] - '0'][j]);;
			}
		}
		res = temp;	
	}
	return res;
}
//ʹ�õݹ�ķ�����ע����⿴�����ʵ�ֵݹ�����ġ�
void dfstraceback(string& digits, int index, string curstring, string mapping[], vector<string>&res)
{
	if (index == digits.size())
	{
		res.push_back(curstring);
	}
	else
	for (int i = 0; i < mapping[digits[index] - '0'].size(); i++)
	{
		char temp= mapping[digits[index] - '0'][i];
		dfstraceback(digits, index + 1, curstring+temp, mapping, res);//ע���ں����������У���constʵ�������ܸ�ֵ�����õ��βΡ�
	}
}
vector<string> letterCombinations2(string digits) {
	string mapping[] = { " ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	vector<string>res;
	//char curstring = new char[digits.size()];
	if (digits.size() == 0)return res;
	string curstring= "";
	dfstraceback(digits, 0, curstring, mapping, res);
	return res;
}
/*
void main()
{
	string digits;
	digits = "32";
	vector<string> res;
	res=letterCombinations2(digits);
//	cout << digits[0];
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}
}
*/