/*
The count-and-say sequence is the sequence of integers with the first five terms as following:
1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.
Note: Each term of the sequence of integers will be represented as a string.
Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"
*/
#include<iostream>
#include<string>
using namespace std;
//使用迭代的方法。
string countAndSayforOneString(string res)//countandsay一个字符串
{
	char temp = res[0];
	string resp = "";
	int num = 0;
	for (int i = 0; i < res.size(); i++)
	{
		if (temp == res[i])
		{
			num++;
			continue;
		}
		else
		{
			resp = resp + to_string(num) + temp;
			temp = res[i];
			num = 1;
		}	
	}
	resp = resp + to_string(num) + temp;
	return resp;

}
string countAndSay(int n) {
	if (n == 0)return "";
	string res="1";
	for (int i = 1; i < n; i++)//从第一个字符串不断迭代到第n个字符串。
	{
		res = countAndSayforOneString(res);
	}
	return res;
}
/*
void main()
{
	cout << countAndSay(4);
}
*/