/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
//暴力的方法 时间复杂度O(n^2)
vector<int> twoSum1(vector<int>& nums, int target) {
	int n = nums.size();
	vector <int> result;
	//sort(nums.begin(),nums.end());
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (target == nums[i] + nums[j])
			{
				result.push_back(i);
				result.push_back(j);
				return result;
			}
		}
	}
}
//利用哈希表求解 首先哈希表要初始化
vector<int> twoSum2(vector<int> nums, int target)
{
	int n = nums.size();
	map<int, int> hashmap;
	vector <int> result;
	for (int i = 0; i < n; i++)
	{
		hashmap[nums[i]] = i;
	}
	for (int i = 0; i < n; i++)
	{
		int complement = target - nums[i];
		if (hashmap.find(complement) != hashmap.end() && hashmap[complement] != i)
		{
			result.push_back(i);
			result.push_back(hashmap[complement]);
			return result;
		}
	}
}
//利用哈希表求解 哈希表一边初始化 一边寻找
vector<int> twoSum3(vector<int> nums, int target)
{
	int n = nums.size();
	map<int, int> hashmap;
	vector <int> result;
	
	for (int i = 0; i < n; i++)
	{
		int complement = target - nums[i];
		if (hashmap.find(complement) != hashmap.end())
		{
			result.push_back(i);
			result.push_back(hashmap[complement]);
			return result;
		}
		hashmap[nums[i]] = i;
	}
}
/*
void main()
{
	vector <int> nums;
	vector <int> result;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(4);
	//nums.push_back(5);
	result=twoSum2(nums, 6);
	vector <int>::iterator it;
	for (it = result.begin(); it != result.end(); it++)
	{
		cout <<*it<< endl;
	}
	
}
*/