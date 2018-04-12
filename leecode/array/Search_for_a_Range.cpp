/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
#include<iostream>
#include<vector>
using namespace std;
//自己写的二分法。。
vector<int> searchRange(vector<int>& nums, int target) {
	int n = nums.size();
	vector <int> res;
	if (n == 1 && nums[0] == target)
	{
		res.push_back(0);
		res.push_back(0);
		return res;
	}
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		int mid = (left + right) >> 1;
		if (target>nums[mid])
		{
			left = mid + 1;
		}
		else if (target < nums[mid])
		{
			right = mid;
		}
		else if (target == nums[mid])
		{
			int i,j;
			while (mid>0 && nums[mid] == nums[mid - 1])mid--;
			i = mid;
			while (mid<n-1 && nums[mid] == nums[mid + 1])mid++;
			j = mid;
			res.push_back(i);
			res.push_back(j);
			return res;
		}
	}
	if (left == right&&target == nums[left])
	{
		res.push_back(left);
		res.push_back(left);
		return res;
	}
	if (res.size() == 0)
	{
		res.push_back(-1);
		res.push_back(-1);
		return res;
	}
}
/*
void main()
{
	vector<int> nums;
	vector<int> res;
	nums.push_back(1);
	nums.push_back(4);
	res=searchRange(nums, 4);
	for (int i = 0; i < res.size();i++)
		cout << res[i] << ' ';
}
*/