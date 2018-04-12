/*
Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/
#include<iostream>
#include<vector>
using namespace std;
//暴力方法  直接找该位置。
int searchInsert(vector<int>& nums, int target) {
	int n = nums.size();
	for (int i = 0; i < n; i++)
	{
		if (target <= nums[i])
			return i;
	}
	return n;
}
//二分法 时间复杂度为o(logn)
int searchInsert2(vector<int>&nums, int target)
{
	int n = nums.size();
	if (n == 1 && target <= nums[0])return 0;
	if (n == 1 && target > nums[0])return 1;
	int lo = 0, hi = n - 1;
	while (lo < hi)
	{
		int mid = (lo + hi) >> 1;
		if (target > nums[mid])
			lo = mid + 1;
		if (target == nums[mid])
			return mid;
		if (target < nums[mid])
			hi = mid;
	}
	if (lo == n - 1&&target>nums[n-1])return n;
	return lo;
}
/*
void main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	cout << searchInsert2(nums, 0);
}
*/