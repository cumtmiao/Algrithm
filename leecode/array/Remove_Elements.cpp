/*
Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.
*/
#include<iostream>
#include<vector>
using namespace std;
//ͨ�����ԣ��Ȱѵ���val��ֵ���������ĩβ���ټ���
int removeElement(vector<int>& nums, int val) {
	int n = nums.size();
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		if (nums[left] != val)left++;
		else if (nums[right] == val)right--;
		else if (nums[left] == val&&nums[right] != val)
		{
			int temp = nums[left];
			nums[left] = nums[right];
			nums[right] =temp;
		}
	}
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		if (nums[i] != val)
			num++;
		else break;
	}
	return num;
}
//�ο� ֱ�������������д��ڵ�Ԫ�ظ���ԭ�����е�Ԫ�ؼ���
int removeElement1(vector<int>nums, int val)
{
	int num = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != val)
		{
			nums[num] = nums[i];
			num++;
		}
	}
	return num;
}