/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/
#include<iostream>
#include<string>
using namespace std;
//思路：两个指针分别从前，从后往中间扫，对应元素交换
string reverseString(string s) {
	int n = s.size();
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		char temp = s[left];
		s[left] = s[right];
		s[right] = temp;
		left++;
		right--;
	}
	return s;
}