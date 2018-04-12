/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.
最大跳跃nums[i]步	

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//编译不通过 ，待修改。
bool canjump(vector<int>& nums) {
	int n = nums.size();
	if (n == 1)return true;
	int i = 0;
	int max1 = 0;
	while (max1 < n)
	{
	
		for (int j = i; j <= i + nums[i]; j++)
		{
			max1 = max(max1, j + nums[j]);
			
		}
		//if (max1>=i+nums[i])
			i = max1;
			if (i >= n - 1)return true;
		if (nums[max1] == 0&&max1!=n-1) return false;
		//i += nums[i];
	}
	return true;
}	
//使用迭代的方法
bool canJumpFromPosition(int position, vector<int>& nums)
{
	int n = nums.size();
	if (position == n-1)
		return true;
	int furestjump = min(position + nums[position],n-1);
	for (int i = position+1; i <= furestjump; i++)
	{
		if (canJumpFromPosition(i, nums))
			return true;
	}
	return false;
}
bool canjump1(vector<int>& nums)
{
	return canJumpFromPosition(0, nums);
}
/*
void main()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(0);
	vec.push_back(0);
	vec.push_back(4);
	cout << canjump1(vec);
}
*/