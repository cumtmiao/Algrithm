/*
Given an array of n positive integers and a positive integer s, 
find the minimal length of a contiguous subarray of which the sum �� s.
If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//��������  ��ʱ ʱ�临�Ӷ� O(n^3)
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
//���������Ľ��棬���ò��ֺ����� ʱ�临�Ӷ�O(n^2)
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
//���ö��ֲ��� ʱ�临�Ӷ�O(nlgn)
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
		auto bound = lower_bound(sum.begin(), sum.end(), to_find);//����c++ STL�Դ��ĺ�������һ�������б��в�С��to_find��interator��ʱ�临�Ӷ�ΪO(logn)
		if (bound != sum.end())
		{
			res=min(res,static_cast<int>(bound - (sum.begin() + i - 1)));
		}
	}
	return res == INT_MAX ? 0 : res;
}
//�����������ڵ�˼�룬ʱ�临�Ӷȿ��Խ���ΪO(n)
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