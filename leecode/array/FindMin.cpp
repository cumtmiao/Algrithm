/*
Find Minimum in Rotated Sorted Array
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
You may assume no duplicate exists in the array.
*/
#include<iostream>
#include<vector>
using namespace std;
//时间复杂度为O(n),如果后一个比前一个小，则后一个就是我们要找的元素
int FindMin(vector<int>& nums)
{
	if (nums.size() == 1)return nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] < nums[i-1])
			return nums[i];
	}
	return nums[0];
}
//二分法，时间复杂度为O(lgn)
int FindMin2(vector<int> nums)
{
	int lo = 0, hi = nums.size() - 1;
	while (lo < hi)
	{
		int mid = (lo + hi) / 2;
		if (nums[mid]>nums[hi])lo = mid + 1;
		else hi = mid;
	}
	return nums[lo];
}
/*void main()
{
	vector<int> vec;
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	cout << FindMin(vec);

}
*/