/*
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.
给存在数组中的数加一，个位数存在最后。
*/
#include<iostream>
#include<vector>
using namespace std;
//自己写的  有点别扭。
vector<int> plusOne(vector<int>& digits) {
	int n = digits.size();
	int carry = 1;
	int i = n - 1;
	vector<int>res;
	if (digits[n - 1] < 9)
	{
		digits[n - 1] += 1;
		return digits;
	}
	for (; i >= 0; i--)
	{
		if (digits[i]+carry <= 9)
		{
			digits[i] = digits[i]+ carry;
			return digits;
		}
		else
		{
			digits[i] = 0;
		}
	}
	if (i<0)
	{
		res.push_back(1);
		for (int i = 1; i <= n; i++)
			res.push_back(0);
		return res;
	}

}
//参考标准代码   简洁明了
vector<int> plusOne1(vector<int>& digits) {
	int n = digits.size();
	for (int i = n - 1; i >= 0; i--)
	{
		if (digits[i] == 9)
			digits[i] = 0;
		else
		{
			digits[i]++;
			return digits;
		}

	}
	digits[0] = 1;
		digits.push_back(0);
		return digits;
}
/*
void main()
{
	vector <int> nums;
	nums.push_back(9);
	plusOne1(nums);
}
*/