/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
[-1, 0, 1],
[-1, -1, 2]
]
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//基本思想是：
//1）先排序
//2）固定一个数nums[i]，然后在i的右侧计算两个数的和满足-nums[i]
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> res;
	if (nums.size() < 3)return res;
	sort(nums.begin(), nums.end());//先排序
	for (int i = 0; i < nums.size() - 2; i++)//i遍历范围是：0~n-3
	{
		if (i>0 && nums[i] == nums[i - 1])continue;
		int lo = i + 1, hi = nums.size() - 1;
		while (lo < hi)//计算两数之和是否与-nums[i]相等
		{
			if (nums[lo] + nums[hi] + nums[i] == 0)
			{
				vector<int> triple;
				triple.push_back(nums[i]);
				triple.push_back(nums[lo]);
				triple.push_back(nums[hi]);
				res.push_back(triple);
				while (lo < hi&&nums[lo] == nums[lo + 1])lo++;
				while (lo < hi&&nums[hi] == nums[hi - 1])hi--;
				lo++;
				hi--;
			}
			else if (nums[lo] + nums[hi] + nums[i] < 0)lo++;
			else hi--;
		}
	}
	return res;
}