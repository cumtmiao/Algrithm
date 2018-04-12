/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//�ݹ鷨.�������������ͬʱע���֦������ʣ��������ű�ʣ��������Ŷ��ʱ����м�֦��
void dfstraceback(int left, int right,string curstring, vector<string>&res)
{
	if (left > right)return;//ʣ�������Ŷ��ʱ��ע��������ļ�֦��
	else
	{
		if (left==0&&right==0)//�����ź������Ŷ�ʹ�����ʱ�򣬱��浽���������
			res.push_back(curstring);
		if (left>0)//
			dfstraceback(left - 1, right, curstring + '(', res);//��֦�ݹ顣
		if (right>0)
			dfstraceback(left, right - 1, curstring + ')', res);//��֦�ݹ顣
	}

}
vector<string> generateParenthesis(int n) {
	vector<string> res;
	int leftremain = n;//��ʣ�����������δʹ��
	int rightremain = n;//��ʣ�����������δʹ��
	string curstring = "";
	dfstraceback(n, n, curstring,res);
	return res;
}