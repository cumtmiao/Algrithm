/*
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
The array may contain duplicates.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//遍历一遍找最小元素
int FindMin3(vector<int>& nums)
{
	int current = nums[0];
	if (nums.size() == 1)return current;
	for (int i = 1; i < nums.size(); i++)
	{
		current = min(current, nums[i]);
	}
	return current;
}