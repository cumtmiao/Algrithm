/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
[-1,  0, 0, 1],
[-2, -1, 1, 2],
[-2,  0, 0, 2]
]
*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
//四数之和是三个数之和的拓展
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	int n = nums.size();
	set<vector<int>> res;//利用Set集合能够避免重复的dumple输出
	sort(nums.begin(), nums.end());
	for (int i = 0; i < n - 3; i++)
	{
		for (int j = i + 1; j < n - 2; j++)
		{
			int lo = j + 1;
			int hi = n - 1;
			
			while (lo < hi)
			{
				int sum = nums[i] + nums[j] + nums[lo] + nums[hi];
				if ( sum== target)
				{
					vector<int> dumple;
					dumple.push_back(nums[i]);
					dumple.push_back(nums[j]);
					dumple.push_back(nums[lo]);
					dumple.push_back(nums[hi]);
					res.insert(dumple);
					while (lo < hi&&nums[lo] == nums[lo + 1])lo++;
					while (lo < hi&&nums[hi] == nums[hi - 1])hi--;
					lo++;
					hi--;
				}
				else if (sum < target)
					lo++;
				else
					hi--;
			}
		}
	}
	return vector<vector<int>>(res.begin(),res.end());
}