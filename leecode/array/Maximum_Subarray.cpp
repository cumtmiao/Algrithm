/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//看nums[i]前面的连续和是否会参政正面影响：
//如果是产生正面影响则maxsum = maxsum + nums[i];否则maxsum = nums[i];
//用res来记录最大的maxsum的值
int maxSubArray(vector<int>& nums) {
	int n = nums.size();
	int maxsum = nums[0];
	int res = nums[0];
	for (int i = 1; i < n; i++)
	{
		if (maxsum>=0)maxsum = maxsum + nums[i];
		else maxsum = nums[i];
		res = max(res, maxsum);
	}
	return res;
}