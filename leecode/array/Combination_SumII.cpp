/*
Given a collection of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
A solution set is:
[
[1, 7],
[1, 2, 5],
[2, 6],
[1, 1, 6]
]
*/
#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
//与combination_sum的唯一区别在于traceback 是从下一个位置开始的
void  traceback(vector<int>&nums,int from,int target,set<vector<int>>&res,vector<int>tuple)
{
	if (target == 0)
	{
		res.insert(tuple);
		return;
	}
	if (target < 0)
		return;
	for (int i = from; i < nums.size()&&nums[i]<=target; i++)
	{
		if (i&&nums[i] == nums[i - 1] && i>from) continue;//排出不必要的迭代过程，提高效率	
		tuple.push_back(nums[i]);
		traceback(nums, i + 1, target - nums[i], res, tuple);
		tuple.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	set<vector<int>> res;
	vector<int> tuple;
	sort(candidates.begin(), candidates.end());
	traceback(candidates, 0, target, res, tuple);
	return vector<vector<int>>(res.begin(), res.end());
}