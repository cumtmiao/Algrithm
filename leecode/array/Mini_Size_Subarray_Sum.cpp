/*
Given an array of n positive integers and a positive integer s, 
find the minimal length of a contiguous subarray of which the sum ≥ s.
If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//暴力方法  超时 时间复杂度 O(n^3)
int minSubArrayLen1(int s, vector<int>& nums) {
	int size = nums.size();
	if (size == 0)return 0;
	int res = INT_MAX;
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			int sum = 0;
			for (int k = i; i <= j; k++)
			{
				sum = sum + nums[k];				
			}
			if (sum >= s)
			{
				res = min(res,j+1-i);
				break;
			}
		}
	}
	return res == INT_MAX ? 0 : res;
}
//暴力方法改进版，利用部分和数组 时间复杂度O(n^2)
int minSubArrayLen2(int s, vector<int>& nums) {
	int size = nums.size();
	if (size == 0)return 0;
	int res = INT_MAX;
	vector<int> sum(size);
	sum[0] = nums[0];
	for (int i = 1; i < size; i++)
	{
		sum[i] = sum[i - 1] + nums[i];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			int sum1=sum[j] - sum[i] + nums[i];
			if (sum1 >= s)
			{
				res = min(res, j - i + 1);
				break;
			}
		}
	}
	return res == INT_MAX ? 0 : res;
}
//利用二分查找 时间复杂度O(nlgn)
int minSubArrayLen3(int s, vector<int>& nums) {
	int size = nums.size();
	if (size == 0)return 0;
	int res = INT_MAX;
	vector<int> sum(size+1);
	sum[0] = 0;
	for (int i = 1; i <= size; i++)
	{
		sum[i] = sum[i - 1] + nums[i-1];
	}

	for (int i = 1; i <=size; i++)
	{
	   
		int to_find = s + sum[i - 1];
		auto bound = lower_bound(sum.begin(), sum.end(), to_find);//利用c++ STL自带的函数返回一个有序列表中不小于to_find的interator。时间复杂度为O(logn)
		if (bound != sum.end())
		{
			res=min(res,static_cast<int>(bound - (sum.begin() + i - 1)));
		}
	}
	return res == INT_MAX ? 0 : res;
}
//借助滑动窗口的思想，时间复杂度可以降低为O(n)
int minSubArrayLen4(int s, vector<int>& nums) {
	int size = nums.size();
	if (size == 0)return 0;
	int res = INT_MAX;
	int sum = 0;
	int left = 0;
	for (int i = 0; i < size; i++)
	{
		sum = sum + nums[i];
		while (sum >= s)
		{
			res = min(res, i - left + 1);
			sum = sum - nums[left];
			left++;
		}
	}
	return res == INT_MAX ? 0 : res;
}