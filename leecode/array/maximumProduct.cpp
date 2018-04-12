/*
Maximum Product of Three Numbers
Given an integer array, find three numbers whose product is maximum and output the maximum product.
Example 1:
Input: [1,2,3]
Output: 6
Example 2:
Input: [1,2,3,4]
Output: 24
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//自己写的，思想完全错误！！！！！
int MaxmumProduct(vector<int>& nums)
{
	int n = nums.size();
	int max = nums[0] * nums[1] * nums[2];
	if (n == 3)return max;
	for (int i = 3; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (nums[i] * nums[(j + 1) % 3] * nums[(j + 2) % 3]>max)
			{
				int temp = nums[j];
				nums[j] = nums[i];
				nums[i] = temp;
				max = nums[0] * nums[1] * nums[2];
			}
		}
	}
	return nums[0] * nums[1] * nums[2];
}
//参考标准答案。
//方法一：先排序
int MaximumProduct1(vector<int>& nums)
{
	sort(nums.begin(),nums.end());
	return max(nums[0] * nums[1] * nums[nums.size() - 1], nums[nums.size() - 3] * nums[nums.size() - 2] * nums[nums.size() - 1]);
}
//方法二：找到数组中的两个最小的和3个最大的元素
int MaximumProduct2(vector<int>& nums)
{
	int min1 = INT_MAX, min2 = INT_MAX;
	int max1 = INT_MIN, max2 = INT_MIN,max3 = INT_MIN;
	for (int n : nums)
	{
		if (n < min1)
		{
			min2 = min1;
			min1 = n;
		}
		else if (n < min2)
		{
			min2 = n;
		}
		if (n>max1)
		{
			max3 = max2;
			max2 = max1;
			max1 = n;
		}
		else if (n>max2)
		{
			max3 = max2;
			max2 = n;
		}
		else if (n>max3)
		{
			max3 = n;
		}
	}
	return max(min1*min2*max1, max1*max2*max3);
}
/*
void main()
{
	vector<int> vec;
	vec.push_back(-1);
	vec.push_back(-2);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	cout << MaximumProduct1(vec)<<endl;
	cout << MaximumProduct2(vec)<<endl;
}
*/