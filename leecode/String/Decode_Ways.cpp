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
�����Ŀ�ǵ��͵Ķ�̬�滮���⣬ע��һЩϸ�ں;������ⷽʽ��
*/
//��̬�滮 numbers[i] �洢 0...i-1�ķ����������s[i-1]!=0,s[i-1]���Լ�������Ϊһ��Ԫ�أ�������s[i-2]����һ��
//����ʱ����s[i-2]��ͬ���һ��Ԫ�أ����s[i-1]==0����ֻ����s[i-2]����һ������ʱ����s[i-2]����һ��Ԫ�أ������ܽ��롣
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