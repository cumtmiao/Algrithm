/*
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//典型的递归问题。
void traceback(vector<int>&nums,int deep, vector<int>& temp, vector<vector<int>> &res)
{
	res.push_back(temp);
	for (int i = deep; i < nums.size(); i++)
	{
		temp.push_back(nums[i]);
		traceback(nums, i + 1, temp, res);
		temp.pop_back();
	}

}
vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> res;
	vector<int> temp;
	sort(nums.begin(), nums.end());
	traceback(nums, 0, temp, res);
	return res;
}

//方法二：迭代
/*Initially: [[]]
Adding the first number to all the existed subsets : [[], [1]];
Adding the second number to all the existed subsets : [[], [1], [2], [1, 2]];
Adding the third number to all the existed subsets : [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]].
*/
vector<vector<int>> subsets2(vector<int>& nums) {
	vector<vector<int>> res;
	vector<int> temp;
	res.push_back(temp);
	sort(nums.begin(), nums.end());
	int n = nums.size();
	if (n == 0)return res;
	for (int i = 0; i < n; i++)
	{
		int sizeofres = res.size();
		for (int j = 0; j < sizeofres; j++)
		{
			res.push_back(res[j]);//将res中第j个元素放到集合的末尾
			res.back().push_back(nums[i]);//在该元素末尾添加即将加入vector的元素nums[i]
		}
	}
	return res;
}