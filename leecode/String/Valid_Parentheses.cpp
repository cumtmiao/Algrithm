/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
#include<iostream>
#include<stack>
using namespace std;
//考察栈的基本操作。进栈：push(x);出栈：pop()(不返回该元素，而只是删除该元素);访问栈顶元素：top();size():栈中元素的个数。
bool isValid(string s) {
	int n = s.size();
	if (n == 0)return true;
	stack<char> res;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
			res.push(')');
		else if (s[i] == '[')
			res.push(']');
		else if (s[i] == '{')
			res.push('}');
		else if (res.empty()||res.top() != s[i])
			return false;
		else
			res.pop();
	}
	if (res.empty())
		return true;
	else
		return false;
}