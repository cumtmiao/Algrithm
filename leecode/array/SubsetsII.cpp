/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
[2],
[1],
[1,2,2],
[2,2],
[1,2],
[]
]
*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res;
	vector<int> temp;
	sort(nums.begin(), nums.end());
	int n = nums.size();
	res.push_back(temp);
	if (n == 0) return res;
	for (int i = 0; i < n; i++)
	{
		int ns = res.size();
		for (int j = 0; j < ns; j++)
		{
			res.push_back(res[j]);
			res.back().push_back(nums[i]);		
		}
	}
	set<vector<int>> setofres;
	for(int i=0;i<res.size();i++)
	{
		setofres.insert(res[i]);
	}
	return vector<vector<int>>(setofres.begin(),setofres.end());
}