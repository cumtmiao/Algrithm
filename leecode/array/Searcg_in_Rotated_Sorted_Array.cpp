/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/
#include<iostream>
#include<vector>
using namespace std;
//直接遍历看元素是否存在数组中，时间复杂度为O(n)
int search1(vector<int>& nums, int target) {
	int n = nums.size();
	for (int i = 0; i < n; i++)
	{
		if (nums[i]==target)
			return i;
	}
	return -1;
}
//用二分法来寻找target,时间复杂度为O(logn) 但是测试性能并不高
int search2(vector<int>&nums, int target)
{
	int n = nums.size();
	int l = 0;;
	int r = n - 1;
	if (n < 1 )return -1;
	if ((n == 1) && nums[0] != target)return -1;
	if (n == 1 && nums[0] == target)return 0;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (nums[mid] == target)
			return mid;
		if (nums[mid]<nums[r])
		{
			if (target>nums[mid] && target <= nums[r])l = mid + 1;
			else r = mid - 1;
		}
		else
		{
			if (target>=nums[l] && target < nums[mid])r = mid-1;
			else l = mid + 1;
		}	
	}
	if (nums[l] == target)return l;
	return -1;
}
/*
void main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	cout << search2(nums, 3);
}
*/