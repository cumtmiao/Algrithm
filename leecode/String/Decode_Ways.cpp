/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
这个题目是典型的动态规划问题，注意一些细节和具体的求解方式。
*/
//动态规划 numbers[i] 存储 0...i-1的方法数，如果s[i-1]!=0,s[i-1]可自己单独作为一个元素，或者在s[i-2]满足一定
//条件时，与s[i-2]共同组成一个元素；如果s[i-1]==0，它只能在s[i-2]满足一定条件时，与s[i-2]构成一个元素，否则不能解码。
int numDecodings(string s) {
	if (s.empty() || (s[0] == '0')) return 0;
	if (s.size() == 1)return 1;
	vector<int> numbers(s.size()+1,0);
	numbers[0] = 1,numbers[1]=1;
	for (int i = 2; i < numbers.size(); i++)
	{
		if (s[i-1] != '0')
			numbers[i] = numbers[i - 1];
		if (s[i - 2] == '1' || (s[i - 2] == '2'&&s[i-1] <= '6'))
		{
			numbers[i] += numbers[i - 2];
		}
	}
	return numbers[s.size()];
}
/*
void main()
{
	string s = "26";
	cout << numDecodings(s);
}
*/