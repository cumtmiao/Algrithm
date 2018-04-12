/*
复习必看！！！
Given a set of candidate numbers (C) (without duplicates) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:
[
[7],
[2, 2, 3]
]
*/
#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
void traceback(vector<int>& nums, int from, int target, set<vector<int>>&res, vector<int>& tuple)
{
	
	if (target == 0)
	{
		res.insert(tuple);
		return;
	}
	if (target < 0)
		return;
	else
	{
		for (int i = from; i < nums.size()&&nums[i]<=target; i++)
		{			
			tuple.push_back(nums[i]);
			traceback(nums, i, target - nums[i],res,tuple);
			tuple.pop_back();
		}
	}
}

//回溯法,注意回溯法具体是怎么实现的! 经典！！！
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	set<vector<int>>res;
	vector<int> tuple;
	traceback(candidates, 0, target, res, tuple);
	return vector<vector<int>> (res.begin(), res.end());
		
}