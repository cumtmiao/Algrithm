/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, 
with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
*/
#include<iostream>
#include<vector>
using namespace std;
//解法一：官网标准答案。
//直接维护两个指针，j比i大，如果j指向的是重复字符，直接跳过，否则，赋值给i+1；
int removeDuplicates(vector<int>& nums)
{
	int n=nums.size();
	if (n == 0)return 0;
	int i = 0;
	for (int j = 1; j < n; j++)
	{
		if (nums[j] != nums[i])
		{
			i++;
			nums[i] = nums[j];
		}
	}
	return i + 1;
}
//解法二：
int removeDuplicates2(vector<int>& nums)
{
	int n = nums.size();
	int i,count = 0;//count表示副本数
	for (i = 1; i < n; i++)
	{
		if (nums[i] == nums[i - 1])
			count++;
		else nums[i - count] = nums[i];
	}
	return n - count;
}
void main()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(2);
	cout << removeDuplicates2(vec);
}