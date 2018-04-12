/*
Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are:
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Note:
The length of the given array won't exceed 1000.
The integers in the given array are in the range of [0, 1000].
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//暴力解法。时间复杂度为O(n^3)
int triangleNumber(vector<int>& nums) {
	int n = nums.size();
	if (n < 3)return 0;
	int num = 0;
	for (int i = 0; i < n-2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n;k++)
			if (nums[i] + nums[j]>nums[k]
				&& nums[i] + nums[k]>nums[j]
				&& nums[j] + nums[k]>nums[i])
				num++;
		}
	}
	return num;
}
//Linear Scan   时间复杂度为O(n^2)
int triangleNumber1(vector<int>& nums) {
	int n = nums.size();
	if (n < 3)return 0;
	int num = 0;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < n - 2; i++)
	{
		int k = i + 2;
		for (int j = i + 1; j < n - 1&&nums[i]>0; j++)
		{ 
			while (k<n&&nums[i] + nums[j]>nums[k])
				k++;
			num = num + k - j - 1;
		}
	}
	return num;
}
/*
void main()
{
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(1);
	cout << triangleNumber1(nums);
}
*/