/*
Given an array consisting of n integers,
find the contiguous subarray of given length k that has the maximum average value.
And you need to output the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
Note:
1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].
*/
#include<iostream>
#include<vector>
using namespace std;
//方法一：暴力方法
double MaxAverageSubarray1(vector<int>& nums, int k)
{
	int max = 0;
	int current;
	for (int i = 0; i < k; i++)
		max = max + nums[i];

		for (int i = 1; i <=nums.size()- k; i++)
	{
		current = 0;
		for (int j = 0; j < k; j++)
		{
			current = current + nums[i+j];

		}
		if (current>max)max = current;

	}
	return max*1.0 / k;
}
//解法二：先计算出累积和，然后再求子数组和。可以降低时间复杂度。
double MaxAverageSubarray2(vector<int> & nums, int k)
{
	int size = nums.size();
	int *sum = new int[size];
	sum[0] = nums[0];
	for (int i = 1; i < size; i++)
	{
		sum[i] = sum[i - 1] + nums[i];
	}
	int res = sum[k - 1];
	for (int i = k; i < size; i++)
	{
		if (sum[i] - sum[i - k ]>res)
			res = sum[i] - sum[i - k ];
	}
	delete[] sum;
	return res*1.0 / k;
}
//解法三：利用滑动窗口的办法求解。
double MaxAverageSubarray3(vector<int> &nums, int k)
{
	int size = nums.size();
	int sum = 0;
	int res = 0;
	for (int i = 0; i < k; i++)
	{
		sum = sum + nums[i];
	}
	res = sum;
	for (int i = k; i < size; i++)
	{
		sum = sum + nums[i] - nums[i - k];
		if (sum>res)
			res = sum;
	}
	return res*1.0 / k;
	
}
void main()
{
	vector <int> vec;
	vec.push_back(-1);
	vec.push_back(12); 
	vec.push_back(-5);
	vec.push_back(-6);
	vec.push_back(50);
	vec.push_back(3);
	cout << MaxAverageSubarray3(vec,4);
}