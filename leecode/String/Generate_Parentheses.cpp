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
//递归法.深度优先搜索（同时注意剪枝，即当剩余的左括号比剩余的右括号多的时候进行剪枝）
void dfstraceback(int left, int right,string curstring, vector<string>&res)
{
	if (left > right)return;//剩余左括号多的时候注意进行树的剪枝。
	else
	{
		if (left==0&&right==0)//左括号和右括号都使用完的时候，保存到结果向量。
			res.push_back(curstring);
		if (left>0)//
			dfstraceback(left - 1, right, curstring + '(', res);//左枝递归。
		if (right>0)
			dfstraceback(left, right - 1, curstring + ')', res);//右枝递归。
	}

}
vector<string> generateParenthesis(int n) {
	vector<string> res;
	int leftremain = n;//还剩余多少左括号未使用
	int rightremain = n;//还剩余多少右括号未使用
	string curstring = "";
	dfstraceback(n, n, curstring,res);
	return res;
}