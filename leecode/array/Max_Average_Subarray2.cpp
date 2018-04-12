/*
Given an array consisting of n integers, find the contiguous subarray whose length
is greater than or equal to k that has the maximum average value. 
And you need to output the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation:
when length is 5, maximum average value is 10.8,
when length is 6, maximum average value is 9.16667.
Thus return 12.75.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//暴力方法。时间超时
double findMaxAverage(vector<int>& nums, int k) {
	int n = nums.size();
	int i, j,m,sum=0;
	int res = 0;
	vector<double> ave;
	for (i = k; i <= n; i++)
	{
		sum = 0, res = 0;
		for (m = 0; m < i; m++)
			sum = sum + nums[m];
		res = sum;
		if (n == 1||n==k)ave.push_back(res*1.0 / i);
		for (j = i; j < n; j++)
		{
			sum = sum+nums[j]-nums[j-i];
			res = max(sum, res);
			ave.push_back(res*1.0/i);
			
		}
	}
	vector<double>::iterator it;
	it = ave.begin();
	double max_ave=*it;
	for (it = ave.begin(); it != ave.end(); it++)
		max_ave = max(max_ave, *it);
	return max_ave;
}
//时间复杂度为O(n^2)的一个解法。时间超时
double findMaxAverage1(vector<int>& nums, int k)
{
	int n = nums.size();
	double res =(double)INT_MIN;
	for (int i = 0; i < n + 1 - k; i++)
	{
		long sum = 0;
		for (int j = i; j < n; j++)
		{
			sum = sum + nums[j];
			if (j + 1 - i>=k)
				res = max(res, sum*1.0 /(j + 1 - i));
		}
	}
	return res;
}
//利用二分法来做。提交通过，时间109ms
//islarger函数的作用是看是否存在长度大于等于k的子数组，它的平均值>mid。
//如果存在，则返回true，否则，返回false。
//数组nums[0...n-1],如果存在一个长度为j(k<=j<n)的子数组，它的平均值>mid；
//则不妨设(nums[0]+nums[1]+...+nums[j-1])/j>mid;
//即：（nums[0]-mid）+（nums[1]-mid）+...+（nums[j-1]-mid）>0
//sum存储当前指针以及之前的数组累积和；prev存储索引比sum小k的数组累积和
bool islarger(vector<int>& nums, double mid, int k)
{
	double sum = 0, prev = 0, min_sum = 0;
	for (int i = 0; i < k; i++)
	{
		sum = sum + nums[i] - mid;
	}
	if (sum>0)
		return true;
	for (int i = k; i < nums.size(); i++)
	{
		sum += nums[i] - mid;
		prev += nums[i - k] - mid;
		//找0到i-k之间（累积和-mid)最小的值，这里体现了长度大于等于k的子数组！！！
		min_sum = min(prev, min_sum);
		if (sum>min_sum)
			return true;
	}
	return false;
}
double findMaxAverage2(vector<int>& nums, int k)
{
	double left = INT_MAX, right = INT_MIN;
	for (int num : nums)
	{
		right = max(right,double(num));
		left = min(left, double(num));
	}
	while (right - left > 0.00001)
	{
		double mid = (right + left) / 2;
		if (islarger(nums, mid, k))
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	return left;
}

void main()
{
	vector <int> vec;
	/*vec.push_back(-1);
	vec.push_back(12);
	vec.push_back(-5);
	vec.push_back(-6);
	vec.push_back(50);
	vec.push_back(3);
	*/
	vec.push_back(6);
	vec.push_back(2);
	vec.push_back(4);
	vec.push_back(0);
	vec.push_back(4);

	vec.push_back(2);
	vec.push_back(2);
	vec.push_back(0);
	vec.push_back(2);
	vec.push_back(1);
	cout << findMaxAverage(vec, 9)<<endl;
	cout << findMaxAverage1(vec, 9)<<endl;
	cout << findMaxAverage2(vec, 9) << endl;

}