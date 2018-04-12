/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container and n is at least 2.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//暴力方法  时间复杂度为O(n^2) 时间超时
int maxArea1(vector<int>& height) {
	int n = height.size();
	int maxarea = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			maxarea = max(maxarea,min(height[i],height[j])*(j-i));
		}
	}
	return maxarea;
}
//时间复杂度为O(n)
int maxArea2(vector<int>height)
{
	int n = height.size();
	int l = 0;
	int r = n - 1;
	int maxarea = 0;
	while (l < r)
	{
		maxarea = max(maxarea, min(height[l], height[r])*(r - l));
		if (height[l] < height[r])
			l++;
		else r--;
	}
	return maxarea;
}