/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
#include<iostream>
#include<stack>
using namespace std;
//����ջ�Ļ�����������ջ��push(x);��ջ��pop()(�����ظ�Ԫ�أ���ֻ��ɾ����Ԫ��);����ջ��Ԫ�أ�top();size():ջ��Ԫ�صĸ�����
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